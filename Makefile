ifeq ($(OS),Windows_NT)
	OUT_FILE = devstore.exe
	BOOST_INC = C:\boost\include\boost-1_80
	BOOST_LIB = C:\boost\lib
else
	OUT_FILE = devstore
endif

CC = gcc
CPP = g++
INC_DIR = ./src/include
LIB_DIR = ./src/libs
SRC_DIR = ./src
OUT_DIR = ./build
STD = c++17

ifeq ($(OS),Windows_NT)
	COMPILE = $(CPP) -std=$(STD) -static $(SRC_DIR)/devstore.cpp \
	 $(LIB_DIR)/sqlite3.o -o $(OUT_DIR)/$(OUT_FILE) \
	 -I$(BOOST_INC) -I$(INC_DIR) -L$(BOOST_LIB) \
	 -lboost_program_options-mgw12-mt-x64-1_80

else
	OUT_FILE = devstore
endif

compile:
	$(COMPILE)

compile-libs:
	$(CC) $(CFLAGS) -c $(INC_DIR)/sqlite3.c -o $(LIB_DIR)/sqlite3.o

install-linux:
	mkdir ~/.devstore
	git clone https://abdulhani.com/git//DevStore.git ~/.devstore
	cd ~/.devstore
	make compile
	mkdir ~/.devstore/bin
	mv $(OUT_DIR)/$(OUT_FILE) ~/.devstore/bin/$(OUT_FILE)
	@echo "You need to add ~/.devstore/bin to PATH if you haven't already."

