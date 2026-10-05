%{
	#include <stdio.h>
	#include <stdlib.h>

	int numOperators = 0;
	int numInts = 0;
	int numDoubles = 0;
	int numBrackets = 0;
	int intValue = 0;
	double doubleValue = 0.0;
%}

digit		[0-9]
hex_digit	{digit}|[a-f]|[A-F]
digits 		{digit}+
hex_digits	{hex_digit}+
hex_pref	"0x"|"0X"
sign_opt	("-")?
fractional	"."{digits}
exp_out		((e|E){sign_opt}{digits})?

dec_num			{digits}
hex_num			{hex_pref}{hex_digits}
double_num		({digits}{fractional}|{digits}"."?|{fractional})
double_exp_num	({digits}{fractional}|{digits}"."?|{fractional}){exp_out}

%%

{dec_num}		{ printf("Liczba dziesiętna (%s)\n",yytext); 
				++numInts;
				intValue += strtol(yytext,NULL,10);
				}

.|\n 			{ /* pomijaj niedopasowane znaki */ }

%%

int main() {
	printf("Poczatek skanowania...\n");
	yylex();
	printf("\nKoniec skanowania\n");
	printf("\t Przeczytano %d liczb calkowitych o lacznej wartosci %d\n", numInts, intValue);

	return 0;
}