class Teacher:
    def __init__(self, name: str, email: str) -> None:
        if not name or not email:
            raise ValueError("Имя и email не могут быть пустыми")
        self.name: str = name
        self.email: str = email

    def __str__(self) -> str:
        return f"ФИО преподавателя: {self.name}, Email: {self.email}"

    def to_dict(self) -> dict:
        return {"name": self.name, "email": self.email}

    @classmethod
    def from_dict(cls, data: dict) -> 'Teacher':
        return cls(name=data["name"], email=data["email"])
