
#include <stdio.h>

int main(void){
	
	FILE *plik1 = fopen("files/cos.txt","r");
	FILE *plik2 = fopen("files/wynik.txt","w");
	char c = 0;
	
	if (plik1 == NULL){return 1;}
	if (plik2 == NULL){return 1;}
	
	while((c = fgetc(plik1)) != EOF){
	
		//printf("%c",c);
		
		if(!(c == ' ' || c == ',')){
			fputc(c, plik2);
		}
		
	}
	
	fclose(plik1);
	fclose(plik2);
	return 0;
}

