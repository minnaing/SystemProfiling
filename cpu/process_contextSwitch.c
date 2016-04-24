#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include "../include/rdtsc.c"
#include <pthread.h>

int pipefd[2];


#define TIMES 1000

int main(){
	long start, end, total;
	double each;
		
	puts(" --- [ Benchmarking Context Switch between Process ] --- ");

	total = 0;
	for (int i = 0; i < TIMES; i++){
		//start = rdtsc();
		// ---
		pipe(pipefd);
		pid_t pid = fork();
		if (pid == -1){
			exit(EXIT_FAILURE);
		}
		if (pid == 0){ // Child
			end = rdtsc();
			write(pipefd[1], &end, sizeof(end));
			exit(1); // return 0; //
		} else { // Parent 
			start = rdtsc();
			read(pipefd[0], &end, sizeof(end));
			total += end - start;

			wait(NULL);
			
			// ---
		}
		// ---
		//end = rdtsc();
		//total += end - start;
	}
	each = total  * 1.0 / TIMES ;
	printf(" Time to run %d iteration  : %ld \n", TIMES, total);
	printf(" Average Context Switch     : %f \n", each);

}