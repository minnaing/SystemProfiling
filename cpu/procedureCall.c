#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include "../include/rdtsc.c"

int test0(){ return 0; }
int test1(int a1){ return 0; }
int test2(int a1, int a2){ return 0; }
int test3(int a1, int a2, int a3){ return 0; }
int test4(int a1, int a2, int a3, int a4){ return 0; }
int test5(int a1, int a2, int a3, int a4, int a5){ return 0; }
int test6(int a1, int a2, int a3, int a4, int a5, int a6){ return 0; }
int test7(int a1, int a2, int a3, int a4, int a5, int a6, int a7){ return 0; }

#define TIMES 1000

int main(){
	long start, end, total;
	double each;
	long record[8];
	puts(" --- [ Benchmarking Procedure Call ] --- ");

	total = 0;
	puts(" - Running with 0 argument");
	for (int i = 0; i < TIMES; i++){
		start = rdtsc();
		test0();
		end = rdtsc();
		total += end - start;
	}
	each = total  * 1.0 / TIMES ;
	printf(" Time to run %d iteration  : %ld \n", TIMES, total);
	printf(" Average ReadOverhead        : %f \n", each);
	record[0] = each;


	total = 0;
	puts(" - Running with 1 argument");
	for (int i = 0; i < TIMES; i++){
		start = rdtsc();
		test1(0);
		end = rdtsc();
		total += end - start;
	}
	each = total  * 1.0 / TIMES ;
	printf(" Time to run %d iteration  : %ld \n", TIMES, total);
	printf(" Average ReadOverhead        : %f \n", each);
	record[1] = each;


	total = 0;
	puts(" - Running with 2 argument");
	for (int i = 0; i < TIMES; i++){
		start = rdtsc();
		test2(0, 0);
		end = rdtsc();
		total += end - start;
	}
	each = total  * 1.0 / TIMES ;
	printf(" Time to run %d iteration  : %ld \n", TIMES, total);
	printf(" Average ReadOverhead        : %f \n", each);
	record[2] = each;


	total = 0;
	puts(" - Running with 3 argument");
	for (int i = 0; i < TIMES; i++){
		start = rdtsc();
		test3(0, 0, 0);
		end = rdtsc();
		total += end - start;
	}
	each = total  * 1.0 / TIMES ;
	printf(" Time to run %d iteration  : %ld \n", TIMES, total);
	printf(" Average ReadOverhead        : %f \n", each);
	record[3] = each;


	total = 0;
	puts(" - Running with 4 argument");
	for (int i = 0; i < TIMES; i++){
		start = rdtsc();
		test4(0, 0, 0, 0);
		end = rdtsc();
		total += end - start;
	}
	each = total  * 1.0 / TIMES ;
	printf(" Time to run %d iteration  : %ld \n", TIMES, total);
	printf(" Average ReadOverhead        : %f \n", each);
	record[4] = each;


	total = 0;
	puts(" - Running with 5 argument");
	for (int i = 0; i < TIMES; i++){
		start = rdtsc();
		test5(0, 0, 0, 0, 0);
		end = rdtsc();
		total += end - start;
	}
	each = total  * 1.0 / TIMES ;
	printf(" Time to run %d iteration  : %ld \n", TIMES, total);
	printf(" Average ReadOverhead        : %f \n", each);
	record[5] = each;

	total = 0;
	puts(" - Running with 6 argument");
	for (int i = 0; i < TIMES; i++){
		start = rdtsc();
		test6(0, 0, 0, 0, 0, 0);
		end = rdtsc();
		total += end - start;
	}
	each = total  * 1.0 / TIMES ;
	printf(" Time to run %d iteration  : %ld \n", TIMES, total);
	printf(" Average ReadOverhead        : %f \n", each);
	record[6] = each;

	total = 0;
	puts(" - Running with 7 argument");
	for (int i = 0; i < TIMES; i++){
		start = rdtsc();
		test7(0, 0, 0, 0, 0, 0, 0);
		end = rdtsc();
		total += end - start;
	}
	each = total  * 1.0 / TIMES ;
	printf(" Time to run %d iteration  : %ld \n", TIMES, total);
	printf(" Average ReadOverhead        : %f \n", each);
	record[7] = each;

	puts(" - Final ... ");

}