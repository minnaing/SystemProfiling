#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include "../include/rdtsc.c"
#include <pthread.h>
	
int pipefd[2];
	
void * run_thread(){
	long end;
	end = rdtsc();
	write(pipefd[1], &end, sizeof(end));
	pthread_exit(NULL);
}

#define TIMES 1000

int main(){
	long start, end, total;
	double each;
		
	puts(" --- [ Benchmarking Context Switch between Thread ] --- ");

	total = 0;
	pthread_t td;
	pipe(pipefd);

	for (int i = 0; i < TIMES; i++){
		pthread_create(&td, NULL, run_thread, NULL);
		start = rdtsc();
		read(pipefd[0], &end, sizeof(end));
		total += end - start;
		pthread_join(td, NULL);
	}
	each = total  * 1.0 / TIMES ;
	printf(" Time to run %d iteration  : %ld \n", TIMES, total);
	printf(" Average Context Switch     : %f \n", each);

}