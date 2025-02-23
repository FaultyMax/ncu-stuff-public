#include <stdio.h>
#include <stdbool.h> // needed for booleans!

int main(void){
	
	char example_char = 'p';													// single character
	char example_char2 = 112;													// also a single character, found with the numerical position of the ascii character
	unsigned char example_char3 = 112;											// chars can also be unsigned (0-255)
	
	printf("This will display a character: %c\n", example_char);				// %c for chars
	printf("This will display a character: %c\n", example_char2);				// %c or %d for numerical value chars
	printf("This will display a character: %c\n\n", example_char3);				// %c or %d for unsigned chars
	
	char example_string[] = "Hello!";											// array of chars, a string
	
	printf("This will display a string: %s\n\n",example_string);				// %s for strings
	
	float example_float = 2.664;												// 32 bits, 6-7 digits of precision
	float example_float2 = 2.66413981;											// This one will be imprecise!
	double example_double = 2.124166422;										// 64 bits, 15-16 digits of precision
	
	printf("This will display a float: %f\n", example_float);					// %f for floats
	printf("This will display a float, but oh no! Im imprecise!: %0.8f\n", example_float2);
	printf("Original number for reference: 2.66413981\n");						// use double for more precision!
	printf("This will display a double: %0.9lf\n\n", example_double);			// %lf for doubles
	
	bool example_bool = true;													// 8 bits, only stores true or false
	
	printf("This will display a bool value: %d\n\n",example_bool);				// %d for bools
	
	short example_short = -23;													// 16 bits ~ -32.000 - 32.000
	unsigned short example_short2 = 340;										// 16 bits ~ 0 - 65.000
	
	printf("This will display a short int: %d\n", example_short);				// %d for shorts
	printf("This will display a unsigned short int: %d\n\n", example_short2);		// %d for unsigned shorts
	
	int example_int = -10203021;												// 32 bits ~ -2.100.000.000 - 2.100.000.000
	unsigned int example_int2 = 3200001201;										// 32 bits ~ 0 - 4.200.000.000
	
	printf("This will display an int: %d\n", example_int);						// %d for ints
	printf("This will display an unsigned int: %u\n\n", example_int2);			// %u for unsigned ints!
	
	long long int example_long = -1203013021199970993;						// 64 bits, these are very large
	unsigned long long int example_long2 = 2103121203102312122;				// 64 bits, starts from 0 and is also large
	
	printf("This will display a long long int: %lld\n", example_long);			// %lld for ints
	printf("This will display a long long int: %llu\n", example_long2);			// %llu for unsigned ints!
	
	return 0;
}
