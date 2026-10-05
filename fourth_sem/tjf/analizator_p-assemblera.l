%{
	#include <stdio.h>
	int ignore = 0;
%}

number		[1-9][0-9]*
id			[A-Za-z][A-Za-z0-9]*

comment		"//"
input		"INPUT"
output		"OUTPUT"
add			"ADD"
subt		"SUBT"
load		"LOAD"
store		"STORE"
clear		"CLEAR"
halt		"HALT"
var 		"VAR"

%%

{comment}	{ if(!ignore) printf("Komentarz\n"); ignore = 1; }
\n 			{ if(ignore) ignore = 0; }
{input}		{ if(!ignore) printf("czytanie z rejestru wejściowego\n"); }