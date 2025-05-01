
#include <stdio.h>

int stringlen(char str[]){

	int count = 0;
	
	while(str[count] != '\0'){
		count++;
	}

	return count;

}

void stringcopy(char dest[],char source[]){

	int i;

	/* if(sizeof(source) > sizeof(dest)){ return;} */
	
	for(i = 0 ; i < stringlen(source) ; i++){
		
		dest[i] = source[i];
		
	}
	
	dest[i] = '\0';
	
}

void stringcat(char dest[],char source[]){
	
	int i = stringlen(dest);
	
	int j=0;
	
	for( ; i < stringlen(source)+stringlen(dest) ; i++){
	
		dest[i] = source[j];
		j++;
	}
	
}

int stringcomp(char s1[],char s2[]){
	
	int i;
	
	if(stringlen(s1) != stringlen(s2)){
		return 1;
	}
	
	
	
};

int main(void){
	
	char tekst[] = "Ala ma kota";
	
	char bufor[50];
	char src[] = "Kot ma Ale";
	
	char ala1[20] = "Ala";
	char kot1[20] = " ma kota.";
	
	char text1 = "Ttt";
	char text2 = "Ttt";
	char text3 = "Tat";
	
	printf("%d\n",stringlen(tekst));
	stringcopy(bufor,src);
	
	printf("%s\n",bufor);
	
	stringcat(ala1,kot1);
	
	stringcomp(text1,text2);
	stringcomp(text2,text3);
	
	printf("%s\n",ala1);
	
	return 0;
}
