from PyQt5.QtWidgets import QApplication, QDialog
from controllers.main_controller import MainController
from models.model_factory import ModelsFactory
from application.database_selector import DatabaseSelectionDialog
import sys

class StudentApplication:
    def __init__(self):
        self.app = QApplication(sys.argv)
        self._setup_application()
    
    def _setup_application(self):
        db_dialog = DatabaseSelectionDialog()
        if db_dialog.exec_() == QDialog.Accepted:
            db_type = db_dialog.get_selected_db_type()
            self._run_application(db_type)
    
    def _run_application(self, db_type: str):
        config = {
            'storage_type': db_type,
            'db_path': 'students.db',
            'xml_path': 'students.xml'
        }

        repository = ModelsFactory.create_repository(config)

        controller = MainController(repository)
        
        controller.view.show()
        sys.exit(self.app.exec_())

def run():
    StudentApplication()._setup_application()

if __name__ == "__main__":
    run()