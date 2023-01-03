/* 
NOTE ON THIS PROGRAM:

There are 3 ways of initializing an arra of CHAR with a string:

(1)
char string[] = "october";

(2)
char string[8] = "october";

(3)
char string[MAX_LENGTH] = "october";

In the first case, the size of the array is automatically taken from the size of the string initializer.
String literals are stored as arrays of CHAR with a string-defining terminating 0 byte;
so, in the case above, the size of the array is 8 ('o', 'c', 't', 'o', 'b', 'e', 'r', 0).

In the other two cases, size is determined either with a precise integer (8) between the array's square brackets or 
a pre-defined constant (MAX_LENTH).

There is also, of course, the possibility of initializing a CHAR array as thus (but STILL with the terminating 0):

char string[] = {'o', 'c', 't', 'o', 'b', 'e', 'r', 0};

or even with the characters' ASCII equivalents:

char string[] = {111, 99, 116, 111, 98, 101, 114, 0};
*/

#include <stdio.h>
#include <stdlib.h>


//prototypes:
void funct1(char []);

int main(int argc, char *argv[]) {
	
	char myArray[] = {"red"};
	
	printf("Before calling funct1: myArray = %s", myArray);
	
	//calling our function:
	funct1(myArray);
	
	//the function above will NOT enable us to display the changed string from within the function back into main():
	printf("\n\nAfter calling funct1: myArray = %s", myArray);
	
	
	return 0;
}

//this function will NOT perform its expected role in main()! here, we are simply passing the variables BY VALUE
void funct1(char a[]) {
	
	char otherArray[] = {"green"};
	
	printf("\n\nWithin funct1: myArray = %s", otherArray);
	//This printf statement will actually display the changed string, BUT ONLY FROM WITHIN THIS FUNCTION, 
	//not if we decide to print it from within MAIN()!
	return;
}
