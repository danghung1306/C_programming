CFLAGS := -I
CC := g++
CC_OPT := -c -g -fpic

DYNAMIC_LIB_OPT := -shared

DYNAMIC_LIB_DEPENDENT := $(OUTPUT_PATH)/reader.o

POJECT_DIR := .

INCLUDE_LIB_DIR := $(POJECT_DIR)/lib/include
SRC_LIB_DIR := $(POJECT_DIR)/lib/src

SRC := $(POJECT_DIR)/src

OUTPUT_PATH := $(POJECT_DIR)/output


build :
	$(MAKE) build -C ./lib
	$(MAKE) build -C ./src

link: build libfoo.so $(OUTPUT_PATH)/main.o
	$(CC) $(OUTPUT_PATH)/main.o -o main libfoo.so
	@LD_LIBRARY_PATH=$(OUTPUT_PATH):
	@export LD_LIBRARY_PATH


all: link
	./main.exe


clean :
	@rm -f $(OUTPUT_PATH)/*.*
	@rm -f *.exe *.so
	@echo "All objects have been removed "