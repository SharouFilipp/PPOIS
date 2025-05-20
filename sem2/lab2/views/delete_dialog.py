from PyQt5.QtWidgets import QDialog, QLineEdit, QComboBox, QLabel, QVBoxLayout, QDialogButtonBox

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