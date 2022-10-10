
#include <string>
#include "config.h"
#include <iostream>
#include "include/sqlite3.h"
#include "include/delKey.hpp"
#include "include/checks.hpp"
#include "include/addKey.hpp"
#include "include/listKeys.hpp"
#include <boost/program_options.hpp>

using namespace std;
namespace po = boost::program_options;

int main(int argc, char *argv[]) 
{   
    mainChecks();

    sqlite3 *db;
    sqlite3_stmt * stmt;
    char* zErrMsg = 0;
    int rc;

    rc = sqlite3_open("db/keys.sqlite", &db);
    string project_name = string(PROJECT_NAME);
    string project_ver = string(PROJECT_VER);
    string project_hash = string(GIT_HASH);

    try {
        po::options_description desc(project_name + " " + project_ver);
        desc.add_options()
            ("help,h", "Display this help message")
            ("version,v", "Display the version number")
            ("add-key", "Add a new key to the database")
            ("list-keys", "List all the keys in the database")
            ("del-key", po::value<string>()->required(), "Takes key path as an argument, it has to be the same as in the database, to find out what it is run devstore --list-keys")

        ;

        po::variables_map vm;

        po::parsed_options parsed = po::command_line_parser(argc, argv).
            options(desc).
            allow_unregistered().
            run();
        po::store(parsed, vm);
        

        if(vm.count("help") || argc == 1) {
            cout << desc << "\n";
            cout << project_name + " Project Version: " + 
                project_ver << " Git hash: " << 
                project_hash << " C++ standard: " <<
                __cplusplus << "\n";
        } else if (vm.count("version")) {
            cout << project_name + " Project Version: " + 
                project_ver << " Git hash: " << 
                project_hash << " C++ standard: " <<
                __cplusplus << "\n";
        } else if(vm.count("add-key")) {
            addKey();
        } else if(vm.count("list-keys")) { 
            listKeys(); 
        } else if(vm.count("del-key")) {
            const string keyToDel = vm["del-key"].as<std::string>();

            delKey(keyToDel);
        }
        return (0);
    }

    catch(exception& e) {
        cerr << "error: " << e.what() << "\n";
        return 1;
    }
    catch(...) {
        cerr << "Exception of unknown type!\n";
    }

} 