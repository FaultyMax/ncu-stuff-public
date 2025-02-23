#include <stdio.h>
#include <stdbool.h> // needed for booleans!

int main(void){
	
	char example_char = 'p';											// single character
	char example_char2 = 112;											// also a single character, found with the numerical position of the ascii character
	
	printf("This will display a character: %c\n", example_char);		// %c for chars
	printf("This will display a character: %c\n\n", example_char2);		// %c or %d for numerical value chars
	
	char example_string[] = "Hello!";									// array of chars, a string
	
	printf("This will display a string: %s\n\n",example_string);		// %s for strings
	
	float example_float = 2.664;										// 32 bits, 6-7 digits of precision
	float example_float2 = 2.66413981;									// This one will be imprecise!
	double example_double = 2.124166422;								// 64 bits, 15-16 digits of precision
	
	printf("This will display a float: %f\n", example_float);			// %f for floats
	printf("This will display a float, but oh no! Im imprecise!: %0.8f\n", example_float2);
	printf("This will display a double: %0.9lf\n\n", example_double);	// %lf for doubles
	
	bool example_bool = true;											// 8 bits, only stores true or false
	
	printf("This will display a bool value: %d\n\n",example_bool);		// %d for bools
	
	short example_short;
	unsigned short int example_short;
	
	
	
	int example_int;
	
	long long int example_long
	unsigned long long int example_long
	
	return 0;
}
