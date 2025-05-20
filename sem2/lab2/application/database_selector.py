from PyQt5.QtWidgets import QDialog, QVBoxLayout, QComboBox, QDialogButtonBox, QLabel

class DatabaseSelectionDialog(QDialog):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Выбор базы данных")
        self.setFixedWidth(300)
        self._setup_ui()
    
    def _setup_ui(self):
        layout = QVBoxLayout()
        layout.setSpacing(10)
        layout.setContentsMargins(10, 10, 10, 10)
        
        layout.addWidget(QLabel("Выберите тип базы данных:"))
        
        self.db_combo = QComboBox()
        self.db_combo.addItems(["SQLite", "XML"])
        self.db_combo.setStyleSheet("""
            QComboBox { 
                padding: 5px; 
                border: 1px solid #ddd; 
                border-radius: 4px; 
            }
        """)
        layout.addWidget(self.db_combo)
        
        buttons = QDialogButtonBox(QDialogButtonBox.Ok | QDialogButtonBox.Cancel)
        buttons.accepted.connect(self.accept)
        buttons.rejected.connect(self.reject)
        layout.addWidget(buttons)
        
        self.setLayout(layout)
    
    def get_selected_db_type(self):
        return self.db_combo.currentText().lower()  # Возвращаем в нижнем регистре