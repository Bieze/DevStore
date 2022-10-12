#include "sqlite3.h"
#include "config.h"
#include <filesystem>
#include <iostream>
#include "callback.hpp"
#include <sys/types.h>
#include <sys/stat.h>
#include <fstream>


using namespace std;
namespace fs = filesystem;

struct stat info;


int mainChecks() {

    if( stat( devhome, &info) != 0) {
        fs::create_directory(devhome);
        fs::create_directory(dbpath);
        
        ofstream file;
        char name[81];
        file.open(dbpath);
        file.close();
    }

    sqlite3 *db;
    sqlite3_stmt * stmt;
    char* zErrMsg = 0;
    int rc;

    const string newKeys = 
            "CREATE TABLE IF NOT EXISTS keys ("
            "    Key TEXT,"
            "    Path TEXT PRIMARY KEY"
            "              NOT NULL,"
            "    Password TEXT"
            ");";

    rc = sqlite3_open(keys, &db);
    rc = sqlite3_exec(db, newKeys.c_str(), callback, 0, &zErrMsg);

    if ( rc !=SQLITE_OK ) {
        cout << "Error: " << zErrMsg << endl;
        sqlite3_free(zErrMsg);
    };

    sqlite3_close(db);


    return 0;
}