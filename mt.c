CC = gcc
CFLAGS = -c -Wall -Werror -Wextra

SRC1 = dmanager_module.c
SRC2 = list.c
SRC3 = list_test.c
SRC4 = stack.c
SRC5 = stack_test.c
SRC6 = print_module.c
SRC7 = main_module_entry_point.c


OBJ1 = $(SRC1:.c=.o)
OBJ2 = $(SRC2:.c=.o)
OBJ3 = $(SRC3:.c=.o)
OBJ4 = $(SRC4:.c=.o)
OBJ5 = $(SRC5:.c=.o)
OBJ6 = $(SRC6:.c=.o)
OBJ7 = $(SRC7:.c=.o)

BUILD = ../build

Q1 = $(BUILD)/Quest_1
Q2 = $(BUILD)/Quest_2
Q3 = $(BUILD)/Quest_3
Q4 = $(BUILD)/Quest_4

.PHONY: all clean rebuild

all: door_struct list_test stack_test print_module

door_struct: clean $(Q1)
$(Q1): $(OBJ1)
	$(CC) $^ -o $@

list_test: $(OBJ2) $(OBJ3)
	$(CC) $^ -o $(Q2)

stack_test: $(OBJ4) $(OBJ5)
	$(CC) $^ -o $(Q3)
print_module: $(OBJ6) $(OBJ7)
	$(CC) $^ -o $(Q4)




%.o: %.c
	$(CC) $(CFLAGS) $^ -o $@

clean_all:
	rm -rf *.o **/*.o
	rm 	$(BUILD)/*

clean:
	rm -rf *.o **/*.o

rebuild: clean all
