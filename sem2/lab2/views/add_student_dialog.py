from PyQt5.QtWidgets import QDialog, QLineEdit, QFormLayout, QDialogButtonBox, QMessageBox

class AddStudentDialog(QDialog):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Добавить студента")
        self.setFixedWidth(400)
        
        self.full_name_input = QLineEdit()
        self.course_input = QLineEdit()
        self.group_input = QLineEdit()
        self.total_works_input = QLineEdit()
        self.completed_works_input = QLineEdit()
        self.language_input = QLineEdit()
        
        for input_field in [self.full_name_input, self.course_input, self.group_input,
                            self.total_works_input, self.completed_works_input, self.language_input]:
            input_field.setStyleSheet("QLineEdit { padding: 5px; border: 1px solid #ddd; border-radius: 4px; }")
        
        buttons = QDialogButtonBox(QDialogButtonBox.Ok | QDialogButtonBox.Cancel)
        buttons.accepted.connect(self.validate_inputs)
        buttons.rejected.connect(self.reject)
        
        layout = QFormLayout()
        layout.setSpacing(10)
        layout.setContentsMargins(10, 10, 10, 10)
        layout.addRow("ФИО:", self.full_name_input)
        layout.addRow("Курс:", self.course_input)
        layout.addRow("Группа:", self.group_input)
        layout.addRow("Всего работ:", self.total_works_input)
        layout.addRow("Выполнено работ:", self.completed_works_input)
        layout.addRow("Язык программирования:", self.language_input)
        layout.addRow(buttons)
        
        self.setLayout(layout)
    
    def validate_inputs(self):
        errors = []
        
        full_name = self.full_name_input.text().strip()
        course = self.course_input.text().strip()
        group = self.group_input.text().strip()
        total_works = self.total_works_input.text().strip()
        completed_works = self.completed_works_input.text().strip()
        language = self.language_input.text().strip()
        
        if not any([full_name, course, group, total_works, completed_works, language]):
            errors.append("• Все поля должны быть заполнены")
            QMessageBox.warning(self, "Ошибка", "Все поля формы должны быть заполнены", QMessageBox.Ok)
            return
        
        if not full_name:
            errors.append("• ФИО не может быть пустым")
        elif full_name.isdigit():
            errors.append("• ФИО не может состоять только из цифр")
        
        if not course:
            errors.append("• Поле курса не может быть пустым")
        else:
            try:
                course_num = int(course)
                if course_num < 1 or course_num > 6:
                    errors.append("• Курс должен быть от 1 до 6")
            except ValueError:
                errors.append("• Курс должен быть числом")
        
        if not group:
            errors.append("• Группа не может быть пустой")
        elif group.isdigit():
            errors.append("• Номер группы не может состоять только из цифр")
        
        if not total_works:
            errors.append("• Общее количество работ не может быть пустым")
        else:
            try:
                total = int(total_works)
                if total <= 0:
                    errors.append("• Общее количество работ должно быть положительным")
            except ValueError:
                errors.append("• Общее количество работ должно быть числом")
        
        if not completed_works:
            errors.append("• Количество выполненных работ не может быть пустым")
        else:
            try:
                completed = int(completed_works)
                if completed < 0:
                    errors.append("• Выполненные работы не могут быть отрицательными")
                if 'total' in locals() and completed > total:
                    errors.append("• Выполненных работ не может быть больше общего количества")
            except ValueError:
                errors.append("• Выполненные работы должны быть числом")
        
        if not language:
            errors.append("• Язык программирования не может быть пустым")
        elif language.isdigit():
            errors.append("• Язык программирования не может состоять только из цифр")
        
        if errors:
            QMessageBox.warning(self, "Ошибки ввода", "Исправьте следующие ошибки:\n" + "\n".join(errors), QMessageBox.Ok)
        else:
            self.accept()
    
    def get_student_data(self):
        return {
            "full_name": self.full_name_input.text(),
            "course": self.course_input.text(),
            "group_number": self.group_input.text(),
            "total_works": int(self.total_works_input.text()),
            "completed_works": int(self.completed_works_input.text()),
            "programming_language": self.language_input.text()
        }