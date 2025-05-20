from PyQt5.QtCore import QAbstractTableModel, Qt
from math import ceil

class StudentTableModel(QAbstractTableModel):
    def __init__(self, students, page=1, per_page=10):
        super().__init__()
        self.all_students = students
        self.headers = [
            "ФИО", "Курс", "Группа", 
            "Всего работ", "Выполнено", 
            "Язык программирования"
        ]
        self.page = page
        self.per_page = per_page
        self.students = []
        self.update_page()
    
    def update_page(self):
        start = (self.page - 1) * self.per_page
        end = start + self.per_page
        self.students = self.all_students[start:end]
        
        top_left = self.index(0, 0)
        bottom_right = self.index(self.rowCount() - 1, self.columnCount() - 1)
        self.dataChanged.emit(top_left, bottom_right)
        self.layoutChanged.emit()
    
    def set_page(self, page):
        total_pages = self.total_pages()
        if page < 1:
            page = 1
        elif page > total_pages:
            page = total_pages
        self.page = page
        self.update_page()
    
    def set_per_page(self, per_page):
        self.per_page = per_page
        self.page = 1
        self.update_page()
    
    def total_pages(self):
        return max(1, ceil(len(self.all_students) / self.per_page))
    
    def rowCount(self, parent=None):
        return len(self.students)
    
    def columnCount(self, parent=None):
        return len(self.headers)
    
    def data(self, index, role=Qt.DisplayRole):
        if role == Qt.DisplayRole and index.isValid():
            student = self.students[index.row()]
            return [
                student.full_name,
                student.course,
                student.group_number,
                student.total_works,
                student.completed_works,
                student.programming_language
            ][index.column()]
        return None
    
    def headerData(self, section, orientation, role=Qt.DisplayRole):
        if role == Qt.DisplayRole and orientation == Qt.Horizontal:
            return self.headers[section]
        return None