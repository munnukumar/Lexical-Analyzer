#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include "lexdef.h"

struct node* createNode(char*, char*);
int hashIndex(char*);
void insertToHash(char*, char*);
void display();

#endif
