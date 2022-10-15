#include <iostream>
#include <string>
#include "config.h"
#include <sqlite3.h>
#include "callback.hpp"


using namespace std;

int delKey(string path) {
    sqlite3 *db;
    sqlite3_stmt * stmt;
    char* zErrMsg = 0;
    int rc;

    rc = sqlite3_open(keys, &db);

    cout << path;
    string delKeyStatement = 
        "DELETE FROM keys WHERE Path = "
        + string("'") + path + string("';");
    rc = sqlite3_exec(db, delKeyStatement.c_str(), callback, 0, &zErrMsg);

    if ( rc !=SQLITE_OK ) {
        cout << "Error: " << zErrMsg << endl;
        sqlite3_free(zErrMsg);
    } else {
        cout << "Deleted file from database: " << path << endl;
    }

    sqlite3_close(db);
    return 0;

}