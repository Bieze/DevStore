#ifndef callback_hpp
#define callback_hpp

#include <iostream>

using namespace std;

/* extern int callback(void *NotUsed, int argc, char **argv, char **azColName){

    // int argc: holds the number of results
    // (array) azColName: holds each column returned
    // (array) argv: holds each value

    for(int i = 0; i < argc; i++) {
        
        // Show column name, value, and newline
        cout << "============================";
        cout << azColName[i] << ": " << argv[i] << endl;
    
    }

    // Insert a newline
    cout << endl;

}; */

extern int callback(void *unused, int count, char **data, char **columns)
{
    int idx;

    cout << "=================================\n";
    for (idx = 0; idx < count; idx++) {
        printf("%s: %s\n", columns[idx], data[idx]);
    }
    cout << "=================================\n";

    return 0;
}

#endif