#include <boost/program_options.hpp>
#include "include/global.h"

using namespace std;
namespace po = boost::program_options;

#include <iostream> 
#include <algorithm>
#include "include/sqlite3.h"


int main(int ac, char* av[]) 
{   
    try {
        po::options_description desc("DevStore " + version);
        desc.add_options()
            ("help", "Display this help message")
            ("version", "Display the version number")
        ;

    
        po::variables_map vm;
        po::store(po::parse_command_line(ac, av, desc), vm);
        po::notify(vm);

        if(vm.count("help") || ac == 1) {
            cout << desc << "\n";
        } else if (vm.count("h")) {
            cout << desc << "\n";
        }

        if (vm.count("version")) {
            cout << "Version " << version << "\n";
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