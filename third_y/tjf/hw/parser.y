
%{
#include <stdio.h>
#include <stdlib.h>
#include "ulamek.h"
#include <string.h>

int yylex(void);
void yyerror(const char *s);

int poprawne = 0;

long long nwd(long long a, long long b)
{
    if (a < 0) a = -a;
    if (b < 0) b = -b;

    while (b != 0)
    {
        long long t = a % b;
        a = b;
        b = t;
    }

    return a == 0 ? 1 : a;
}

Ulamek uprosc(Ulamek u)
{
    if (u.mianownik < 0)
    {
        u.licznik = -u.licznik;
        u.mianownik = -u.mianownik;
    }

    long long g = nwd(u.licznik, u.mianownik);

    u.licznik /= g;
    u.mianownik /= g;

    return u;
}

Ulamek dodaj(Ulamek a, Ulamek b)
{
    Ulamek r;
    r.licznik = a.licznik * b.mianownik + b.licznik * a.mianownik;
    r.mianownik = a.mianownik * b.mianownik;
    return uprosc(r);
}

Ulamek odejmij(Ulamek a, Ulamek b)
{
    Ulamek r;
    r.licznik = a.licznik * b.mianownik - b.licznik * a.mianownik;
    r.mianownik = a.mianownik * b.mianownik;
    return uprosc(r);
}

Ulamek mnoz(Ulamek a, Ulamek b)
{
    Ulamek r;
    r.licznik = a.licznik * b.licznik;
    r.mianownik = a.mianownik * b.mianownik;
    return uprosc(r);
}

Ulamek dziel(Ulamek a, Ulamek b)
{
    Ulamek r;
    r.licznik = a.licznik * b.mianownik;
    r.mianownik = a.mianownik * b.licznik;
    return uprosc(r);
}

void wypisz(Ulamek u)
{
    u = uprosc(u);

    if (u.mianownik == 1)
        printf("%lld\n", u.licznik);
    else
        printf("%lld|%lld\n", u.licznik, u.mianownik);
}

%}

%union {
    Ulamek ul;
}

%token <ul> LICZBA
%token KONIEC

%type <ul> expr term factor

%left '+' '-'
%left '*' '/'
%right UMINUS

%%

program:
      
    | program linia
    ;

linia:
      expr '\n'
      {
          wypisz($1);
          poprawne++;
      }
    ;

expr:
      expr '+' term
      {
          $$ = dodaj($1, $3);
      }
    | expr '-' term
      {
          $$ = odejmij($1, $3);
      }
    | term
      {
          $$ = $1;
      }
    ;

term:
      term '*' factor
      {
          $$ = mnoz($1, $3);
      }
    | term '/' factor
      {
          $$ = dziel($1, $3);
      }
    | factor
      {
          $$ = $1;
      }
    ;

factor:
      '(' expr ')'
      {
          $$ = $2;
      }
    | '-' factor %prec UMINUS
      {
          $$.licznik = -$2.licznik;
          $$.mianownik = $2.mianownik;
      }
    | LICZBA
      {
          $$ = $1;
      }
    ;

%%

void yyerror(const char *s)
{
    printf("Błąd składniowy\n");
    printf("Poprawnie obliczone wyrażenia: %d\n", poprawne);
    exit(0);
}

int main(void)
{
    yyparse();

    printf("Poprawnie obliczone wyrażenia: %d\n", poprawne);

    return 0;
}

