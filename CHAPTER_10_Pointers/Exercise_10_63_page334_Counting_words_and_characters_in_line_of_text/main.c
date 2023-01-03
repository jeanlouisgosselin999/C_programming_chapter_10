/*
This program will analyze a line of text entered by the user.

It will display the number of words, then the total number of characters from that line of text.

*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // this library is used to use the toupper() function

#define MAX 50

//prototype:
void scan_line(char [], int *, int *);
int main(int argc, char *argv[]) {
	
	char line[MAX];
	int a;
	int wordCount = 0;
	int charCount = 0;
	
	//entering a line of text charcater by character using getchar():
	printf("Enter a line of text:\n");
	for(a=0; (line[a] = getchar()) != '\n'; ++a)
	;
	
	//calling our function, and "sending" the ADDRESSES of our variables to our function, the arguments of which -POINTERS- will point to. 
	//(NOTE: the array argument, "line", is not preceded by an &, since arrays are, by definition, pointers, and therefore ADDRESSES)
	scan_line(line, &wordCount, &charCount);
	
	printf("\nNumber of words: %d", wordCount);
	printf("\nNumber of characters: %d", charCount);
	
	return 0;
}

/*	Our function (we declare our pointers within the function definition itself)
	NOTE: the array argument, "line", is not preceded by a *, since arrays are, by definition, pointers.
	We could also have written the function as such: 
	void scan_line(char *line, int *pw, int *pc)
*/ 
void scan_line(char line[], int *pw, int *pc) {
	
	char c; //character within the line of text
	int count; //counter of characters in line of text
	*pw = 1; //we initialize our pointer to 1, because the MINIMUM number of words in a line of text is obvisouly 1!
	
	// counting total number of characters (discarding whitespaces) and number of words:
	//NOTE: we are converting all characters to uppercase, just to make things more straight-forward
	for (count=0; (c = toupper(line[count])) != '\n'; ++count) { 
		
		if (line[count] != ' ')
			++ *pc;
			
		if (line[count] == ' ' && line[count-1] != ' ') //NOTE: notice how with expression "line[count-1] != ' '" we discard ALL whitespaces
			++ *pw;	
	}
	
	return;
}
