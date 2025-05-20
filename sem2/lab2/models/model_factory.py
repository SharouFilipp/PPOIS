
from models.xml import XMLDatabase
from models.sql import Database

class ModelsFactory:
    @staticmethod
    def create_repository(config):
        if config['storage_type'] == 'sqlite':
            return Database(config['db_path'])
        elif config['storage_type'] == 'xml':
            return XMLDatabase(config['xml_path'])
        raise ValueError("Unsupported storage type")