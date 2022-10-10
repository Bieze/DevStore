#include "sqlite3.h"
#include <filesystem>

using namespace std;
namespace fs = filesystem;

int mainChecks() {
    if (!fs::is_directory("db") || !fs::exists("db")) {
        fs::path path("db");
        path /= "keys.sqlite";
        fs::create_directories(path.parent_path());

        sqlite3 *db;
        sqlite3_stmt * stmt;
        char* zErrMsg = 0;
        int rc;

        const string newKeys = 
            "CREATE TABLE IF NOT EXISTS keys ("
            "    name TEXT,"
            "    path TEXT PRIMARY KEY"
            "              NOT NULL,"
            "    pswd TEXT"
            ");";

        rc = sqlite3_open("db/keys.sqlite", &db);
        rc = sqlite3_exec(db, newKeys.c_str(), callback, 0, &zErrMsg);

        if ( rc !=SQLITE_OK ) {
            cout << "Error: " << zErrMsg << endl;
            sqlite3_free(zErrMsg);
        };

        sqlite3_close(db);

    }
    return 0;
}