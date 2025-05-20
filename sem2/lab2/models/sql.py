import sqlite3
from typing import List
from models.student import Student

class Database:
    def __init__(self, db_path: str = "students.db"):
        self.conn = sqlite3.connect(db_path)
        self._create_table()
    
    def __del__(self):
        self.conn.close()
    
    def _create_table(self):
        cursor = self.conn.cursor()
        cursor.execute("""
        CREATE TABLE IF NOT EXISTS students (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            full_name TEXT NOT NULL,
            course INTEGER NOT NULL,
            group_number TEXT NOT NULL,
            total_works INTEGER NOT NULL,
            completed_works INTEGER NOT NULL,
            programming_language TEXT NOT NULL
        )
        """)
        self.conn.commit()
    
    def add_student(self, student: Student) -> int:
        cursor = self.conn.cursor()
        cursor.execute("""
        INSERT INTO students 
        (full_name, course, group_number, total_works, completed_works, programming_language)
        VALUES (?, ?, ?, ?, ?, ?)
        """, (
            student.full_name,
            student.course,
            student.group_number,
            student.total_works,
            student.completed_works,
            student.programming_language
        ))
        self.conn.commit()
        return cursor.lastrowid
    
    def get_all_students(self) -> List[Student]:
        cursor = self.conn.cursor()
        cursor.execute("SELECT * FROM students")
        rows = cursor.fetchall()
        return [self._row_to_student(row) for row in rows]
    
    def search_student(self, filt: str, value: str) -> List[Student]:
        cursor = self.conn.cursor()
        query = "SELECT * FROM students WHERE "
        params = []
        
        if filt == "ФИО студента":
            query += "full_name LIKE ?"
            params.append(f"%{value}%")
        elif filt == "Курс":
            query += "course = ?"
            try:
                params.append(int(value))
            except ValueError:
                return []
        elif filt == "Группа":
            query += "group_number LIKE ?"
            params.append(f"%{value}%")
        elif filt == "Язык программирования":
            query += "programming_language = ?"
            params.append(value)
        elif filt == "Количество выполненных работ":
            query += "completed_works = ?"
            try:
                params.append(int(value))
            except ValueError:
                return []
        elif filt == "Общее число работ":
            query += "total_works = ?"
            try:
                params.append(int(value))
            except ValueError:
                return []
        else:
            return []
        
        cursor.execute(query, params)
        rows = cursor.fetchall()
        return [self._row_to_student(row) for row in rows]
    
    def delete_student(self, filt: str, value: str) -> int:
        cursor = self.conn.cursor()
        query = "DELETE FROM students WHERE "
        params = []
        
        if filt == "ФИО студента":
            query += "full_name LIKE ?"
            params.append(f"%{value}%")
        elif filt == "Курс":
            query += "course = ?"
            try:
                params.append(int(value))
            except ValueError:
                return 0
        elif filt == "Группа":
            query += "group_number LIKE ?"
            params.append(f"%{value}%")
        elif filt == "Язык программирования":
            query += "programming_language = ?"
            params.append(value)
        elif filt == "Количество выполненных работ":
            query += "completed_works = ?"
            try:
                params.append(int(value))
            except ValueError:
                return 0
        elif filt == "Общее число работ":
            query += "total_works = ?"
            try:
                params.append(int(value))
            except ValueError:
                return 0
        else:
            return 0
        
        cursor.execute(query, params)
        deleted_count = cursor.rowcount
        self.conn.commit()
        return deleted_count
    
    def _row_to_student(self, row: tuple) -> Student:
        return Student(
            full_name=row[1],
            course=row[2],
            group_number=row[3],
            total_works=row[4],
            completed_works=row[5],
            programming_language=row[6]
        )