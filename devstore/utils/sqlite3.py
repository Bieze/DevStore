import sqlite3


class Database(object):
    """Sqlite3 database class"""
    DB_PATH = "./data/devstore.db"
    BUILD_PATH = "./data/devstore.sql"

    def __init__(self):
        self.__dbcon = sqlite3.connect(self.DB_PATH)
        self.__dbcur = self.__dbcon.cursor()
        with open(self.BUILD_PATH, 'r') as BUILD_FILE:
            BUILD_FILE = BUILD_FILE.read()
        self.__dbcur.executescript(BUILD_FILE)

    def close(self):
        self.__dbcon.close()

    def execute(self, data):
        self.__dbcur.execute(data)

    def commit(self):
        self.__dbcon.commit()

    def __enter__(self):
        return self

    def __exit__(self, ext_type, exc_value, traceback):
        self.__dbcur.close()
        if isinstance(exc_value, Exception):
            self.connection.rollback()
        else:
            self.__dbcon.commit()
        self.__dbcon.close()
