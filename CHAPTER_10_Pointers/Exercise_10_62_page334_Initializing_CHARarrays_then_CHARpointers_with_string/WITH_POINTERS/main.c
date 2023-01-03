/* 
NOTE ON THIS PROGRAM:
INSTEAD OF USING ARRAYS, WE WILL USE POINTERS.

Notice how pointers and arrays act exactly the same way: arrays ARE pointers.
*/

#include <stdio.h>
#include <stdlib.h>


//prototype:
void funct1(char *);

int main(int argc, char *argv[]) {
	
	char *myPointer = {"red"};
	
	printf("Before calling funct1: myPointer = %s", myPointer);
	
	//calling our function:
	funct1(myPointer);
	
	//NOTE: the function above will NOT enable us to display the changed string from within the function back into main():
	printf("\n\nAfter calling funct1: myPointer = %s", myPointer);
		
	return 0;
}

//function
void funct1(char *a) {
	
	char *otherPointer = {"green"};
	
	printf("\n\nWithin funct1: myPointer = %s", otherPointer);
	//This printf statement will actually display the changed values of variables "otherPointer", BUT ONLY FROM WITHIN THIS FUNCTION, 
	//not when we print it from within MAIN()!
	return;
}
