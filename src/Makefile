CC = gcc
CFLAGS = -Wall -Werror -Wextra
BUILD = ../build/

all: state_sort state_search clear_state
state_sort: state_sort.o
	$(CC) $(CFLAGS) state_sort.o -o $(BUILD)Quest_1

state_search: state_search.o
	$(CC) $(CFLAGS) state_search.o -o $(BUILD)Quest_2
clear_state: clear_state.o
	$(CC) $(CFLAGS) clear_state.o -o $(BUILD)Quest_3

state_sort.o: state_sort.c 
	$(CC) $(CFLAGS) -c state_sort.c -o state_sort.o

state_search.o: state_search.c
	$(CC) $(CFLAGS) -c state_search.c -o state_search.o

clear_state.o: clear_state.c
	$(CC) $(CFLAGS) -c clear_state.c -o clear_state.o

clean:
	rm -f *.o $(BUILD)Quest_*

rebuild:
	all clean