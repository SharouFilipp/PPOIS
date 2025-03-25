import argparse
from interface import EducationProcess


def main() -> None:
    parser = argparse.ArgumentParser(description="Образовательный процесс CLI")
    parser.add_argument("--add-teacher", action="store_true", help="Добавить преподавателя")
    parser.add_argument("--add-student", action="store_true", help="Добавить студента")
    parser.add_argument("--add-classroom", action="store_true", help="Добавить аудиторию")
    parser.add_argument("--add-plan", action="store_true", help="Добавить учебный план")
    parser.add_argument("--add-material", action="store_true", help="Добавить материал")
    parser.add_argument("--start-lesson", action="store_true", help="Начать занятие")
    parser.add_argument("--evaluate-student", action="store_true", help="Оценить студента")
    parser.add_argument("--consult-student", action="store_true", help="Консультировать студента")
    args = parser.parse_args()

    system = EducationProcess()
    system.load_data()

    try:
        if args.add_teacher:
            name = input("Введите ФИО преподавателя: ").strip()
            email = input("Введите email: ").strip()
            system.add_teacher(name, email)
            print(f"✅ Преподаватель {name} добавлен.")

        elif args.add_student:
            name = input("Введите ФИО студента: ").strip()
            group = input("Введите номер группы: ").strip()
            system.add_student(name, group)
            print(f"✅ Студент {name} добавлен.")

        elif args.add_classroom:
            number = input("Введите номер аудитории: ").strip()
            capacity = int(input("Введите вместимость: ").strip())
            system.add_classroom(number, capacity)
            print(f"✅ Аудитория {number} добавлена.")

        elif args.add_plan:
            name = input("Введите название учебного плана: ").strip()
            system.add_plan(name)
            print(f"✅ Учебный план {name} добавлен.")

        elif args.add_material:
            if system.state == "администрирование":
                system.to_materials()
            name = input("Введите название дисциплины: ").strip()
            author = input("Введите автора: ").strip()
            material_name = input("Введите название материала: ").strip()
            system.add_material(name, author, material_name)
            print(f"✅ Материал {material_name} добавлен.")

        elif args.start_lesson:
            if not system.teachers:
                raise ValueError("Нет преподавателей для проведения урока.")
            if not system.classrooms:
                raise ValueError("Нет аудиторий для проведения урока.")
            if system.state == "администрирование":
                system.to_materials() 

            print("Доступные преподаватели:")
            for i, teacher in enumerate(system.teachers, 1):
                print(f"{i}. {teacher.name} ({teacher.email})")
            teacher_idx = int(input("Выберите номер преподавателя: ")) - 1
            if teacher_idx < 0 or teacher_idx >= len(system.teachers):
                raise ValueError("Неверный выбор преподавателя.")
            teacher = system.teachers[teacher_idx]

            subject = input("Введите предмет: ").strip()

            print("Доступные аудитории:")
            for i, classroom in enumerate(system.classrooms, 1):
                print(f"{i}. {classroom.number} (вместимость: {classroom.capacity})")
            classroom_idx = int(input("Выберите номер аудитории: ")) - 1
            if classroom_idx < 0 or classroom_idx >= len(system.classrooms):
                raise ValueError("Неверный выбор аудитории.")
            classroom = system.classrooms[classroom_idx]

            start_time = input("Введите время начала: ").strip()
            end_time = input("Введите время окончания: ").strip()
            system.start_lesson(teacher, subject, classroom, start_time, end_time)
            print(f"✅ Занятие по {subject} начато.")


        elif args.evaluate_student:
            if not system.lessons:
                raise ValueError("Нет проведённых уроков для оценивания.")
            if not system.students:
                raise ValueError("Нет студентов для оценивания.")

            if system.state != "оценивание студентов":
                if system.state == "проведение занятий":
                    system.to_evaluation()
                elif system.state == "администрирование":
                    system.to_materials()
                    system.to_lessons()
                    system.to_evaluation()

            print("Доступные уроки:")
            for i, lesson in enumerate(system.lessons, 1):
                print(f"{i}. {lesson.subject} ({lesson.start_time} - {lesson.end_time})")
            lesson_idx = int(input("Выберите номер урока: ")) - 1
            if lesson_idx < 0 or lesson_idx >= len(system.lessons):
                raise ValueError("Неверный выбор урока.")
            lesson = system.lessons[lesson_idx]

            print("Доступные студенты:")
            for i, student in enumerate(system.students, 1):
                print(f"{i}. {student.name} (группа: {student.group_number})")
            student_idx = int(input("Выберите номер студента: ")) - 1
            if student_idx < 0 or student_idx >= len(system.students):
                raise ValueError("Неверный выбор студента.")
            student = system.students[student_idx]

            mark = int(input("Введите оценку: ").strip())
            system.evaluate_student(lesson, student, mark)
            print(f"✅ Студент {student.name} оценён: {mark}.")

        elif args.consult_student:
            if not system.students:
                raise ValueError("Нет студентов для консультирования.")

            if system.state != "консультирование":
                if system.state == "оценивание студентов":
                    system.to_consulting()
                elif system.state == "администрирование":
                    system.to_materials()
                    system.to_lessons()
                    system.to_evaluation()
                    system.to_consulting()

            print("Доступные студенты:")
            for i, student in enumerate(system.students, 1):
                print(f"{i}. {student.name} (группа: {student.group_number})")
            student_idx = int(input("Выберите номер студента: ")) - 1
            if student_idx < 0 or student_idx >= len(system.students):
                raise ValueError("Неверный выбор студента.")
            student = system.students[student_idx]

            message = input("Введите сообщение для консультации: ").strip()
            system.consult_student(student, message)

    except ValueError as e:
        print(f"❌ Ошибка: {e}")
    except Exception as e:
        print(f"❌ Неизвестная ошибка: {e}")

    system.save_data()

if __name__ == "__main__":
    main()
