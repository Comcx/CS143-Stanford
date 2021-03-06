%{
#include <stdio.h>
#include "coo_AST.h"
  /*#include "y.tab.h"*/
  
int yylex();
void yyerror(char* x);
%}

%union {
  int i;
  double r;
  char *str;
  coo_Node *node;
}

%token <node> coo_LIST
%token <i> coo_INT
%token <r> coo_REAL
%token <str> coo_STR
%token <str> coo_SYMBOL
%token <str> coo_ID
%token <str> coo_KEYWORD
%token <str> coo_LEFT coo_RIGHT


%type <node> Term
%type <node> Expr
%type <node> Exps
%type <node> List

%%

Prog : Prog Expr  {printf("-> "); print_node($2, 0);}
     | /*Empty*/  {}

Expr : Term       {$$ = $1; /*printf("ans = "); print_node($$, 0);*/}
     | List       {$$ = $1;}
     ;

List : coo_LEFT
       coo_RIGHT  {}
     | coo_LEFT
       Exps
       coo_RIGHT  {
       //printf("fst: %s\n", $2->data.str);
         $$ = list($2);
       }
     ;

Exps : Expr       {$$ = $1; /*printf("ans = "); print_node($$);*/}
     | Expr Exps  {$$ = list_args($1, $2);}
     ;

Term : coo_INT    {$$ = integer($1);}
     | coo_REAL   {$$ = real($1);}
     | coo_STR    {$$ = string($1);}
     | coo_SYMBOL {$$ = symbol($1);}
     | coo_KEYWORD{$$ = keyword($1);}
     | coo_ID     {$$ = id($1);}
     ;

%%

int main() {

  return yyparse();
}





