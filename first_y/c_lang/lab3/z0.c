
#include <stdio.h>
#include <string.h>

int main(void){

	char slowo[100] = "Tekst";
	
	printf("%ld\n",sizeof(slowo));
	printf("%ld\n",strlen(slowo));
	
	printf("%d\n", '\0');
	printf("%d\n", slowo[5]);
	
	printf("%s\n",slowo);
	
	return 0;
	
}
