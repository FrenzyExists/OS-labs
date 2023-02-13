## Ex 2

In mathematics, the Fibonacci numbers are the numbers in the following integer sequence, called the Fibonacci sequence, and characterized by the fact that every number after the first two is the sum of the two preceding ones:

`0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377...`

By definition, the first two numbers in the Fibonacci sequence are either 1 and 1, or 0 and 1, depending on the chosen starting point of the sequence, and each subsequent number is the sum of the previous two.

This series can be broken down as the following series:

```
Fib0 = 0
Fib1 = 1
Fibn = Fibn-1 + Fibn-2 , n > 1
```

## Tribonacci sequence:

The tribonacci sequence is a generalization of the Fibonacci sequence where each term is the sum of the three preceding terms.
This series can be broken down as the following series:

- `Trib0= 0`
- `Trib1= 1`
- `Trib2= 1`
- `Tribn= Tribn-1 + Tribn-2 + Tribn-3, n>2`

The sequence begins 
You will create an array smaller than n using `malloc/calloc` to store the values of the series on the heap. You will use realloc to resize the array as needed. *You will recompute the Tribonacci series with every iteration (even if you already have the values).*

## Input Format

Input will contain one integer, n`, as the amount of series to compute and print.


## Output Format

You will print n tribonacci series up to `i` where `{i|0<=i<=n}` in new lines separeted by a single space. Each new line will print the tribonacci series for `i+1`.


For example:

### Test

```bash
tribonacci(3);
tribonacci(0);
tribonacci(2);
tribonacci(20);
```
### Result

```bash
0
0 1
0 1 1
0 1 1 2
0
0
0 1
0 1 1
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
```

```c
#include "ex2.h"

//n, amount of series to compute
void tribonacci(int n){
	//initialize array (int* seq) to 1, using malloc/calloc
    int* seq;
    seq = (int*)calloc(1, n*sizeof(int));


	int i;
	for(i = 0; i<n+1; i++){ //FIX iteration parameters

    	// Recompute the whole series
    	tribonacciHelper(i, seq);

	    //print array
    	int j;
    	for(j = 0; j<i+1; j++){ //FIX iteration parameters
            // Complete code to print array
            printf("%d ", seq[j]);
        }

		//resize array, with realloc
        seq = (int*) realloc(seq, n * sizeof(int));
        printf("\n");
	}
	//free array
    free(seq);
}

//n=amount of numbers in the series to compute, seq=array to store series
void tribonacciHelper(int n, int *seq) {
    //TODO
    if (n == 0) {
       seq[n] = 0;
    } else if (n <= 2) {
        seq[n] = 1;
    } else {
        seq[n] = seq[n - 1] + seq[n - 2] + seq[n - 3];
    }    
}
```