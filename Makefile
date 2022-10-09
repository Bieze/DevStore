ifeq ($(OS),Windows_NT)
	OUT_FILE = devstore.exe
	INC_DIRS = C:\boost\include\boost-1_80 -I./src/include
	LIB_DIRS = C:\boost\lib -L./src/libs
else
	OUT_FILE = devstore
endif

CC = gcc
CPP = g++
STD = c++17
INC_DIR = ./src/include
LIB_DIR = ./src/libs
SRC_DIR = ./src
OUT_DIR = ./build

ifeq ($(OS),Windows_NT)
	COMPILE = $(CPP) -std=$(STD) -static $(SRC_DIR)/devstore.cpp \
	 $(LIB_DIR)/sqlite3.o \
	 -o $(OUT_DIR)/$(OUT_FILE) \
	 -I$(INC_DIRS) -L$(LIB_DIRS) \
	 -lboost_program_options-mgw12-mt-x64-1_80
else
	...
endif

compile:
	$(COMPILE)

compile-libs:
	$(CC) -c $(INC_DIR)/sqlite3.c -o $(LIB_DIR)/sqlite3.o

install-linux:
	mkdir ~/.devstore
	git clone https://abdulhani.com/git//DevStore.git ~/.devstore
	cd ~/.devstore
	make compile
	mkdir ~/.devstore/bin
	mv $(OUT_DIR)/$(OUT_FILE) ~/.devstore/bin/$(OUT_FILE)
	@echo "You need to add ~/.devstore/bin to PATH if you haven't already."

