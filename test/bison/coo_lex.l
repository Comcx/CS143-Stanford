/* scanner for a toy Clojure-like language */
/**
* --- COOLER Syntax ---
* Number
* String
* Lambdas
* Branches
* Loops
*/




%{
/* need this for the call to atof() below */
#include <stdio.h>
#include <math.h>
#include "coo_AST.h"
#include "y.tab.h"

int cur_line = 1;
%}

DIGIT    [0-9]
ALPHA    [a-zA-Z]
SYMBOL   [\+\-\*/~!@#\'$%\^&=<>,\.?:\|\\]
WILD     [\_]
WHITE    [ \t\n]
ID       ({DIGIT}|{ALPHA}|{SYMBOL}|{WILD})*

%%

\"(\\.|[^"\\])*\" {

  yylval.str = strdup(yytext); 
  return coo_STR; /*"*/
}
  
\'[^ ]+ {
  yylval.str = strdup(yytext);
  return coo_SYMBOL;
}

[\+\-]?{DIGIT}+ {
  yylval.i = atoi(yytext);
  return coo_INT;
}

[\+\-]?{DIGIT}+"."{DIGIT}* {
  yylval.r = atof(yytext);
  return coo_REAL;
}

if|for|let|:|=|=:|<-|->|class|object {
  yylval.str = yytext;
  return coo_KEYWORD;
}




{ID} {
  yylval.str = yytext;
  return coo_ID;
}

"(" {
  yylval.str = "(";
  return coo_LEFT;
}
")" {
  yylval.str = ")";
  return coo_RIGHT;
}



"--".*"\n"     /* eat up one-line comments */

[ \t]+          /* eat up whitespace */
\n {cur_line++;}

.  return yytext[0];

%%

void yyerror(char *x) {

  printf("[Error] %s\n", x);
  printf("  at line %d\n", cur_line);
  printf("  at symbol %s\n", yytext);
  exit(1);
}


int yywrap() {

  return 1;
}



