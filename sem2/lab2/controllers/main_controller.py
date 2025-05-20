from PyQt5.QtCore import QObject
from PyQt5.QtWidgets import QDialog, QMessageBox
from models.student import Student
from views.main_window import MainWindow, SearchResultsWindow

class MainController(QObject):
    def __init__(self, db):
        super().__init__()
        self.db = db
        self.view = MainWindow(db)
        self.view.add_button.clicked.connect(self.add_student)
        self.view.search_button.clicked.connect(self.search_student)
        self.view.delete_button.clicked.connect(self.delete_student)
        
        self.show_all_students()
    
    def show_all_students(self):
        try:
            students = self.db.get_all_students()
            self.view.show_students(students)
        except Exception as e:
            QMessageBox.critical(self.view, "Ошибка", f"Не удалось загрузить студентов: {str(e)}")
    
    def add_student(self):
        try:
            result, student_data = self.view.show_add_dialog()
            if result:
                student = Student(
                    full_name=student_data["full_name"],
                    course=int(student_data["course"]),
                    group_number=student_data["group_number"],
                    total_works=student_data["total_works"],
                    completed_works=student_data["completed_works"],
                    programming_language=student_data["programming_language"]
                )
                self.db.add_student(student)
                self.show_all_students()
        except Exception as e:
            QMessageBox.critical(self.view, "Ошибка", f"Не удалось добавить студента: {str(e)}")
    
    def search_student(self):
        try:
            dialog = self.view.show_search_dialog()
            if dialog.exec_() == QDialog.Accepted:
                students = dialog.get_search_results()
                if students:
                    results_window = SearchResultsWindow(students, self.view)
                    if results_window.exec_() == QDialog.Accepted:
                        self.view.show_students(results_window.get_selected_students())
            else:
                pass  # Диалог был отменен
        except Exception as e:
            QMessageBox.critical(self.view, "Ошибка", f"Не удалось выполнить поиск: {str(e)}")
    
    def delete_student(self):
        try:
            filt, value = self.view.show_delete_dialog()
            if filt and value:
                deleted_count = self.db.delete_student(filt, value)
                if deleted_count > 0:
                    QMessageBox.information(self.view, "Успех", f"Удалено {deleted_count} записей")
                    self.show_all_students()
                else:
                    QMessageBox.warning(self.view, "Предупреждение", "Записи не найдены")
            elif filt is None and value is None:
                pass  
            else:
                QMessageBox.warning(self.view, "Предупреждение", "Введите значение для удаления")
        except Exception as e:
            QMessageBox.critical(self.view, "Ошибка", f"Не удалось удалить студентов: {str(e)}")