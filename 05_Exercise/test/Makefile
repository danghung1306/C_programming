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

$(OUTPUT_PATH)/reader.o : $(SRC_LIB_DIR)/reader.cpp $(INCLUDE_LIB_DIR)/reader.h
	@echo "Compile reader.cpp to objects file"
	@$(CC) $(CC_OPT) $(SRC_LIB_DIR)/reader.cpp $(CFLAGS)$(INCLUDE_LIB_DIR) -o $(OUTPUT_PATH)/reader.o

$(OUTPUT_PATH)/child_reader.o : $(SRC_LIB_DIR)/child_reader.cpp $(INCLUDE_LIB_DIR)/child_reader.h
	@echo "Compile child_reader.cpp to objects file"
	@$(CC) $(CC_OPT) $(SRC_LIB_DIR)/child_reader.cpp $(CFLAGS)$(INCLUDE_LIB_DIR) -o $(OUTPUT_PATH)/child_reader.o

$(OUTPUT_PATH)/adults_reader.o : $(SRC_LIB_DIR)/adults_reader.cpp $(INCLUDE_LIB_DIR)/adults_reader.h
	@echo "Compile adults_reader.cpp to objects file"
	@$(CC) $(CC_OPT) $(SRC_LIB_DIR)/adults_reader.cpp $(CFLAGS)$(INCLUDE_LIB_DIR) -o $(OUTPUT_PATH)/adults_reader.o

$(OUTPUT_PATH)/libForm.o : $(SRC_LIB_DIR)/libForm.cpp $(INCLUDE_LIB_DIR)/libForm.h
	@echo "Compile libForm.cpp to objects file"
	@$(CC) $(CC_OPT) $(SRC_LIB_DIR)/libForm.cpp $(CFLAGS)$(INCLUDE_LIB_DIR) -o $(OUTPUT_PATH)/libForm.o

libfoo.so : $(OUTPUT_PATH)/reader.o $(OUTPUT_PATH)/child_reader.o $(OUTPUT_PATH)/adults_reader.o $(OUTPUT_PATH)/libForm.o
	@echo "Link objects file"
	@$(CC) $(DYNAMIC_LIB_OPT) $(OUTPUT_PATH)/reader.o $(OUTPUT_PATH)/child_reader.o $(OUTPUT_PATH)/adults_reader.o $(OUTPUT_PATH)/libForm.o -o libfoo.so


build : $(SRC)/main.cpp $(INCLUDE_LIB_DIR)/libForm.h
	$(CC) $(SRC)/main.cpp -c -o $(SRC)/main.o -I$(INCLUDE_LIB_DIR)


all : $(SRC)/main.o libfoo.so
	$(CC) $(SRC)/main.o -o main libfoo.so


static_b: $(OUTPUT_PATH)/reader.o $(OUTPUT_PATH)/child_reader.o $(OUTPUT_PATH)/adults_reader.o $(OUTPUT_PATH)/libForm.o
	ar cvr libfoo.a $(OUTPUT_PATH)/reader.o $(OUTPUT_PATH)/child_reader.o $(OUTPUT_PATH)/adults_reader.o $(OUTPUT_PATH)/libForm.o


clean :
	@rm -f $(OUTPUT_PATH)/*.*
	@echo "All objects have been removed "
	@rm -f *.exe