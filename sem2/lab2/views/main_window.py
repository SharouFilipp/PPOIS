from PyQt5.QtWidgets import (
    QMainWindow, QTableView, QTreeWidget, QTreeWidgetItem, QVBoxLayout, QWidget, 
    QPushButton, QLineEdit, QFormLayout, QDialog, QDialogButtonBox, 
    QLabel, QHBoxLayout, QSizePolicy, QHeaderView, QMessageBox, QComboBox
)
from PyQt5.QtCore import QAbstractTableModel, Qt
from PyQt5.QtGui import QFont, QIntValidator
from math import ceil
from models.student import Student

class MainWindow(QMainWindow):
    def __init__(self, db):
        super().__init__()
        self.db = db
        self.setWindowTitle("Студенты")
        
        # Основные виджеты
        self.table_view = QTableView()
        self.tree_widget = QTreeWidget()
        self.add_button = QPushButton("Добавить студента")
        self.search_button = QPushButton("Поиск")
        self.delete_button = QPushButton("Удалить")
        self.toggle_view_button = QPushButton("Переключить на дерево")
        self.first_btn = QPushButton("<<")
        self.prev_btn = QPushButton("<")
        self.next_btn = QPushButton(">")
        self.last_btn = QPushButton(">>")
        self.page_label = QLabel("Страница 1 из 1")
        self.per_page_input = QLineEdit("10")
        self.stats_label = QLabel("Записи 0-0 из 0")
        self.search_combo = QComboBox()
        self.delete_combo = QComboBox()
        self.toggle_view_button.clicked.connect(self.toggle_view)
        
        # Валидатор для per_page_input
        self.per_page_validator = QIntValidator(1, 1000, self)
        self.per_page_input.setValidator(self.per_page_validator)
        self.per_page_input.setFixedWidth(60)
        self.per_page_input.setStyleSheet("QLineEdit { padding: 5px; border: 1px solid #ddd; border-radius: 4px; }")
        self.per_page_input.editingFinished.connect(self.change_per_page)
        
        # Настройка выпадающих списков
        criteria = ["ФИО студента", "Курс", "Группа", "Язык программирования",
                    "Количество выполненных работ", "Общее число работ"]
        self.search_combo.addItems(criteria)
        self.delete_combo.addItems(criteria)
        
        # Настройка дерева
        self.tree_widget.setHeaderLabels(["Информация"])
        self.tree_widget.setColumnCount(1)
        self.tree_widget.setStyleSheet("""
            QTreeWidget { 
                border: 1px solid #ddd; 
                font-size: 12px; 
            }
            QTreeWidget::item { 
                padding: 2px; 
            }
        """)
        self.tree_widget.setHidden(True)
        
        # Стилизация
        for btn in [self.add_button, self.search_button, self.delete_button, 
                    self.toggle_view_button, self.first_btn, self.prev_btn, self.next_btn, self.last_btn]:
            btn.setFixedHeight(30)
            btn.setFont(QFont("Arial", 10))
        
        for combo in [self.search_combo, self.delete_combo]:
            combo.setStyleSheet("QComboBox { padding: 5px; border: 1px solid #ddd; border-radius: 4px; }")
        
        self.toggle_view_button.setStyleSheet("QPushButton { background-color: #FF9800; color: white; border-radius: 4px; padding: 8px; }"
                                             "QPushButton:hover { background-color: #F57C00; }")
        self.add_button.setStyleSheet("QPushButton { background-color: #4CAF50; color: white; border-radius: 4px; padding: 8px; }"
                                      "QPushButton:hover { background-color: #45a049; }")
        self.search_button.setStyleSheet("QPushButton { background-color: #2196F3; color: white; border-radius: 4px; padding: 8px; }"
                                        "QPushButton:hover { background-color: #1976D2; }")
        self.delete_button.setStyleSheet("QPushButton { background-color: #f44336; color: white; border-radius: 4px; padding: 8px; }"
                                        "QPushButton:hover { background-color: #d32f2f; }")
        
        # Подключение сигналов
        self.first_btn.clicked.connect(self.first_page)
        self.prev_btn.clicked.connect(self.prev_page)
        self.next_btn.clicked.connect(self.next_page)
        self.last_btn.clicked.connect(self.last_page)
        
        self.is_table_view = True
        self.last_valid_per_page = 10
        
        self.setup_ui()
        self.show_students(self.db.get_all_students())
        
        self.setMinimumSize(800, 600)
    
    def change_per_page(self):
        text = self.per_page_input.text().strip()
        try:
            per_page = int(text)
            if per_page < 1:
                raise ValueError("Количество записей должно быть положительным")
            self.last_valid_per_page = per_page
            if hasattr(self, 'model') and self.model:
                self.model.set_per_page(per_page)
                self.table_view.reset()
                self.update_page_info()
        except ValueError:
            QMessageBox.warning(self, "Ошибка", "Введите положительное целое число (например, 10)")
            self.per_page_input.setText(str(self.last_valid_per_page))
    
    def get_unique_values(self, criterion):
        if not hasattr(self, 'model') or not self.model.all_students:
            return []
        if criterion == "Язык программирования":
            return sorted(set(student.programming_language for student in self.model.all_students))
        elif criterion == "Количество выполненных работ":
            return sorted(set(str(student.completed_works) for student in self.model.all_students))
        elif criterion == "Общее число работ":
            return sorted(set(str(student.total_works) for student in self.model.all_students))
        return []
    def update_students(self, students):
        """Обновляем список студентов в модели"""
        print(f"Обновление студентов: {len(students)} записей")  # Отладка
        self.show_students(students)
    
    def setup_ui(self):
        central_widget = QWidget()
        self.setCentralWidget(central_widget)
        
        main_layout = QVBoxLayout(central_widget)
        main_layout.setContentsMargins(10, 10, 10, 10)
        main_layout.setSpacing(15)
        
        top_panel = QHBoxLayout()
        top_panel.addWidget(self.add_button)
        top_panel.addWidget(self.toggle_view_button)
        main_layout.addLayout(top_panel, stretch=0)
        
        search_panel = QHBoxLayout()
        search_panel.setSpacing(10)
        search_panel.addWidget(self.search_combo)
        search_panel.addWidget(self.search_button)
        main_layout.addLayout(search_panel, stretch=0)
        
        delete_panel = QHBoxLayout()
        delete_panel.setSpacing(10)
        delete_panel.addWidget(self.delete_combo)
        delete_panel.addWidget(self.delete_button)
        main_layout.addLayout(delete_panel, stretch=0)
        
        self.table_view.setSizePolicy(QSizePolicy.Expanding, QSizePolicy.Expanding)
        self.table_view.horizontalHeader().setStretchLastSection(True)
        self.table_view.horizontalHeader().setSectionResizeMode(QHeaderView.Stretch)
        self.table_view.setAlternatingRowColors(True)
        self.table_view.setStyleSheet("QTableView { border: 1px solid #ddd; gridline-color: #eee; }")
        
        self.tree_widget.setSizePolicy(QSizePolicy.Expanding, QSizePolicy.Expanding)
        
        self.view_container = QVBoxLayout()
        self.view_container.addWidget(self.table_view)
        self.view_container.addWidget(self.tree_widget)
        main_layout.addLayout(self.view_container, stretch=1)
        
        self.pagination_widget = QWidget()
        self.pagination_panel = QHBoxLayout(self.pagination_widget)
        self.pagination_panel.setSpacing(10)
        self.pagination_panel.addStretch(1)
        self.pagination_panel.addWidget(QLabel("Записей на странице:"))
        self.pagination_panel.addWidget(self.per_page_input)
        self.pagination_panel.addWidget(self.first_btn)
        self.pagination_panel.addWidget(self.prev_btn)
        self.pagination_panel.addWidget(self.page_label)
        self.pagination_panel.addWidget(self.next_btn)
        self.pagination_panel.addWidget(self.last_btn)
        self.pagination_panel.addWidget(self.stats_label)
        self.pagination_panel.addStretch(1)
        main_layout.addWidget(self.pagination_widget, stretch=0)
    
    def toggle_view(self):
        self.is_table_view = not self.is_table_view
        self.table_view.setHidden(not self.is_table_view)
        self.tree_widget.setHidden(self.is_table_view)
        self.toggle_view_button.setText("Переключить на " + ("таблицу" if self.is_table_view else "дерево"))
        self.pagination_widget.setHidden(not self.is_table_view)
        
        if not self.is_table_view and hasattr(self, 'model') and self.model.all_students:
            self.update_tree()
    
    def update_tree(self):
        self.tree_widget.clear()
        if not hasattr(self, 'model') or not self.model.all_students:
            print("No students to display in tree")  # Отладка
            return
        
        print(f"Updating tree with {len(self.model.all_students)} students")  # Отладка
        for student in sorted(self.model.all_students, key=lambda s: s.full_name):
            student_item = QTreeWidgetItem(self.tree_widget, [student.full_name])
            QTreeWidgetItem(student_item, [f"Курс: {student.course}"])
            QTreeWidgetItem(student_item, [f"Группа: {student.group_number}"])
            QTreeWidgetItem(student_item, [f"Язык программирования: {student.programming_language}"])
            QTreeWidgetItem(student_item, [f"Всего работ: {student.total_works}"])
            QTreeWidgetItem(student_item, [f"Выполнено работ: {student.completed_works}"])
        self.tree_widget.expandAll()
        self.tree_widget.viewport().update()  # Принудительное обновление интерфейса
    
    def show_search_dialog(self):
        filt = self.search_combo.currentText()
        values = self.get_unique_values(filt)
        dialog = SearchDialog(filt, values, self.db)
        if dialog.exec_() == QDialog.Accepted:
            results, criterion = dialog.get_search_results()
            print(f"Получено результатов поиска: {results}, тип: {type(results)}")  # Отладка
            # Убедимся, что results - это список
            if not isinstance(results, list):
                print(f"Ошибка: results не список, а {type(results)}")
                results = [results] if results else []
            # Фильтруем только объекты Student
            students = [
                student for student in results
                if isinstance(student, Student)
            ]
            if not students:
                QMessageBox.information(self, "Результат", "Нет валидных результатов поиска")
                return dialog
            print(f"Фильтровано {len(students)} студентов для отображения")  # Отладка
            # Показываем результаты в новом окне
            search_window = SearchResultsWindow(students, self)
            search_window.exec_()
        return dialog
    
    def show_delete_dialog(self):
        filt = self.delete_combo.currentText()
        values = self.get_unique_values(filt)
        dialog = DeleteDialog(filt, values)
        if dialog.exec_() == QDialog.Accepted:
            delete_text = dialog.get_delete_text()
            return filt, delete_text
        return None, None
    
    def show_add_dialog(self):
        dialog = AddStudentDialog()
        if dialog.exec_() == QDialog.Accepted:
            data = dialog.get_student_data()
            return True, data
        return False, None
    
    def show_students(self, students):
        per_page = self.last_valid_per_page
        try:
            per_page = int(self.per_page_input.text().strip())
            if per_page < 1:
                per_page = self.last_valid_per_page
        except ValueError:
            per_page = self.last_valid_per_page
        self.per_page_input.setText(str(per_page))
        self.last_valid_per_page = per_page
        self.model = StudentTableModel(students, page=1, per_page=per_page)
        self.table_view.setModel(self.model)
        self.table_view.reset()
        if not self.is_table_view:
            self.update_tree()  # Обновляем дерево при изменении данных
        self.update_page_info()
    
    def first_page(self):
        if hasattr(self, 'model') and self.model:
            self.model.set_page(1)
            self.table_view.reset()
            self.update_page_info()
    
    def prev_page(self):
        if hasattr(self, 'model') and self.model and self.model.page > 1:
            self.model.set_page(self.model.page - 1)
            self.table_view.reset()
            self.update_page_info()
    
    def next_page(self):
        if hasattr(self, 'model') and self.model and self.model.page < self.model.total_pages():
            self.model.set_page(self.model.page + 1)
            self.table_view.reset()
            self.update_page_info()
    
    def last_page(self):
        if hasattr(self, 'model') and self.model:
            self.model.set_page(self.model.total_pages())
            self.table_view.reset()
            self.update_page_info()
    
    def update_page_info(self):
        if hasattr(self, 'model') and self.model and self.model.all_students:
            total_pages = self.model.total_pages()
            total_records = len(self.model.all_students)
            per_page = self.model.per_page
            start = (self.model.page - 1) * per_page + 1
            end = min(self.model.page * per_page, total_records)
            self.page_label.setText(f"Страница {self.model.page} из {total_pages}")
            self.stats_label.setText(f"Записи {start}-{end} из {total_records}")
            self.first_btn.setEnabled(self.model.page > 1)
            self.prev_btn.setEnabled(self.model.page > 1)
            self.next_btn.setEnabled(self.model.page < total_pages)
            self.last_btn.setEnabled(self.model.page < total_pages)
        else:
            self.page_label.setText("Страница 0 из 0")
            self.stats_label.setText("Записи 0-0 из 0")
            self.first_btn.setEnabled(False)
            self.prev_btn.setEnabled(False)
            self.next_btn.setEnabled(False)
            self.last_btn.setEnabled(False)

class SearchResultsWindow(QDialog):
   
    
    def __init__(self, students, parent=None):
        super().__init__(parent)
        self.setWindowTitle("Результаты поиска")
        self.setMinimumSize(600, 400)
        
        self.table_view = QTableView()
        self.first_btn = QPushButton("<<")
        self.prev_btn = QPushButton("<")
        self.next_btn = QPushButton(">")
        self.last_btn = QPushButton(">>")
        self.page_label = QLabel("Страница 1 из 1")
        self.per_page_input = QLineEdit("10")
        self.stats_label = QLabel("Записи 0-0 из 0")
        self.apply_btn = QPushButton("Применить")  # Новая кнопка
        
        self.per_page_validator = QIntValidator(1, 1000, self)
        self.per_page_input.setValidator(self.per_page_validator)
        self.per_page_input.setFixedWidth(60)
        self.per_page_input.setStyleSheet("QLineEdit { padding: 5px; border: 1px solid #ddd; border-radius: 4px; }")
        self.per_page_input.editingFinished.connect(self.change_per_page)
        
        self.last_valid_per_page = 10
        
        for btn in [self.first_btn, self.prev_btn, self.next_btn, self.last_btn, self.apply_btn]:
            btn.setFixedHeight(30)
            btn.setFont(QFont("Arial", 10))
        
        self.apply_btn.setStyleSheet("QPushButton { background-color: #4CAF50; color: white; border-radius: 4px; padding: 8px; }"
                                     "QPushButton:hover { background-color: #45a049; }")
        
        self.table_view.setSizePolicy(QSizePolicy.Expanding, QSizePolicy.Expanding)
        self.table_view.horizontalHeader().setStretchLastSection(True)
        self.table_view.horizontalHeader().setSectionResizeMode(QHeaderView.Stretch)
        self.table_view.setAlternatingRowColors(True)
        self.table_view.setStyleSheet("QTableView { border: 1px solid #ddd; gridline-color: #eee; }")
        
        self.first_btn.clicked.connect(self.first_page)
        self.prev_btn.clicked.connect(self.prev_page)
        self.next_btn.clicked.connect(self.next_page)
        self.last_btn.clicked.connect(self.last_page)
        self.apply_btn.clicked.connect(self.apply_changes)
        
        buttons = QDialogButtonBox(QDialogButtonBox.Close)
        buttons.rejected.connect(self.reject)
        
        main_layout = QVBoxLayout()
        main_layout.setContentsMargins(10, 10, 10, 10)
        main_layout.setSpacing(15)
        
        main_layout.addWidget(self.table_view, stretch=1)
        
        pagination_panel = QHBoxLayout()
        pagination_panel.addStretch(1)
        pagination_panel.addWidget(QLabel("Записей на странице:"))
        pagination_panel.addWidget(self.per_page_input)
        pagination_panel.addWidget(self.apply_btn)
        pagination_panel.addWidget(self.first_btn)
        pagination_panel.addWidget(self.prev_btn)
        pagination_panel.addWidget(self.page_label)
        pagination_panel.addWidget(self.next_btn)
        pagination_panel.addWidget(self.last_btn)
        pagination_panel.addWidget(self.stats_label)
        pagination_panel.addStretch(1)
        main_layout.addLayout(pagination_panel, stretch=0)
        
        main_layout.addWidget(buttons, stretch=0)
        
        self.setLayout(main_layout)
        
        self.show_students(students)
    
    def change_per_page(self):
        text = self.per_page_input.text().strip()
        try:
            per_page = int(text)
            if per_page < 1:
                raise ValueError("Количество записей должно быть положительным")
            self.last_valid_per_page = per_page
            if hasattr(self, 'model') and self.model:
                self.model.set_per_page(per_page)
                self.table_view.reset()
                self.update_page_info()
        except ValueError:
            QMessageBox.warning(self, "Ошибка", "Введите положительное целое число (например, 10)")
            self.per_page_input.setText(str(self.last_valid_per_page))
    
    def apply_changes(self):
        self.change_per_page()  # Применить изменения per_page
        self.table_view.reset()
        self.update_page_info()
    
    
    
    def show_students(self, students):
        per_page = self.last_valid_per_page
        try:
            per_page = int(self.per_page_input.text().strip())
            if per_page < 1:
                per_page = self.last_valid_per_page
        except ValueError:
            per_page = self.last_valid_per_page
        self.per_page_input.setText(str(per_page))
        self.last_valid_per_page = per_page
        self.model = StudentTableModel(students, page=1, per_page=per_page)
        self.table_view.setModel(self.model)
        self.table_view.reset()
        self.update_page_info()
    
    def first_page(self):
        if hasattr(self, 'model') and self.model:
            self.model.set_page(1)
            self.table_view.reset()
            self.update_page_info()
    
    def prev_page(self):
        if hasattr(self, 'model') and self.model and self.model.page > 1:
            self.model.set_page(self.model.page - 1)
            self.table_view.reset()
            self.update_page_info()
    
    def next_page(self):
        if hasattr(self, 'model') and self.model and self.model.page < self.model.total_pages():
            self.model.set_page(self.model.page + 1)
            self.table_view.reset()
            self.update_page_info()
    
    def last_page(self):
        if hasattr(self, 'model') and self.model:
            self.model.set_page(self.model.total_pages())
            self.table_view.reset()
            self.update_page_info()
    
    def update_page_info(self):
        if hasattr(self, 'model') and self.model and self.model.all_students:
            total_pages = self.model.total_pages()
            total_records = len(self.model.all_students)
            per_page = self.model.per_page
            start = (self.model.page - 1) * per_page + 1
            end = min(self.model.page * per_page, total_records)
            self.page_label.setText(f"Страница {self.model.page} из {total_pages}")
            self.stats_label.setText(f"Записи {start}-{end} из {total_records}")
            self.first_btn.setEnabled(self.model.page > 1)
            self.prev_btn.setEnabled(self.model.page > 1)
            self.next_btn.setEnabled(self.model.page < total_pages)
            self.last_btn.setEnabled(self.model.page < total_pages)
        else:
            self.page_label.setText("Страница 0 из 0")
            self.stats_label.setText("Записи 0-0 из 0")
            self.first_btn.setEnabled(False)
            self.prev_btn.setEnabled(False)
            self.next_btn.setEnabled(False)
            self.last_btn.setEnabled(False)
    
    def get_selected_students(self):
        return self.model.all_students if hasattr(self, 'model') else []

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
            # Преобразуем результаты поиска в объекты Student
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

class DeleteDialog(QDialog):
    def __init__(self, criterion, values):
        super().__init__()
        self.setWindowTitle("Удаление студента")
        self.setFixedWidth(300)
        
        self.criterion = criterion
        self.delete_input = QLineEdit()
        self.delete_input.setPlaceholderText("Введите запрос")
        self.delete_input.setStyleSheet("QLineEdit { padding: 5px; border: 1px solid #ddd; border-radius: 4px; }")
        
        self.values_combo = QComboBox()
        self.values_combo.setStyleSheet("QComboBox { padding: 5px; border: 1px solid #ddd; border-radius: 4px; }")
        self.values_combo.addItem("Выберите значение")
        self.values_combo.addItems(values)
        self.values_combo.currentTextChanged.connect(self.on_combo_changed)
        
        buttons = QDialogButtonBox(QDialogButtonBox.Ok | QDialogButtonBox.Cancel)
        buttons.accepted.connect(self.accept)
        buttons.rejected.connect(self.reject)
        
        layout = QVBoxLayout()
        layout.setSpacing(10)
        layout.setContentsMargins(10, 10, 10, 10)
        layout.addWidget(QLabel(f"Критерий: {criterion}"))
        if criterion in ["Язык программирования", "Количество выполненных работ", "Общее число работ"] and values:
            layout.addWidget(self.values_combo)
        layout.addWidget(self.delete_input)
        layout.addWidget(buttons)
        
        self.setLayout(layout)
    
    def on_combo_changed(self, text):
        if text != "Выберите значение":
            self.delete_input.setText(text)
    
    def get_delete_text(self):
        return self.delete_input.text().strip()

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