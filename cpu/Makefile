CC = gcc
CFLAGS = -I.
INC = ../include
BIN = ../bin

all: clean readOverhead procedureCall syscall taskCreation contextSwitch

readOverhead: readOverhead.c
	gcc readOverhead.c $(INC)/rdtsc.c -o $(BIN)/readOverhead
	nice $(BIN)/readOverhead

procedureCall: procedureCall.c
	gcc procedureCall.c $(INC)/rdtsc.c -o $(BIN)/procedureCall
	nice $(BIN)/procedureCall

syscall: syscall.c
	gcc syscall.c $(INC)/rdtsc.c -o $(BIN)/syscall
	nice $(BIN)/syscall

taskCreation: thread_creation.c process_creation.c task_creation.c
	gcc thread_creation.c $(INC)/rdtsc.c -o $(BIN)/threadCreation
	nice $(BIN)/threadCreation
	gcc process_creation.c $(INC)/rdtsc.c -o $(BIN)/processCreation
	nice $(BIN)/processCreation
	gcc task_creation.c $(INC)/rdtsc.c -o $(BIN)/taskCreation
	nice $(BIN)/taskCreation


contextSwitch: thread_contextSwitch.c process_contextSwitch.c
	gcc thread_contextSwitch.c $(INC)/rdtsc.c -o $(BIN)/thread_contextSwitch
	nice $(BIN)/thread_contextSwitch
	gcc process_contextSwitch.c $(INC)/rdtsc.c -o $(BIN)/process_contextSwitch
	nice $(BIN)/process_contextSwitch

clean:
	rm -rf $(BIN)/*