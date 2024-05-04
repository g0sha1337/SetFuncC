#define _CRT_SECURE_NO_WARNINGS1
#include <stdio.h>
#include "data.h"
#include "hashtable.h"
#include "manager.h"


void printData(Data data) {
	switch (data.type) {
	case INT_TYPE:
		printf("Int: %d", data.Int);
		break;
	case CHAR_TYPE:
		printf("Char: %s", data.Char);
		break;
	case FLOAT_TYPE:
		printf("Float: %f", data.Float);
		break;
	}
}
void printShortData(Data data) {
	switch (data.type) {
	case INT_TYPE:
		printf("%d ", data.Int);
		break;
	case CHAR_TYPE:
		printf("%s ", data.Char);
		break;
	case FLOAT_TYPE:
		printf("%f ", data.Float);
		break;
	}
}
void printHashTable(HashTable* table) {
	if (table == NULL) {
		printf("HASHTABLE IS EMPTY!\n\n");
		return;
	}

	printf("HashTable\n\n");
	for (int i = 0; i < table->size; i++) {
		printf("[%d]: ", i);
		Node* head = table->array[i];
		while (head != NULL) {
			printf("-> ");
			printData(head->value);  // Вывод текущих данных
			head = head->next;
		}
		printf("\n");
		//printf("NULL\n");
	}
}

void printSet(HashTable* ht,char* SetName) {
	printf("%s = ", SetName);

	if (ht == NULL) {
		printf("{}");
		return;
	}

	printf("{ ");

	for (int i = 0; i < ht->size; i++) {
		//printf("[%d]: ", i);
		Node* head = ht->array[i];
		while (head != NULL) {
			//printf("-> ");
			if (i != 0) printf(", ");
			printShortData(head->value);  // Вывод текущих данных
			head = head->next;
		}
	}
	printf("}\n\n");

}
void AskNameOfSet(char* str) {
	//char* name = (char*)malloc(64 * sizeof(char)); //TODO: add free to 
	//if (!name) {
	//	printf("Some error with allocating memory..");
	//	exit(-1);
	//}
	printf("Enter name of new set:  ");
	fscanf_s("%[^\n]%*c", str);
	

	//return name;
}
void printNode(SetNode* node) {
	printf("[%d]   ", node->num);
	printSet(node->ht, node->name);
	printf("\n");
	printHashTable(node->ht);
}
void printList(ListOfSets* list) {
	printf("                                         List of sets\n\n\n");
	for (int i = 0; i < list->size; i++) {
		printNode(&(list->SetArray[i]));
	}

}