#include <string>
#include <iostream>
#include "config.h"
#include <sqlite3.h>

#include "callback.hpp"

using namespace std;


int listKeys() {

    sqlite3 *db;
    sqlite3_stmt * stmt;
    char* zErrMsg = 0;
    int rc;

    rc = sqlite3_open(keys, &db);

    string fetchKeysStatement =
        "SELECT * FROM keys;";
    rc = sqlite3_exec(db, fetchKeysStatement.c_str(), callback, 0, &zErrMsg);

    if ( rc != SQLITE_OK) {
        cout << "Error: " << zErrMsg << endl;
        sqlite3_free(zErrMsg);
    }

    cout << "\n" << rc;

    sqlite3_close(db);

    return 0;

}