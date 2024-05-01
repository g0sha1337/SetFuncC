#define _CRT_SECURE_NO_WARNINGS1
#include <stdio.h>
#include "data.h"
#include "hashtable.h"

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
}void printShortData(Data data) {
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
		printf("EMPTY\n\n");
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

void printSet(char* SetName, HashTable* ht) {
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

