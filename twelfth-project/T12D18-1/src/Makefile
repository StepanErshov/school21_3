CC = gcc
CFLAGS = -Wall -Werror -Wextra
BUILD_DIR= ../build/


all: print_module documentation_module
print_module: print_module.o 
	$(CC) $(CFLAGS) print_module.o main_module_entry_point.o -D quest1 -o $(BUILD_DIR)Quest_1
documentation_module: documentation_module.o
	$(CC) $(CFLAGS) documentation_module.o main_module_entry_point.c -D quest2 -o  $(BUILD_DIR)Quest_2
print_module.o: print_module.c main_module_entry_point.c
	$(CC) $(CFLAGS) -c print_module.c  -o print_module.o
documentation_module.o: documentation_module.c main_module_entry_point.c
	$(CC) $(CFLAGS) -c documentation_module.c  -o documentation_module.o
main_module_entry_point.o: main_module_entry_point.c
	$(CC) $(CFLAGS) -c main_module_entry_point.c  -o main_module_entry_point.o
clean:
	rm -f *.o $(BUILD_DIR)Quest_*
rebuild: 
	clean ../build/
