//Basic Declarations and Expressions exercise 4

// also need to redo that one...

#include <stdio.h>

char a = 'X', b = 'L', c = 'M';

int main(void){
	
	printf("The reverse of %c%c%c is %c%c%c\n",a,b,c,c,b,a);
	
	return 0;
}

/*

author's solution

#include <stdio.h>

int main() 
{
    // Declare and initialize character variables
    char char1 = 'X';
    char char2 = 'M';
    char char3 = 'L';

    // Print the original and reversed characters
    printf("The reverse of %c%c%c is %c%c%c\n",
        char1, char2, char3,
        char3, char2, char1);

    return(0);
}

*/
