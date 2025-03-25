from typing import List, Dict

class EducationalMaterial:
    def __init__(self, name: str) -> None:
        if not name:
            raise ValueError("Название дисциплины не может быть пустым")
        self.name: str = name
        self.materials: List[Dict[str, str]] = []

    def __str__(self) -> str:
        courses = self.display_material()
        return f"Дисциплина: {self.name}\nСписок материалов:\n{courses}"

    def add_material(self, author: str, material_name: str) -> None:
        if not author or not material_name:
            raise ValueError("Автор и название материала не могут быть пустыми")
        self.materials.append({"author": author, "name": material_name})
        
    def display_material(self) -> str:
        if not self.materials:
            return "Нет материалов."
        return "\n".join(f"Автор: {m['author']}, Название: {m['name']}" for m in self.materials)

    def to_dict(self) -> dict:
        return {"name": self.name, "materials": self.materials}

    @classmethod
    def from_dict(cls, data: dict) -> 'EducationalMaterial':
        material = cls(data["name"])
        material.materials = data.get("materials", [])
        return material
