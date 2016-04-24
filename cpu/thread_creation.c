#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include "../include/rdtsc.c"
#include <pthread.h>

void * run_thread(){
	pthread_exit(NULL);
}

#define TIMES 1000

int main(){
	long start, end, total;
	double each;

	puts(" --- [ Benchmarking Thread Creation ] --- ");

	total = 0;
	pthread_t td;
	for (int i = 0; i < TIMES; i++){
		start = rdtsc();
		pthread_create(&td, NULL, run_thread, NULL);
		end = rdtsc();
		total += end - start;
		// pthread_join(td, NULL);
	}
	each = total  * 1.0 / TIMES ;
	printf(" Time to run %d iteration  : %ld \n", TIMES, total);
	printf(" Average Thread Creation     : %f \n", each);

}