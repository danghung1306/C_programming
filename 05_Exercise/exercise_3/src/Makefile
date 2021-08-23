CFLAGS := -I
CC := g++
CC_OPT := -c -g -fpic

DYNAMIC_LIB_OPT := -shared

POJECT_DIR := .

INCLUDE_LIB_DIR := $(POJECT_DIR)./lib/include
SRC_LIB_DIR := $(POJECT_DIR)./lib/src

SRC := $(POJECT_DIR)

OUTPUT_PATH := $(POJECT_DIR)./output

build : $(SRC)/main.cpp $(INCLUDE_LIB_DIR)/libForm.h
	@echo "Build main.cpp to objects file"
	@$(CC) $(SRC)/main.cpp -c -I$(INCLUDE_LIB_DIR) -o $(OUTPUT_PATH)/main.o
	@echo "Build done!"


clean :
	@rm -f $(OUTPUT_PATH)/main.o
	@echo "All objects have been removed"