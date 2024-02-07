CC=gcc
CFLAGS=-Wall -Wextra -Werror
BUILD_DIR= ../build/
EXECUTABLE=$(BUILD_DIR)/Quest_1
SOURCES=s21_string.c s21_string_test.c
OBJECTS=$(SOURCES:.c=.o)

build: strlen_tests strcmp_test
strlen_tests: s21_string.o 
	$(CC) $(CFLAGS) $(BUILD_DIR)s21_string.o s21_string_test.c -D quest1 -o $(BUILD_DIR)Quest_1
strcmp_tests: s21_string.o
	$(CC) $(CFLAGS) $(BUILD_DIR)s21_string.o s21_string_test.c -D quest2 -o $(BUILD_DIR)Quest_2
strcpy_tests: s21_string.o
	$(CC) $(CFLAGS) $(BUILD_DIR)s21_string.o s21_string_test.c -D quest3 -o $(BUILD_DIR)Quest_3
strcat_tests: s21_string.o
	$(CC) $(CFLAGS) $(BUILD_DIR)s21_string.o s21_string_test.c -D quest4 -o $(BUILD_DIR)Quest_4
strchr_tests: s21_string.o
	$(CC) $(CFLAGS) $(BUILD_DIR)s21_string.o s21_string_test.c -D quest5 -o $(BUILD_DIR)Quest_5
strstr_tests: s21_string.o
	$(CC) $(CFLAGS) $(BUILD_DIR)s21_string.o s21_string_test.c -D quest6 -o $(BUILD_DIR)Quest_6
strtok_tests: s21_string.o
	$(CC) $(CFLAGS) $(BUILD_DIR)s21_string.o s21_string_test.c -D quest7 -o $(BUILD_DIR)Quest_7
s21_string.o: s21_string.c s21_string.h
	$(CC) $(CFLAGS) -c s21_string.c -o $(BUILD_DIR)s21_string.o 
clean:
	rm -f *.o $(BUILD_DIR)Quest_*
rebuild: 
	clean ../build/
