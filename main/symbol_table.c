#include "symbol_table.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct hash hashTable[1000];
int eleCount = 1000;


struct node* createNode(char* token, char* attr)
{
	struct node* newnode;
	newnode = (struct node*) malloc(sizeof(struct node));
	strcpy(newnode->token, token);
	strcpy(newnode->attr, attr);
	newnode->next = NULL;
	return newnode;
}

int hashIndex(char* token)
{
	int hi = 0;
	int l, i;
	for (i = 0; token[i] != '\0'; i++) {
		hi = hi + (int)token[i];
	}
	hi = hi % eleCount;
	return hi;
}

void insertToHash(char* token, char* attr)
{
	int flag = 0;
	int hi;

	//calling the hashIndex for finding the index of the table.

	hi = hashIndex(token);
	struct node* newnode = createNode(token, attr);
	/* head of list for the bucket with index "hashIndex" */
	if (hashTable[hi].head == NULL) {
		hashTable[hi].head = newnode;
		hashTable[hi].count = 1;
		return;
	}
	struct node* myNode;
	myNode = hashTable[hi].head;
	while (myNode != NULL) {
		if (strcmp(myNode->token, token) == 0) {
			flag = 1;
			break;
		}
		myNode = myNode->next;
	}
	if (!flag) {
		//adding new node to the list
		newnode->next = (hashTable[hi].head);
		//update the head of the list and no of nodes in the current bucket
		hashTable[hi].head = newnode;
		hashTable[hi].count++;
	}
	return;
}

void display()
{
	struct node* myNode;
	int i, j, k = 1;
	printf
	("-------------------------------------------------------------------");
	printf("\nSNo \t|\tToken \t\t|\tToken Type \t\n");
	printf
	("-------------------------------------------------------------------\n");
	for (i = 0; i < eleCount; i++) {
		if (hashTable[i].count == 0)
			continue;
		myNode = hashTable[i].head;
		if (!myNode)
			continue;
		while (myNode != NULL) {
			printf("%d\t\t", k++);
			printf("%s\t\t\t", myNode->token);
			printf("%s\t\n", myNode->attr);
			myNode = myNode->next;
		}
	}
	return;
}

