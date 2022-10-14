#define PROJECT_NAME "DevStore"
#define PROJECT_VER  "0.1.2"
#define PROJECT_VER_MAJOR "0"
#define PROJECT_VER_MINOR "1"
#define PROJECT_VER_PATCH "2"

/*
devhome: The home of the .devstore directory
For windows this can be C:\\Users\\user\\.devstore
For Linux and mac this can be ~/.devstore

The dbpath is the path to the database folder
For windows \\db
For Linux /db
*/

#ifndef GLOBALS_H
#define GLOBALS_H
const char *GIT_HASH = "f78939a";
inline const char *devhome = "C:/Users/abdul/.devstore";
inline const char *dbpath = "C:/Users/abdul/.devstore/db";
inline const char *keys = "C:/Users/abdul/.devstore/db/keys.sqlite";
#endif
