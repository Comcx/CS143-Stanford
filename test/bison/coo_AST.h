/*#include "coo_parser.tab.c"*/
#include <stdlib.h>
#include <stdio.h>
//#include "y.tab.h"

typedef struct coo_Node {
  
  int tag;
  int is_list;
  union {
    int i;
    double r;
    char *str;
  } data;
      struct coo_Node *next;
} coo_Node;


enum coo_Tag {
	      T_INT, T_REAL, T_LIST, T_SYMBOL, T_STR, T_ID
};


coo_Node *get_node();

coo_Node *list(coo_Node *head, coo_Node *tail);
coo_Node *integer(int i);
coo_Node *real(double r);
coo_Node *string(char *str);
coo_Node *symbol(char *str);
coo_Node *id(char *str);

void print_node(coo_Node *node);







