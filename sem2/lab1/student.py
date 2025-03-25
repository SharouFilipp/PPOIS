class Student:
    def __init__(self, name: str, group_number: str) -> None:
        if not name or not group_number:
            raise ValueError("Имя и номер группы не могут быть пустыми")
        self.name: str = name
        self.group_number: str = group_number

    def __str__(self) -> str:
        return f"ФИО студента: {self.name}, Номер группы: {self.group_number}"

    def to_dict(self) -> dict:
        return {"name": self.name, "group_number": self.group_number}

    @classmethod
    def from_dict(cls, data: dict) -> 'Student':
        return cls(name=data["name"], group_number=data["group_number"])
