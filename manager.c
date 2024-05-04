#include <stdio.h>
#include "manager.h"


ListOfSets* initListOfSets(int size) {
	ListOfSets* List = (ListOfSets*)malloc(sizeof(ListOfSets));
	List->size = size; 
	List->SetArray = (SetNode*)malloc(List->size * sizeof(SetNode));
	if (List->SetArray == NULL) {
		printf("Some error with allocating memory..");
		exit(-1);
	}
	List->count = 0;
	return List;
}
void freeListOfSets(ListOfSets* list) {
	free(list->SetArray);
	free(list);
}

void AddNodeToSet(ListOfSets* list, char* NewName) { //add new element to list of sets array
	
	SetNode Node;

	Node.num = list->count;
	
	list->SetArray[Node.num] = Node;

	list->count++;
}


SetNode* initNode() {
	SetNode* setNode = (SetNode*)malloc(sizeof(SetNode));

	if (!setNode) {
		printf("Error with alocating memory..");
		exit(-1);
	}

	setNode->ht = CreateHashTable(DEFAULT_HASHTABLESIZE);
	AskNameOfSet(setNode->name);

}


