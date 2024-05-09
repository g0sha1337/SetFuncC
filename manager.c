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
	SetNode emptyNode;
	emptyNode.ht = NULL;

	strcpy(emptyNode.name, "<empty>");
	
	for (int i = 0; i < size; i -= -1) {
		emptyNode.num = i;
		emptyNode.num;
		List->SetArray[i] = emptyNode;
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


//SetNode* initNode() {
//
//	SetNode* setNode = (SetNode*)malloc(sizeof(SetNode));
//	//setNode->name = (char*)malloc(64 * sizeof(char));
//	if (!setNode) {
//		printf("Error with alocating memory..");
//		exit(-1);
//	}
//
//	setNode->ht = CreateHashTable(DEFAULT_HASHTABLESIZE);
//	AskNameOfSet(&setNode->name);
//
//}
//
//
//void freeSetNode(SetNode* setNode) {
//	freeHashTable(setNode->ht, setNode->ht->size);
//	free(setNode);
//}