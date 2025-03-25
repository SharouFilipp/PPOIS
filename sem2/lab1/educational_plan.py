from typing import List, Dict

class EducationalPlan:
    def __init__(self, name: str, courses_and_hours: List[Dict[str, int]] = None) -> None:
        if not name:
            raise ValueError("Название учебного плана не может быть пустым")
        self.name: str = name
        self.courses_and_hours: List[Dict[str, int]] = courses_and_hours if courses_and_hours is not None else []

    def __str__(self) -> str:
        courses = self.display_courses()
        return f"Учебный план: {self.name}\nСписок предметов:\n{courses}"

    def add_course(self, course: str, hours: int) -> None:
        if not course:
            raise ValueError("Название курса не может быть пустым")
        if hours <= 0:
            raise ValueError("Количество часов должно быть положительным")
        self.courses_and_hours.append({course: hours})

    def display_courses(self) -> str:
        if not self.courses_and_hours:
            return "Нет курсов в учебном плане."
        return "\n".join(f"Дисциплина: {list(c.keys())[0]}, Часов: {list(c.values())[0]}" for c in self.courses_and_hours)

    def to_dict(self) -> dict:
        return {"name": self.name, "courses_and_hours": self.courses_and_hours}

    @classmethod
    def from_dict(cls, data: dict) -> 'EducationalPlan':
        return cls(name=data["name"], courses_and_hours=data.get("courses_and_hours", []))
