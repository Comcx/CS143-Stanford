/* scanner for a toy Pascal-like language */
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
#include <math.h>
%}

DIGIT    [0-9]
ALPHA    [a-zA-Z]
SYMBOL   [\+\-\*/~!@#$%\^&=<>,\.?:;\|\\]
WILD     [_]
ID       ({DIGIT}|{ALPHA}|{SYMBOL}|{WILD})*

%%

\"(\\.|[^"\\])*\" printf("String: %s\n", yytext); /*"*/

  
[\+\-]?{DIGIT}+ {
  printf( "Integer: %s (%d)\n", yytext,
          atoi(yytext));
}

[\+\-]?{DIGIT}+"."{DIGIT}* {
  printf( "Float: %s (%g)\n", yytext,
          atof(yytext) );
}

if|for|while|lambda|:|=> {
  printf( "Keyword: %s\n", yytext );
}




{ID} {
  printf( "Identifier: %s\n", yytext );
}

"("  printf("Left paren\n");
")"  printf("Right paren\n");



"--".*"\n"     /* eat up one-line comments */

[ \t\n]+          /* eat up whitespace */

. printf( "Unrecognized character: %s\n", yytext );

%%





