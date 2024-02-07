CC=gcc
SRC_DIR=../main_executable_module/
YET=../yet_another_decision_module/
MDL=../data_module/
LBS=../data_libs/
BIN_NAME=Quest_3
CFLAGS=-Wall -Wextra -Werror 
OUTDIR=../../build/
LDFLAGS=-L../data_libs/


build: main
main: main_executable_module.o data_stat.o data_io.o data_sort.o data_process.o decision.o  
	$(CC) $(CFLAGS) $(OUTDIR)main_executable_module.o $(OUTDIR)data_io.o $(OUTDIR)data_stat.o $(OUTDIR)data_sort.o $(OUTDIR)data_process.o  $(OUTDIR)decision.o -o $(OUTDIR)Quest_3 -o $(OUTDIR)Quest_5
build_with_static: main_executable_module.o data_stat.o data_io.o data_sort.o data_process.o decision.o
	$(CC) $(CFLAGS) -static main_executable_module.o data_io.o data_sort.o data_process.o decision.o -o $(OUTDIR)Quest_5 -L$(LBS)data_stat.a -ldata_stat
data_stat.a: $(LBS)data_stat.o 
	ar rcs $(LBS)data_stat.a $(LBS)data_stat.o 
main_executable_module.o: main_executable_module.c 
	$(CC) $(CFLAGS) -c main_executable_module.c -o $(OUTDIR)main_executable_module.o
decision.o: $(YET)decision.c $(YET)decision.h
	$(CC) $(CFLAGS) -c $(YET)decision.c  -o $(OUTDIR)decision.o 
data_process.o: $(MDL)data_process.c $(MDL)data_process.h
	$(CC) $(CFLAGS) -c $(MDL)data_process.c -o $(OUTDIR)data_process.o
data_sort.o: $(LBS)data_sort.c $(LBS)data_sort.h
	$(CC) $(CFLAGS) -c $(LBS)data_sort.c -o $(OUTDIR)data_sort.o
data_io.o: $(LBS)data_io.c $(LBS)data_io.h
	$(CC) $(CFLAGS) -c $(LBS)data_io.c -o $(OUTDIR)data_io.o 
data_stat.o: $(LBS)data_stat.c $(LBS)data_stat.h
	$(CC) $(CFLAGS) -c $(LBS)data_stat.c -o $(OUTDIR)data_stat.o
clean:
	rm -rf *.o $(OUTDIR)Quest_3 $(OUTDIR)Quest_5 $(LBS)*.a

rebuild: 
	clean ../../build/


