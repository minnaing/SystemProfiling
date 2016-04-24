#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include "../include/rdtsc.c"

#define TIMES 1000

int main(){
	long start, end, total;
	double each;
	total = 0;

	puts(" --- [ Benchmarking Syscall ] --- ");

	total = 0;
	for (int i = 0; i < TIMES; i++){
		start = rdtsc();
		getpid();
		end = rdtsc();
		total += end - start;
	}
	each = total  * 1.0 / TIMES ;
	printf(" Time to run %d iteration  : %ld \n", TIMES, total);
	printf(" Average SyscallOverhead        : %f \n", each);

}

