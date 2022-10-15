# DevStore.git

A small utility program for programmers.

| Support   | Answer    | When will it get support |
| :---      | :----:    |           ---:           |
| Linux     | ✔️        | v0.1.1                   |
| Windows   | ✔️        | v0.1.0                   |
| BSD Family| ✔️        | v0.1.1                   |


## Dependencies
| Name          | Version   | Platforms  | Other versions supported |
| :---          | :----     | ----:      |                  ---:    |
| Boost         | 1.80.0    | All        | Unknown                  |
| MinGW64 or 32 | 10.0.0    | Windows    | Unknown                  |


## Boost installation

### Windows
Get boost from:
    https://www.boost.org/

* Note For Windows users only:
    Because of the limited abilities of the cmake project finder,
    you'll need to follow this [guide](https://gist.github.com/zrsmithson/0b72e0cb58d0cb946fc48b5c88511da8) to compile boost for Windows. Once finished, you'll have to grab the required libraries (only program_options) from C:\boost\lib, You'll have to copy the file named `libboost_program_options-mgw12-mt-s-x64-1_80.a` over to C:\mingw64\lib and rename it to `libboost_program_options-mgw12-mt-d-1_80.a`, after that you'll have to copy the directory
    named `C:\boost\include\boost-1_80\boost` to C:\mingw64\include\c++\12.1.0\boost, and finally,
    create a directory in C:\mingw64\lib\boost and download [BoostConfig.cmake](https://github.com/boostorg/boost_install/raw/develop/BoostConfig.cmake) to it.

### Debian, Arch and Fedora and their derivatives
```bash
# Arch Linux and derivatives
pacman -S boost

# Debian and derivatives
apt-get install libboost-all-dev

# Fedora and derivatives
yum install boost
yum install boost-devel
```

## How to compile the full program

* For the stable version

```bash
git clone https://abdulhani.com/git/DevStore.git
cd DevStore

mkdir build && cd build

# Linux
cmake ..

# Windows
cmake .. -G "MinGW Makefiles"

make
```

* For the latest (Might not compile)

```bash
git clone https://abdulhani.com/git/DevStore.git
cd DevStore
git checkout devel

mkdir build && cd build

# Linux
cmake ..

# Windows
cmake .. -G "MinGW Makefiles"

make
```


## Usage and help
DevStore:
  -h [ --help ]         Display this help message
  -v [ --version ]      Display the version number
  --add-key             Add a new key to the database
  --list-keys           List all the keys in the database
  --del-key arg         Takes key path as an argument, it has to be the same as
                        in the database, to find out what it is run devstore
                        --list-keys

```bash
# Help command
Abdul ~> devstore
DevStore 0.1.1:
  -h [ --help ]         Display this help message
  -v [ --version ]      Display the version number
  --add-key             Add a new key to the database
  --list-keys           List all the keys in the database
  --del-key arg         Takes key path as an argument, it has to be the same as
                        in the database, to find out what it is run devstore
                        --list-keys

DevStore Project Version: 0.1.1 Git hash: decdf98 C++ standard: 201703

# Add a key
devstore --add-key # This will ask you some questions so no need to add arguments in the command line.

# List all the keys
devstore --list-keys

# Delete a key from the database
devstore --del-key [key-path] # The key path is the same as what's written in when you run --list-keys.
```


## Ideas I might add
| Idea              | Usage                             | Will I add it ?       |
| :---              | :----:                            |   ---:                |
| Python installer  | Installs latest version of Python | No                    |
| .NET Components   | Fetches .NET version              | Unsure                |


## Contributing
[Pull requests](https://github.com/abdulh4ni/DevStore/pulls) are welcome. For major changes, please open an [issue first](https://github.com/abdulh4ni/DevStore/issues) to discuss what you would like to change.

## License
[GPL v3](https://www.gnu.org/licenses/gpl-3.0.en.html)