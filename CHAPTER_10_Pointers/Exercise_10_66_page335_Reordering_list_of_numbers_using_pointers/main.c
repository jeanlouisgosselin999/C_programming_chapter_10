/*

This program will demonstrate how to reorder a list of numbers using POINTERS rather than arrays.
The function will use the BUBBLE SORT code.

NOTE: regarding MALLOC: an important advantage of dynamic memory allocation is the ability to reserve as much memory as
may be required during program execution, then release this memory when it is no longer needed.

NOTE: to see how we do this traditionally with arrays, see Ex_9_13

We will notice that, compared with Ex_9_13, the only two big differences in this example are:
(1) using the extra MALLOC expression (x = (int *) malloc(n * sizeof(int));) to dynamically allocate memory space for the list;
(2) replacing the customary expressions &x[i] with x+1, and x[i] with *(x+1)

*/

#include <stdio.h>
#include <stdlib.h>

//prototype:
void reorder(int n, int *x); //NOTE: the second argument is a pointer to an integer quantity rather than an integer array

int main(int argc, char *argv[]) {
	
	int i, n, *x; // "*x" is a pointer that points towards objects of type INT
	
	//defining number of integers we wish to input::
	printf("How many values?\n");
	scanf("%d", &n);
	printf("\n");
	
	//allocating memory for our pointer "x" using MALLOC:
	x = (int *) malloc(n * sizeof(int));
	
	//inputting + printing chosen integers:
	for(i=0; i<n; ++i) {
		printf("i = %d   x = ", i+1);
		scanf("%d", x+i); //NOTE: here, "x+1" is equivalent to writing "&x[i]"
	}
	
	//calling our function to reorder all array elements:
	reorder(n, x);
	
	printf("\n\n\n");
	
	//displaying the reordered list of numbers:
	for(i=0; i<n; ++i) {
		printf("i = %d   x = %d\n", i+1, *(x+i)); //NOTE: here, "*(x+i)" is equivalent to writing "x[i]"
	}
	
	return 0;
}

//our function:
void reorder(int n, int *x) {
	
	int i, j, temp; //i == row number, j == column number
	
	//NOTE: code below == BUBBLE SORT code == treating this as 2-dimensional array (with only one column per row)
	for(i = 0; i < n-1; ++i) 
		for(j = i+1; j < n; ++j)
			if (*(x+i) > *(x+j)) { /*
									NOTE: here, "*(x+i)" is equivalent to writing "x[i]"; similarly, "*(x+j)" is equivalent to writing "x[j]"
									ALSO: we have chosen to reorder in INCREASING order; to do it in DECREASING order, simply change > for <
								*/
				//swapping:
				temp = *(x+j);
				*(x+j) = *(x+i);
				*(x+i) = temp;
			}
	return;
}
