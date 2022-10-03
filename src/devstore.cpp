#include <iostream> 
#include <algorithm>
#include "include/sqlite3.h"

using namespace std;

char* fetchCmdOption(char ** begin, char ** end, const string & option) {
    char ** itr = find(begin, end, option);
    if (itr != end && ++itr != end) {
        return *itr;
    }
    return 0;
}

bool cmdOptionExists(char ** begin, char ** end, const string& option) {
    return find(begin, end, option) != end;
}

  
int main(int argc, char * argv[]) 
{ 
    if (cmdOptionExists(argv, argv+argc, "help")) {
        cout << "DevStore v0.1.0 usage:\n";
        cout << "   help                         Print this help message.";
    }  
    
    return (0); 
} 