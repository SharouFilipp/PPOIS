import json
import os
from typing import List, Dict
from transitions import Machine
from student import Student
from teacher import Teacher
from classroom import Classroom
from marks import Marks
from educational_material import EducationalMaterial
from educational_plan import EducationalPlan
from lesson import Lesson


class EducationProcess:
    states = ["администрирование", "работа с материалами", "проведение занятий", "оценивание студентов", "консультирование"]

    def __init__(self) -> None:
        self.teachers: List[Teacher] = []
        self.students: List[Student] = []
        self.classrooms: List[Classroom] = []
        self.educational_plans: List[EducationalPlan] = []
        self.materials: List[EducationalMaterial] = []
        self.lessons: List[Lesson] = []
        self.student_marks: Dict[Student, List[Marks]] = {}

        self.machine = Machine(model=self, states=self.states, initial="администрирование")

        self.machine.add_transition("to_materials", "администрирование", "работа с материалами")
        self.machine.add_transition("to_lessons", "работа с материалами", "проведение занятий", conditions=["is_ready_for_lesson"])
        self.machine.add_transition("to_evaluation", "проведение занятий", "оценивание студентов")
        self.machine.add_transition("to_consulting", "оценивание студентов", "консультирование")
        self.machine.add_transition("to_admin", "*", "администрирование")

    def is_ready_for_lesson(self) -> bool:
        return (len(self.educational_plans) > 0 and len(self.classrooms) > 0 and 
                len(self.teachers) > 0 and len(self.students) > 0 and len(self.materials) > 0)

    def ensure_admin_state(self) -> None:
        if self.state != "администрирование":
            if not self.to_admin():
                raise ValueError("Не удалось вернуться в состояние 'администрирование'.")

    def ensure_materials_state(self) -> None:
        if self.state != "работа с материалами":
            if not self.to_materials():
                raise ValueError("Нельзя работать с материалами: требуется состояние 'администрирование'.")

    def ensure_lesson_state(self) -> None:
        if self.state != "проведение занятий":
            if not self.to_lessons():
                raise ValueError("Нельзя начать занятие: система не готова (требуются преподаватели, студенты, материалы и т.д.)")

    def ensure_evaluation_state(self) -> None:
        if self.state != "оценивание студентов":
            if not self.to_evaluation():
                raise ValueError("Нельзя оценить студентов: требуется состояние 'проведение занятий'.")

    def ensure_consulting_state(self) -> None:
        if self.state != "консультирование":
            if not self.to_consulting():
                raise ValueError("Нельзя консультировать: требуется состояние 'оценивание студентов'.")

    def add_teacher(self, name: str, email: str) -> None:
        self.ensure_admin_state()
        teacher = Teacher(name, email)
        self.teachers.append(teacher)

    def add_student(self, name: str, group: str) -> None:
        self.ensure_admin_state()
        student = Student(name, group)
        self.students.append(student)

    def add_classroom(self, number: str, capacity: int) -> None:
        self.ensure_admin_state()
        classroom = Classroom(number, capacity)
        self.classrooms.append(classroom)

    def add_plan(self, name: str) -> None:
        self.ensure_admin_state()
        plan = EducationalPlan(name)
        self.educational_plans.append(plan)

    def add_material(self, name: str, author: str, material_name: str) -> None:
        self.ensure_materials_state()
        material = EducationalMaterial(name)
        material.add_material(author, material_name)
        self.materials.append(material)

    def start_lesson(self, teacher: Teacher, subject: str, classroom: Classroom, start_time: str, end_time: str) -> None:
        self.ensure_lesson_state()
        lesson = Lesson(teacher, subject, classroom, start_time, end_time)
        self.lessons.append(lesson)
        lesson.conduct_lesson()

    
    def evaluate_student(self, lesson: Lesson, student: Student, mark: int) -> None:
        self.ensure_evaluation_state()
        if student not in self.student_marks:
            self.student_marks[student] = []
        grade = Marks(mark, lesson)
        self.student_marks[student].append(grade)


    def consult_student(self, student: Student, message: str) -> None:
        self.ensure_consulting_state()
        print(f"Консультация для {student.name}: {message}")

    def save_data(self, filename: str = "education_data.json") -> None:
        data = {
            "teachers": [t.to_dict() for t in self.teachers],
            "students": [s.to_dict() for s in self.students],
            "classrooms": [c.to_dict() for c in self.classrooms],
            "plans": [p.to_dict() for p in self.educational_plans],
            "materials": [m.to_dict() for m in self.materials],
            "lessons": [l.to_dict() for l in self.lessons],
            "student_marks": {
                student.name: [{"mark": mark.mark, "lesson_subject": mark.lesson.subject} for mark in marks]
                for student, marks in self.student_marks.items()
            }

        }
        with open(filename, "w", encoding="utf-8") as f:
            json.dump(data, f, ensure_ascii=False, indent=4)

    def load_data(self, filename: str = "education_data.json") -> None:
        if os.path.exists(filename):
            with open(filename, "r", encoding="utf-8") as f:
                data = json.load(f)
                self.teachers = [Teacher.from_dict(t) for t in data.get("teachers", [])]
                self.students = [Student.from_dict(s) for s in data.get("students", [])]
                self.classrooms = [Classroom.from_dict(c) for c in data.get("classrooms", [])]
                self.educational_plans = [EducationalPlan.from_dict(p) for p in data.get("plans", [])]
                self.materials = [EducationalMaterial.from_dict(m) for m in data.get("materials", [])]
                self.lessons = [Lesson.from_dict(l, self.teachers, self.classrooms) for l in data.get("lessons", [])]
                self.student_marks = {}
                for student_name, marks_list in data.get("student_marks", {}).items():
                    student = next(s for s in self.students if s.name == student_name)
                    self.student_marks[student] = [
                        Marks(mark["mark"], next(l for l in self.lessons if l.subject == mark["lesson_subject"]))
                        for mark in marks_list
                    ]

