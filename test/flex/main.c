#include <stdio.h>
#include "lex.yy.c"


int main( int argc, char **argv ) {
    ++argv, --argc;  /* skip over program name */
    if ( argc > 0 )
        yyin = fopen( argv[0], "r" );
    else
        yyin = stdin;

    yylex();
}

int yywrap() {
  return 1;
}


