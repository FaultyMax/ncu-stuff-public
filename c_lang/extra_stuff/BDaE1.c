//Basic Declarations and Expressions exercise 1

#include <stdio.h>

char name[50],dob[20],mob[20];

int main(void){
	
	fgets(name, 50, stdin);
	fgets(dob, 20, stdin);
	fgets(mob, 20, stdin);
	
	printf("Name   : %s",name);
	printf("DOB    : %s",dob);
	printf("Mobile : %s",mob);

	return 0;
}

/*

author's solution

#include <stdio.h>

int main()  
{
    // Print Name
    printf("Name   : Alexandra Abramov\n"); 
    
    // Print Date of Birth
    printf("DOB    : July 14, 1975\n"); 
    
    // Print Mobile Number
    printf("Mobile : 99-9999999999\n"); 
    
    // Indicate successful execution
    return(0); 
}
 
*/
