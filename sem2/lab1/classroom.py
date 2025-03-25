class Classroom:
    def __init__(self, number: str, capacity: int) -> None:
        if not number:
            raise ValueError("Номер аудитории не может быть пустым")
        if capacity <= 0:
            raise ValueError("Вместимость аудитории должна быть положительным числом")
        self.number: str = number
        self.capacity: int = capacity
    
    def __str__(self) -> str:
        return f"Номер аудитории: {self.number}\nВместимость: {self.capacity}"
    
    def to_dict(self) -> dict:
        return {"number": self.number, "capacity": self.capacity}

    @classmethod
    def from_dict(cls, data: dict) -> 'Classroom':
        return cls(number=data["number"], capacity=data["capacity"])
