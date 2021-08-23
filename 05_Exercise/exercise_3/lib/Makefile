CFLAGS := -I
CC := g++
CC_OPT := -c -g -fpic

DYNAMIC_LIB_OPT := -shared

DYNAMIC_LIB_DEPENDENT := $(OUTPUT_PATH)/reader.o

POJECT_DIR := .

INCLUDE_LIB_DIR := $(POJECT_DIR)/include
SRC_LIB_DIR := $(POJECT_DIR)/src

SRC := $(POJECT_DIR)/src

OUTPUT_PATH := $(POJECT_DIR)./output

reader.o : $(SRC_LIB_DIR)/reader.cpp $(INCLUDE_LIB_DIR)/reader.h
	@echo "Compile reader.cpp to objects file"
	@$(CC) $(CC_OPT) $(SRC_LIB_DIR)/reader.cpp $(CFLAGS)$(INCLUDE_LIB_DIR) -o $(OUTPUT_PATH)/reader.o

child_reader.o : $(SRC_LIB_DIR)/child_reader.cpp $(INCLUDE_LIB_DIR)/child_reader.h
	@echo "Compile child_reader.cpp to objects file"
	@$(CC) $(CC_OPT) $(SRC_LIB_DIR)/child_reader.cpp $(CFLAGS)$(INCLUDE_LIB_DIR) -o $(OUTPUT_PATH)/child_reader.o

adults_reader.o : $(SRC_LIB_DIR)/adults_reader.cpp $(INCLUDE_LIB_DIR)/adults_reader.h
	@echo "Compile adults_reader.cpp to objects file"
	@$(CC) $(CC_OPT) $(SRC_LIB_DIR)/adults_reader.cpp $(CFLAGS)$(INCLUDE_LIB_DIR) -o $(OUTPUT_PATH)/adults_reader.o

libForm.o : $(SRC_LIB_DIR)/libForm.cpp $(INCLUDE_LIB_DIR)/libForm.h
	@echo "Compile libForm.cpp to objects file"
	@$(CC) $(CC_OPT) $(SRC_LIB_DIR)/libForm.cpp $(CFLAGS)$(INCLUDE_LIB_DIR) -o $(OUTPUT_PATH)/libForm.o

libfoo.so : reader.o child_reader.o adults_reader.o libForm.o
	@echo "Link objects file"
	@$(CC) $(DYNAMIC_LIB_OPT) $(OUTPUT_PATH)/reader.o $(OUTPUT_PATH)/child_reader.o $(OUTPUT_PATH)/adults_reader.o $(OUTPUT_PATH)/libForm.o -o $(POJECT_DIR)./libfoo.so

build: libfoo.so
	@echo "Adding dynamic library into systems successfully!"

clean :
	@rm -f $(OUTPUT_PATH)/*.*
	@echo "All objects have been removed "