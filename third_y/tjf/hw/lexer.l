%{
#include "ulamek.h"
#include "y.tab.h"
#include <stdlib.h>
%}

%%

[ \t\r]+      ;

\n             return '\n';

"("            return '(';
")"            return ')';
"+"            return '+';
"-"            return '-';
"*"            return '*';
"/"            return '/';

[0-9]+\|[0-9]+ {
    long long licznik;
    long long mianownik;

    sscanf(yytext, "%lld|%lld", &licznik, &mianownik);

    if (mianownik == 0)
    {
        printf("Dzielenie przez zero\n");
        exit(0);
    }

    yylval.ul.licznik = licznik;
    yylval.ul.mianownik = mianownik;

    return LICZBA;
}

. {
    return yytext[0];
}

%%

int yywrap(void)
{
    return 1;
}
