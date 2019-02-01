/*#include "coo_parser.tab.c"*/
#include <stdlib.h>
#include <stdio.h>
//#include "y.tab.h"

typedef struct coo_Node {
  
  int tag;                  /*COOLA parse element type tag*/
  union {                   /*Contain actual data of node*/
    int i;                  /*Integer type*/
    double r;               /*Real number type*/
    char *str;              /*String, Symbol, Id type*/
    struct coo_Node *list;  /*List type*/
  } data;
  struct coo_Node *next;    /*List linker*/
} coo_Node;                 /*Main COOLA Node type*/


enum coo_Tag {
	      T_INT, T_REAL,
	      T_LIST,
	      T_SYMBOL, T_STR,
	      T_KEYWORD, T_ID
};


coo_Node *get_node();

coo_Node *list(coo_Node *list);
coo_Node *list_args(coo_Node *first, coo_Node *rest);
coo_Node *integer(int i);
coo_Node *real(double r);
coo_Node *string(char *str);
coo_Node *symbol(char *str);
coo_Node *keyword(char *str);
coo_Node *id(char *str);

void print_node(coo_Node *node, int depth);







