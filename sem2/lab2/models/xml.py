import xml.dom.minidom as minidom
import xml.sax
from typing import List
from models.student import Student
import os

class XMLDatabase:
    def __init__(self, xml_path: str = "students.xml"):
        self.xml_path = xml_path
        self._initialize_file()
    
    def _initialize_file(self):
        if not os.path.exists(self.xml_path):
            doc = minidom.Document()
            root = doc.createElement("students")
            doc.appendChild(root)
            self._write_xml(doc)
    
    def _write_xml(self, doc: minidom.Document):
        with open(self.xml_path, "w", encoding="utf-8") as f:
            f.write(doc.toprettyxml(indent="    "))
    
    def add_student(self, student: Student) -> int:
        doc = minidom.parse(self.xml_path)
        root = doc.getElementsByTagName("students")[0]
        
        students = root.getElementsByTagName("student")
        max_id = 0
        for s in students:
            sid = int(s.getAttribute("id"))
            if sid > max_id:
                max_id = sid
        
        new_id = max_id + 1
        
       
        student_elem = doc.createElement("student")
        student_elem.setAttribute("id", str(new_id))
        
        fields = [
            ("full_name", student.full_name),
            ("course", str(student.course)),
            ("group_number", student.group_number),
            ("total_works", str(student.total_works)),
            ("completed_works", str(student.completed_works)),
            ("programming_language", student.programming_language)
        ]
        
        for tag, value in fields:
            elem = doc.createElement(tag)
            elem.appendChild(doc.createTextNode(value))
            student_elem.appendChild(elem)
        
        root.appendChild(student_elem)
        self._write_xml(doc)
        return new_id
    
    def get_all_students(self) -> List[Student]:
        handler = StudentSAXHandler()
        parser = xml.sax.make_parser()
        parser.setContentHandler(handler)
        parser.parse(self.xml_path)
        return handler.students
    
    def search_student(self, filt: str, value: str) -> List[Student]:
        all_students = self.get_all_students()
        filtered = []
        
        for student in all_students:
            if filt == "ФИО студента" and value.lower() in student.full_name.lower():
                filtered.append(student)
            elif filt == "Курс":
                try:
                    if student.course == int(value):
                        filtered.append(student)
                except ValueError:
                    continue
            elif filt == "Группа" and value.lower() in student.group_number.lower():
                filtered.append(student)
            elif filt == "Язык программирования" and value.lower() == student.programming_language.lower():
                filtered.append(student)
            elif filt == "Количество выполненных работ":
                try:
                    if student.completed_works == int(value):
                        filtered.append(student)
                except ValueError:
                    continue
            elif filt == "Общее число работ":
                try:
                    if student.total_works == int(value):
                        filtered.append(student)
                except ValueError:
                    continue
        
        return filtered
    
    def delete_student(self, filt: str, value: str) -> int:
        doc = minidom.parse(self.xml_path)
        root = doc.getElementsByTagName("students")[0]
        students = root.getElementsByTagName("student")
        deleted_count = 0
        
        for student_elem in students[:]:  # Копируем список, чтобы можно было удалять
            student_data = {}
            for child in student_elem.childNodes:
                if child.nodeType == child.ELEMENT_NODE:
                    student_data[child.tagName] = child.firstChild.nodeValue if child.firstChild else ""
            
            matches = False
            if filt == "ФИО студента" and value.lower() in student_data.get("full_name", "").lower():
                matches = True
            elif filt == "Курс":
                try:
                    if int(student_data.get("course", "0")) == int(value):
                        matches = True
                except ValueError:
                    continue
            elif filt == "Группа" and value.lower() in student_data.get("group_number", "").lower():
                matches = True
            elif filt == "Язык программирования" and value.lower() == student_data.get("programming_language", "").lower():
                matches = True
            elif filt == "Количество выполненных работ":
                try:
                    if int(student_data.get("completed_works", "0")) == int(value):
                        matches = True
                except ValueError:
                    continue
            elif filt == "Общее число работ":
                try:
                    if int(student_data.get("total_works", "0")) == int(value):
                        matches = True
                except ValueError:
                    continue
            
            if matches:
                root.removeChild(student_elem)
                deleted_count += 1
        
        if deleted_count > 0:
            self._write_xml(doc)
        
        return deleted_count

class StudentSAXHandler(xml.sax.ContentHandler):
    def __init__(self):
        super().__init__()
        self.students = []
        self.current_student = None
        self.current_tag = None
        self.current_data = {}
    
    def startElement(self, name, attrs):
        self.current_tag = name
        if name == "student":
            self.current_data = {"id": attrs.get("id", "0")}
    
    def characters(self, content):
        if self.current_tag in ["full_name", "course", "group_number", "total_works", "completed_works", "programming_language"]:
            self.current_data[self.current_tag] = content.strip()
    
    def endElement(self, name):
        if name == "student":
            try:
                student = Student(
                    full_name=self.current_data.get("full_name", ""),
                    course=int(self.current_data.get("course", "0")),
                    group_number=self.current_data.get("group_number", ""),
                    total_works=int(self.current_data.get("total_works", "0")),
                    completed_works=int(self.current_data.get("completed_works", "0")),
                    programming_language=self.current_data.get("programming_language", "")
                )
                self.students.append(student)
            except ValueError:
                pass  # Пропускаем некорректные записи
            self.current_data = {}
        self.current_tag = None
