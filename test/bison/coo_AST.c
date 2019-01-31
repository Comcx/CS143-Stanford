/*#include "coo_parser.tab.c"*/
#include "coo_AST.h"


coo_Node *get_node() {

  coo_Node *p;
  size_t size_node = sizeof(coo_Node);
  if ((p = malloc(size_node)) == NULL)
    yyerror("out of memory\n");

  p->next = NULL;
  return p;
}

coo_Node *list(coo_Node *head, coo_Node *tail) {
  //head->tag = T_LIST;
  //  tail->next = NULL;
  head->next = tail;
  return head;
}

coo_Node *integer(int i) {

  coo_Node *p = get_node();
  p->tag = T_INT;
  p->data.i = i;
  return p;
}

coo_Node *real(double r) {

  coo_Node *p = get_node();
  p->tag = T_REAL;
  p->data.r = r;
  return p;
}

coo_Node *string(char *str) {

  coo_Node *p = get_node();
  p->tag = T_STR;
  p->data.str = str;
  return p;
}

coo_Node *symbol(char *str) {

  coo_Node *p = get_node();
  p->tag = T_SYMBOL;
  p->data.str = str;
  return p;
}

coo_Node *id(char *str) {

  coo_Node *p = get_node();
  p->tag = T_ID;
  p->data.str = str;
  return p;
}



void print_atom(coo_Node *node) {

  switch (node->tag) {
    case T_ID:
      printf("Id: %s\n", node->data.str);
      break;
    case T_INT:
      printf("Integer: %d\n", node->data.i);
      break;
    case T_REAL:
      printf("Real: %f\n", node->data.r);
      break;
    case T_SYMBOL:
      printf("Symbol: %s\n", node->data.str);
      break;
    case T_STR:
      printf("Str: %s\n", node->data.str);
      break;
    default:
      printf("%d\n", node->tag);
  }
}


void print_list(coo_Node *list, int depth) {

  if(list->next != NULL) {
    for(int i =0; i < depth; i++)
      printf("  ");
    print_atom(list);
    print_list(list->next, ++depth);
    
  } else {
    for(int i =0; i < depth; i++)
      printf("  ");
    print_node(list);
  }
}

void print_node(coo_Node *node) {

  if(node->next == NULL) {
    print_atom(node);
    
  } else {

    printf("\n");
    print_list(node, 0);
  }
}






