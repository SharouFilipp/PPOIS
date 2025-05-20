class Student:
    def __init__(self, full_name: str, course: str, group_number: str,  total_works: int, completed_works: int, programming_language: str ) -> None:
        self.full_name: str = full_name
        self.course: str = course
        self.group_number: str = group_number
        self.total_works: int = total_works
        self.completed_works: int = completed_works
        self.programming_language: str = programming_language

    def __str__(self) -> str:
        return f"ФИО студента: {self.full_name}, Номер группы: {self.group_number}"

    def to_dict(self) -> dict:
        return {
            "full_name": self.full_name,
            "course": self.course,
            "group_number": self.group_number,
            "total_works": self.total_works,
            "completed_works": self.completed_works,
            "programming_language": self.programming_language
            }

    @classmethod
    def from_dict(cls, data: dict) -> 'Student':
        return cls(
            full_name=data["full_name"], 
            course=data["course"],
            group_number=data["group_number"], 
            total_works=data["total_works"],
            completed_works=data["completed_works"], 
            programming_language=data["programming_language"]
            )