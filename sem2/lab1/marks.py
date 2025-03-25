from lesson import Lesson

class Marks:
    def __init__(self, mark: int, lesson: Lesson) -> None:
        if not isinstance(mark, int) or mark < 0 or mark > 100:
            raise ValueError("Оценка должна быть целым числом от 0 до 100")
        self.mark: int = mark
        self.lesson: Lesson = lesson
    
    def __str__(self) -> str:
        return f"Оценка: {self.mark} (урок: {self.lesson.subject})"
