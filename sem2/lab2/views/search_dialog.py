from PyQt5.QtWidgets import QDialog, QLineEdit, QComboBox, QPushButton, QLabel, QVBoxLayout, QHBoxLayout, QDialogButtonBox, QMessageBox
from models.student import Student

class SearchDialog(QDialog):
    def __init__(self, criterion, values, db):
        super().__init__()
        self.setWindowTitle("Поиск студента")
        self.setFixedWidth(400)
        self.criterion = criterion
        self.db = db
        self.search_results = []
        
        self.search_input = QLineEdit()
        self.search_input.setPlaceholderText("Введите запрос")
        self.search_input.setStyleSheet("QLineEdit { padding: 5px; border: 1px solid #ddd; border-radius: 4px; }")
        
        self.values_combo = QComboBox()
        self.values_combo.setStyleSheet("QComboBox { padding: 5px; border: 1px solid #ddd; border-radius: 4px; }")
        self.values_combo.addItem("Выберите значение")
        self.values_combo.addItems(values)
        self.values_combo.currentTextChanged.connect(self.on_combo_changed)
        
        self.search_button = QPushButton("Найти")
        self.search_button.setStyleSheet("QPushButton { background-color: #2196F3; color: white; border-radius: 4px; padding: 8px; }"
                                        "QPushButton:hover { background-color: #1976D2; }")
        self.search_button.clicked.connect(self.perform_search)
        
        buttons = QDialogButtonBox(QDialogButtonBox.Cancel)
        buttons.rejected.connect(self.reject)
        
        layout = QVBoxLayout()
        layout.setSpacing(10)
        layout.setContentsMargins(10, 10, 10, 10)
        
        input_layout = QHBoxLayout()
        input_layout.addWidget(QLabel(f"Критерий: {criterion}"))
        if criterion in ["Язык программирования", "Количество выполненных работ", "Общее число работ"] and values:
            input_layout.addWidget(self.values_combo)
        input_layout.addWidget(self.search_input)
        input_layout.addWidget(self.search_button)
        
        layout.addLayout(input_layout)
        layout.addWidget(buttons)
        
        self.setLayout(layout)
    
    def on_combo_changed(self, text):
        if text != "Выберите значение":
            self.search_input.setText(text)
    
    def perform_search(self):
        search_text = self.search_input.text().strip()
        if not search_text:
            QMessageBox.warning(self, "Предупреждение", "Введите значение для поиска")
            return
        
        try:
            raw_results = self.db.search_student(self.criterion, search_text)
            print(f"Результаты поиска (сырые): {raw_results}")  # Отладка
            self.search_results = []
            if not isinstance(raw_results, list):
                print(f"Ошибка: raw_results не список, а {type(raw_results)}")
                raw_results = [raw_results] if raw_results else []
            for row in raw_results:
                if isinstance(row, Student):
                    self.search_results.append(row)
                    continue
                if not isinstance(row, (list, tuple)) or len(row) != 6:
                    print(f"Ошибка: неверный формат строки: {row}")
                    continue
                try:
                    student = Student(
                        full_name=row[0],
                        course=row[1],
                        group_number=row[2],
                        total_works=int(row[3]),
                        completed_works=int(row[4]),
                        programming_language=row[5]
                    )
                    self.search_results.append(student)
                except (ValueError, TypeError) as e:
                    print(f"Ошибка при преобразовании строки {row}: {e}")
                    continue
            if not self.search_results:
                QMessageBox.information(self, "Результат", "Записи не найдены")
                return
            print(f"Преобразовано {len(self.search_results)} студентов")  # Отладка
            self.accept()
        except Exception as e:
            QMessageBox.critical(self, "Ошибка", f"Не удалось выполнить поиск: {str(e)}")
    
    def get_search_results(self):
        return self.search_results, self.criterion