@ECHO OFF

CFLAGS := -I
CC := g++
CC_OPT := -c -g

POJECT_DIR := .

INCLUDE_DIR := $(POJECT_DIR)/include
SRC_DIR := $(POJECT_DIR)/src

OUTPUT_PATH := $(POJECT_DIR)/output

$(OUTPUT_PATH)/main.o: ./src/main.cpp
	$(CC) -c $(SRC_DIR)/main.cpp -o $(OUTPUT_PATH)/main.o $(CFLAGS)$(INCLUDE_DIR)

all: $(OUTPUT_PATH)/main.o
	g++ $(OUTPUT_PATH)/main.o -o exe

clean:
	rm -f $(OUTPUT_PATH)/*.*
	@echo "clean has been done"
