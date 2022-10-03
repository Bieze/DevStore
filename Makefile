ifeq ($(shell uname), Linux)
	OUT_FILE = program
	FILE = devstore

endif
ifeq ($(shell uname), windows32)
	OUT_FILE = program.exe
	FILE = devstore.exe
endif

CC = gcc
CPP = g++
INC_DIR = ./src/include
LIB_DIR = ./src/libs
SRC_DIR = ./src
OUT_DIR = ./build
CPPFLAGS= -std=c++17 -static $(SRC_DIR)/devstore.cpp $(LIB_DIR)/sqlite3.o -o $(OUT_DIR)/$(OUT_FILE) -I$(INC_DIR)
CFLAGS = -c $(INC_DIR)/sqlite3.c -o $(LIB_DIR)/sqlite3.o

compile:
	$(CC) $(CFLAGS) && $(CPP) $(CPPFLAGS)

install:
	ifeq ($(shell uname), windows32)
		@echo "Please use the Windows installer instead."
	else
		git clone https://abdulhani.com/git//DevStore.git ~/.devstore
		mkdir ~/.devstore/bin
		mv build/$(OUT_FILE) ~/.devstore/bin/$(FILE)
	endif

	@echo "You need to add ~/.devstore/bin to PATH if you haven't already."
	@echo "The config file for devstore is at ~/.gitutils/src/include/global.h, edit it and recompile the program using `make compile` and then `make install` to apply changes."

