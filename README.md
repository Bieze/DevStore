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


Get boost from:
    https://www.boost.org/

* Note For Windows users only:
    Because of the limited abilities of the cmake project finder,
    you'll need to follow this [guide](https://gist.github.com/zrsmithson/0b72e0cb58d0cb946fc48b5c88511da8) to compile boost for Windows. Once finished, you'll have to grab the required libraries (only program_options) from C:\boost\lib, You'll have to copy the file named `libboost_program_options-mgw12-mt-s-x64-1_80.a` over to C:\mingw64\lib and rename it to `libboost_program_options-mgw12-mt-d-1_80.a`, after that you'll have to copy the directory
    named `C:\boost\include\boost-1_80\boost` to C:\mingw64\include\c++\12.1.0\boost, and finally,
    create a directory in C:\mingw64\lib\boost and download [BoostConfig.cmake](https://github.com/boostorg/boost_install/raw/develop/BoostConfig.cmake) to it.
    


## How to compile sqlite3

```bash
gcc -c ./src/include/sqlite3.c -o ./src/libs/sqlite3.o
```

## How to compile the full program

```bash
# Compile sqlite3 if you haven't already.

mkdir build && cd build
cmake ..
make
```

## Contributing
[Pull requests](https://github.com/abdulh4ni/DevStore/pulls) are welcome. For major changes, please open an [issue first](https://github.com/abdulh4ni/DevStore/issues) to discuss what you would like to change.

## License
[GPL v3](https://www.gnu.org/licenses/gpl-3.0.en.html)