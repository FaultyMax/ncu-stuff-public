
#include <stdio.h>
#include <string.h>

int main(void){

	char slowo[] = "Ala ma kota.";
	
	int i;
	
	for(i = 0 ; i < strlen(slowo) ; i++){
		printf("%c  %d\n",slowo[i],slowo[i]);
	}
	
	return 0;
	
}
