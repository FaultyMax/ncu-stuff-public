
#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	unsigned short i = 254;
	int j;
	short x = 10;
	
	for(j = 0; j < 8; j++){
		if (i & (1 << j)){
			printf("Bit %d = 1\n", j);
		}else{
			printf("Bit %d = 0\n", j);
		}
	}

    printf("Początkowa wartość: %d\n", x);
	/* ustawienie na jeden */
    x |= (1 << 0);
    printf("Po ustawieniu bitu 0: %d\n", x);
	
    x &= ~(1 << 3);
    printf("Po wyzerowaniu bitu 3: %d\n", x);

    x ^= (1 << 1);
    printf("Po przełączeniu bitu 1: %d\n", x);
    
	return 0;
}
