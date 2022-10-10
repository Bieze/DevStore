#include <string>
#include <iostream>
#include "sqlite3.h"

using namespace std;

int listKeys() {
    sqlite3 *db;
    sqlite3_stmt * stmt;
    char* zErrMsg = 0;
    int rc;

    rc = sqlite3_open("db/keys.sqlite", &db);

    if ( rc ) {
        cout << "Encountered error while opening db/keys.sqlite : " << sqlite3_errmsg(db) << "\n";
    }

    string fetchKeysStatement =
        "SELECT * FROM keys;";
    rc = sqlite3_exec(db, fetchKeysStatement.c_str(), callback, 0, &zErrMsg);
    cout << "\n" << rc;

    sqlite3_close(db);

    return 0;

}