#include <stdlib.h>
#include <stdio.h>
void reverseSentence();
int main(int argc, char const *argv[])
{
	printf("Enter a sentence: ");
	reverseSentence();
	return 0;
}
/* "Recursive" example -> Reverse a string */
void reverseSentence()
{
	char c;
	scanf("%c",&c);
	if(c != '\n'){
		reverseSentence();
		printf("%c",c);
	}
}


/* ********
INPUT: chishen
OUTPUT: nehsihc
******** */
