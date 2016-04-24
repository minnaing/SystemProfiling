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

	puts(" --- [ Benchmarking Process Creation ] --- ");

	total = 0;
	for (int i = 0; i < TIMES; i++){
		start = rdtsc();
		// ---
		pid_t pid = fork();
		if (pid == -1){
			exit(EXIT_FAILURE);
		}
		if (pid == 0){ // Child
			exit(EXIT_SUCCESS);
		} else { // Parent 
			wait(NULL);
			end = rdtsc();
			total += end - start;
			// ---
		}
		// ---
		//end = rdtsc();
		//total += end - start;
	}
	each = total  * 1.0 / TIMES ;
	printf(" Time to run %d iteration  : %ld \n", TIMES, total);
	printf(" Average Process Creation    : %f \n", each);

}