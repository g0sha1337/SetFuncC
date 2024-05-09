#pragma once
#include "hashtable.h"

typedef struct SetNode {
	HashTable* ht;
	char name[64]; //char* name
	int num;
}SetNode;


typedef struct ListOfSets {
	SetNode* SetArray;
	int size;
	int count;

} ListOfSets;
ListOfSets* initListOfSets(int size);
void freeListOfSets(ListOfSets* list);
//SetNode* initNode();
//void freeSetNode(SetNode* setNode);