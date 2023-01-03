/*
This program will demonstrate how to print the values of array elements and their addresses.

THIS TIME: PRINTING unsigned long int !!!

NOTE: 	&x[i] and (x+1) both represent the ADDRESS of the ith element of array "x";
		x[i] and *(x+i) both represent the CONTENTS of the address of the ith element of array "x"		
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	
	static unsigned long int x[10] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
	int i;
	
	for(i=0; i<=9; ++i) {
		
		//displaying the CONTENTS of each of the array's elements:
		printf("\nfor element %d of the array:  x[i] = %lu   *(x + i) = %lu", i, x[i], *(x+i));

	}
	
	printf("\n\n\n");
	
		for(i=0; i<=9; ++i) {

		//displaying the ADDRESS of each of the array's elements:
		printf("\nfor element %d of the array:  &x[i] = %X   x + i = %X", i, &x[i], (x+i));
		//REMINDER: identifier %X gives the hexadecimal value of the address
	}
	
	return 0;
}
