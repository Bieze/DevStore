#include <string>
#include <cctype>
#include <iostream>
#include "sqlite3.h"
#include "config.h"

using namespace std;

int addKey() {


    sqlite3 *db;
    sqlite3_stmt * stmt;
    char* zErrMsg = 0;
    int rc;

    rc = sqlite3_open(keys, &db);

    if ( rc ) {
        cout << "Encountered error while opening db/keys.sqlite : " << sqlite3_errmsg(db) << "\n";
    }

    string name;
    string path;
    string password;
    char answer;
    int i = 0;

    while(i < 2) {
        cout << ">>> DevStore add-key\n";
        cout << "Arguments required: name, path, password\n";
        cout << "TIP: You can leave the password blank if you want to\n";
        cout << "Keyfile nickname: ";
        cin >> name;
        cout << "Keyfile path: ";
        cin >> path;
        cout << "Enter password: ";
        cin >> password;

        cout << "====================================";
        cout << "\nKeyfile nickname: " << name << "\n";
        cout << "Keyfile Path: " << path << "\n";
        cout << "Keyfile password: " << password << "\n";

        cout << "====================================";
        cout << "\nIs this correct? [y/n] ";
        cin >> answer;

        if (toupper(answer) == 'Y' ) {
            string addKeyStatement = 
                "INSERT INTO keys (Key, Path, Password) VALUES("
                + string("'") + name + string("',")
                + string("'") + path + string("',")
                + string("'") + password + string("');");
            rc = sqlite3_exec(db, addKeyStatement.c_str(), callback, 0, &zErrMsg);
            if ( rc != SQLITE_OK) {
                cout << "Error: " << zErrMsg << endl;
                sqlite3_free(zErrMsg);
            } else {
                cout << "Added key to database.";
            }
            i = 3;
        } else {
            i = 0;
        }
        

    }

    sqlite3_close(db);

    return 0;
}