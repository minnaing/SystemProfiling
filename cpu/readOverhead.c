#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include "../include/rdtsc.c"

#define TIMES 1000

int main(){
	long start, end, total;
	double each;
	puts(" --- [ Benchmarking Mesaurement Overhead ] --- ");

	puts(" - Benchmarking Read Overhead ");
	
	total = 0;
	for (int i = 0; i < TIMES; i++){
		start = rdtsc();
		end = rdtsc();
		total += end - start;
	}
	each = total  * 1.0 / TIMES ;
	printf(" Time to run %d iteration  : %ld \n", TIMES, total);
	printf(" Average ReadOverhead        : %f \n", each);


	puts(" - Benchmarking Loop Overhead ");

	total = 0;
	start = rdtsc();
	for (int i = 0; i < TIMES; i++){
		// do nothing	
	}
	end = rdtsc();
	total += end - start;
	each = total  * 1.0 / TIMES ;
	printf(" Time to run %d iteration  : %ld \n", TIMES, total);
	printf(" Average LoopOverhead        : %f \n", each);
}
