/*#include "coo_parser.tab.c"*/
#include "coo_AST.h"


coo_Node *get_node() {

  coo_Node *p;
  size_t size_node = sizeof(coo_Node);
  if ((p = malloc(size_node)) == NULL) {
    
    printf("out of memory\n");
    exit(-1);
  }
  p->next = NULL;
  return p;
}

coo_Node *list(coo_Node *list) {
  //head->tag = T_LIST;
  //  tail->next = NULL;
  coo_Node *head = get_node();
  head->data.list = list;
  head->tag = T_LIST;
  
  return head;
}

coo_Node *list_args(coo_Node *first, coo_Node *rest) {

  first->next = rest;
  return first;
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

coo_Node *keyword(char *str) {

  coo_Node *p = get_node();
  p->tag = T_KEYWORD;
  p->data.str = str;
  return p;
}

coo_Node *id(char *str) {

  coo_Node *p = get_node();
  p->tag = T_ID;
  p->data.str = str;
  return p;
}






void print_tab(int depth) {

  for(int i = 0; i < depth; i++) {
    printf("  ");
  }
}


void print_atom(coo_Node *node, int depth) {

  print_tab(depth);
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
  case T_KEYWORD:
    printf("Keyword: %s\n", node->data.str);
    break;
  default:
    printf("%d\n", node->tag);
  }
}


void print_list(coo_Node *list, int depth) {

  if(list->tag == T_LIST) {

    coo_Node *p = list->data.list;
    print_tab(depth++);
    printf("List: ...\n");
    //    print_tab(depth++);
    while(p != NULL) {

      print_node(p, depth);
      p = p->next;
    }
    
  } else {

    print_tab(depth);
    print_node(list, depth);
  }
}

void print_node(coo_Node *node, int depth) {

  if(node->tag != T_LIST) {
    print_atom(node, depth);
    
  } else {

    printf("\n");
    print_list(node, depth);
  }
}






