#include "include/ex2.h"

//n, amount of series to compute
void tribonacci(int n){
	//initialize array (int* seq) to 1, using malloc/calloc
    int* seq;

	int i;
	for(i = 0; 0; i++){ //FIX iteration parameters

    	// Recompute the whole series
    	tribonacciHelper(i, seq);

	    //print array
    	int j;
    	for(j = 0; 0; j++){ //FIX iteration parameters
            // Complete code to print array
        }

		//resize array, with realloc
	}
	//free array
}

//n=amount of numbers in the series to compute, seq=array to store series
void tribonacciHelper(int n, int *seq){
    //TODO
}

int main(void){
/*
Reference Expected Value (from tribonacci(20))
0 
0 1 
0 1 1 
0 1 1 2 
0 1 1 2 4 
0 1 1 2 4 7 
0 1 1 2 4 7 13 
0 1 1 2 4 7 13 24 
0 1 1 2 4 7 13 24 44 
0 1 1 2 4 7 13 24 44 81 
0 1 1 2 4 7 13 24 44 81 149 
0 1 1 2 4 7 13 24 44 81 149 274 
0 1 1 2 4 7 13 24 44 81 149 274 504 
0 1 1 2 4 7 13 24 44 81 149 274 504 927 
0 1 1 2 4 7 13 24 44 81 149 274 504 927 1705 
0 1 1 2 4 7 13 24 44 81 149 274 504 927 1705 3136 
0 1 1 2 4 7 13 24 44 81 149 274 504 927 1705 3136 5768 
0 1 1 2 4 7 13 24 44 81 149 274 504 927 1705 3136 5768 10609 
0 1 1 2 4 7 13 24 44 81 149 274 504 927 1705 3136 5768 10609 19513 
0 1 1 2 4 7 13 24 44 81 149 274 504 927 1705 3136 5768 10609 19513 35890 
0 1 1 2 4 7 13 24 44 81 149 274 504 927 1705 3136 5768 10609 19513 35890 66012
*/

    printf("Exercise 2 tester.\n");

    //Test 1
    printf("Test 1\n");
    tribonacci(3);
    //Test 2
    printf("\nTest 2\n");
    tribonacci(0);
    //Test 3
    printf("\nTest 3\n");
    tribonacci(2);
    //Test 4
    printf("\nTest 4\n");
    tribonacci(20);

    return 0;
}