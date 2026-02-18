CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
LDFLAGS = -lm

BUILD_DIR = ../../build
DIR1 = ../data_libs
DIR2 = ../data_module
DIR3 = ../yet_another_decision_module

SRC11 = $(DIR1)/data_io.c
SRC12 = $(DIR1)/data_stat.c
SRC2 = $(DIR2)/data_process.c
SRC3 = $(DIR3)/decision.c
SRC4 = main_executable_module.c

SOURCES = $(SRC11) $(SRC12) $(SRC2) $(SRC3) $(SRC4)
SOURCES_Q4 = $(SRC11) $(SRC2) $(SRC3) $(SRC4)
SOURCES_Q5 = $(SRC11) $(SRC12) $(SRC3) $(SRC4)

OBJECTS = $(addprefix $(BUILD_DIR)/, $(notdir $(SOURCES:.c=.o)))
OBJECTS_Q4 = $(addprefix $(BUILD_DIR)/, $(notdir $(SOURCES_Q4:.c=.o)))
OBJECTS_Q5 = $(addprefix $(BUILD_DIR)/, $(notdir $(SOURCES_Q5:.c=.o)))

OBJECT12 = $(BUILD_DIR)/data_stat.o
OBJECT2 = $(BUILD_DIR)/data_process.o

Q3 = $(BUILD_DIR)/Quest_3
Q4 = $(BUILD_DIR)/Quest_4
Q5 = $(BUILD_DIR)/Quest_5

.PHONY: all clean rebuild build_with_static build_with_dynamic

all: $(BUILD_DIR) $(Q3) $(Q4) $(Q5)

$(BUILD_DIR)/data_io.o: $(DIR1)/data_io.c $(DIR1)/data_io.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/data_stat.o: $(DIR1)/data_stat.c $(DIR1)/data_stat.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/data_process.o: $(DIR2)/data_process.c $(DIR2)/data_process.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/decision.o: $(DIR3)/decision.c $(DIR3)/decision.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/main_executable_module.o: $(SRC4) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(Q3): $(OBJECTS)
	$(CC) $^ -o $@ $(LDFLAGS)



$(DIR1)/data_stat.a: $(OBJECT12)
	ar -rcs $@ $<

$(Q4): $(OBJECTS_Q4) $(DIR1)/data_stat.a
	$(CC) $(OBJECTS_Q4) -L$(DIR1) -l:data_stat.a -o $@ $(LDFLAGS)

$(DIR2)/data_process.so: $(OBJECT2) $(OBJECT12)
	$(CC) -shared -fPIC $^ -o $@

$(Q5): $(OBJECTS_Q5) $(DIR2)/data_process.so
	$(CC) $(OBJECTS_Q5) $(DIR2)/data_process.so -o $@ $(LDFLAGS)

build_with_static: clean $(DIR1)/data_stat.a $(Q4)

build_with_dynamic: clean $(DIR2)/data_process.so $(Q5)


clean:
	rm -rf $(BUILD_DIR)/*.o
	find $(DIR1) -name "*.a" -type f -delete
	find $(DIR2) -name "*.so" -type f -delete

rebuild: clean all

