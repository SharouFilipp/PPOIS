from PyQt5.QtWidgets import (
    QDialog, QTableView, QPushButton, QLineEdit, QLabel, QHBoxLayout, 
    QVBoxLayout, QSizePolicy, QHeaderView, QDialogButtonBox, QMessageBox
)
from PyQt5.QtCore import QIntValidator
from PyQt5.QtGui import QFont
from student_table_model import StudentTableModel

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
        self.apply_btn = QPushButton("Применить")
        
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
        self.change_per_page()
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