cmake_minimum_required(VERSION 3.10)

project(DevStore VERSION 0.1.2)

if (WIN32)
    file(TO_CMAKE_PATH "$ENV{USERPROFILE}" USERPROFILE)
    set(devhome "${USERPROFILE}/.devstore")
    set(dbpath "${USERPROFILE}/.devstore/db")
    set(keypath "${USERPROFILE}/.devstore/db/keys.sqlite")
elseif(UNIX)
    set(devhome "$ENV{HOME}/.devstore")
    set(dbpath "$ENV{HOME}/.devstore/db")
    set(keypath "$ENV{HOME}/.devstore/db/keys.sqlite")
endif()

execute_process(
    COMMAND git log -1 --format=%h
    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
    OUTPUT_VARIABLE GIT_HASH
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

add_custom_target(AlwaysCheckGit COMMAND ${CMAKE_COMMAND}
    -DRUN_CHECK_GIT_VERSION=1
    -Dpre_configure_dir=${pre_configure_dir}
    -Dpost_configure_file=${post_configure_dir}
    -DGIT_HASH_CACHE=${GIT_HASH_CACHE}
    -P ${CURRENT_LIST_DIR}/CheckGit.cmake
    BYPRODUCTS ${post_configure_file}
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 

find_package(Boost 1.74.0 COMPONENTS program_options)
find_package(SQLite3)

include_directories(
    ${PROJECT_SOURCE_DIR}/src/include/
    ${PROJECT_SOURCE_DIR}/src/
    ${Boost_INCLUDE_DIRS}
    ${SQLite3_INCLUDE_DIRS}
)

configure_file(
    ${PROJECT_SOURCE_DIR}/src/config.h.in
    ${PROJECT_SOURCE_DIR}/src/config.h
)

add_executable(
    devstore
    ${PROJECT_SOURCE_DIR}/src/main.cpp
)

target_link_libraries(
    devstore
    ${SQLite3_LIBRARIES}
    Boost::program_options
)