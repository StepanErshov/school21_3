CC=gcc
CFLAGS=-Wall -Wextra -Werror
BUILD_DIR= ../build/
EXECUTABLE=$(BUILD_DIR)/Quest_1
SOURCES=s21_string.c s21_string_test.c
OBJECTS=$(SOURCES:.c=.o)

all: dmanager_module list_tests stack_tests
dmanager_module: dmanager_module.o
	$(CC) $(CFLAGS) $(BUILD_DIR)dmanager_module.o -D quest1 -o $(BUILD_DIR)Quest_1
list_tests: list.o
	$(CC) $(CFLAGS) $(BUILD_DIR)list.o list_test.c -D quest2 -o $(BUILD_DIR)Quest_2
stack_tests: stack.o stack_test.o
	$(CC) $(CFLAGS) $(BUILD_DIR)stack.o stack_test.c -D quest3 -o $(BUILD_DIR)Quest_3
list.o: list.c list.h
	$(CC) $(CFLAGS) -c list.c  -o $(BUILD_DIR)list.o
stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c stack.c -o $(BUILD_DIR)stack.o
dmanager_module.o: dmanager_module.c 
	$(CC) $(CFLAGS) -c dmanager_module.c -o $(BUILD_DIR)dmanager_module.o
clean:
	rm -f *.o $(BUILD_DIR)Quest_*
rebuild: 
	clean ../build/
