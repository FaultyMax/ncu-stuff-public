//Basic Declarations and Expressions exercise 2

#include <stdio.h>

int main(void){
	
	int version =  __STDC_VERSION__;
	
	if(version >= 201710){
		printf("We are using C18!\n");
	}
	
	// added after checking the answer
	
	if(version == 201112){printf("We are using C11!\n");}
	if(version == 199901){printf("We are using C90!\n");}
	
	// and this is still probably bad and might error on older systems, you can always try with preprocessor directives like below
	
	return 0;
}

/*

#include <stdio.h>

int main(int argc, char** argv) {
    // Check for C standard version
    #if __STDC_VERSION__ >=  201710L
        printf("We are using C18!\n");
    #elif __STDC_VERSION__ >= 201112L
        printf("We are using C11!\n");
    #elif __STDC_VERSION__ >= 199901L
        printf("We are using C99!\n");
    #else
        printf("We are using C89/C90!\n");
    #endif

    // Indicate successful execution
    return 0;
}

 
*/
