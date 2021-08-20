CFLAGS := -I
CC := g++
CC_OPT := -c -g

POJECT_DIR := .

INCLUDE_DIR := $(POJECT_DIR)/include
SRC_DIR := $(POJECT_DIR)/src

OUTPUT_PATH := $(POJECT_DIR)/output

$(OUTPUT_PATH)/main.o: $(SRC_DIR)/main.cpp
	@echo "Compile main.cpp file"
	$(CC) $(CC_OPT) $(SRC_DIR)/main.cpp -o $(OUTPUT_PATH)/main.o
	@echo "Build done"


build: $(OUTPUT_PATH)/main.o
	@echo "Create executed file"
	$(CC) $(OUTPUT_PATH)/main.o -o exe
	@echo "Build done"


all: build
	./exe.exe

clean:
	rm -f $(OUTPUT_PATH)/*.*
	rm -f *.exe
	@echo "clean has been done"