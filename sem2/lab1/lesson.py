from teacher import Teacher
from classroom import Classroom
from typing import List

class Lesson:
    def __init__(self, teacher: Teacher, subject: str, classroom: Classroom, start_time: str, end_time: str) -> None:
        if not subject or not start_time or not end_time:
            raise ValueError("Предмет, время начала и окончания не могут быть пустыми")
        self.teacher: Teacher = teacher
        self.subject: str = subject
        self.classroom: Classroom = classroom
        self.start_time: str = start_time
        self.end_time: str = end_time
        
    def conduct_lesson(self) -> None:
        print(f"Проводится занятие по {self.subject} с учителем {self.teacher.name} в аудитории {self.classroom.number}.")
    
    def get_classroom(self) -> str:
        return self.classroom.number
    
    def to_dict(self) -> dict:
        return {
            "teacher": self.teacher.to_dict(),
            "subject": self.subject,
            "classroom": self.classroom.to_dict(),
            "start_time": self.start_time,
            "end_time": self.end_time
        }

    @classmethod
    def from_dict(cls, data: dict, teachers: List[Teacher], classrooms: List[Classroom]) -> 'Lesson':
        teacher = next(t for t in teachers if t.name == data["teacher"]["name"])
        classroom = next(c for c in classrooms if c.number == data["classroom"]["number"])
        return cls(teacher, data["subject"], classroom, data["start_time"], data["end_time"])

