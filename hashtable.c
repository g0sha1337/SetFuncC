#define _CRT_SECURE_NO_WARNINGS
#include <malloc.h>
#include <string.h>


#include "hashtable.h"
#include "hash.h"

bool EqualData(Data data1, Data data2) {
	if (data1.type == data2.type) {
		if (data1.type == FLOAT_TYPE) {
			if (data1.Float == data2.Float) return true;
		}
		else if (data1.type == INT_TYPE) {
			if (data1.Int == data2.Int) return true;
		}
		else if (data1.type == CHAR_TYPE) {
			if (strcmp(data1.Char, data2.Char) == 0) return true;
		}
	}

	return false;
}

HashTable* CreateHashTable(int size) {
	HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
	if (!(ht)) {
		return NULL; // if error inda heap
	}
	ht->size = size;
	ht->array = (Node**)malloc(sizeof(Node*)*size);
	if (!ht->array) {
		free(ht);
		return NULL;
	}

	for (int i = 0; i < size; i++) {
		ht->array[i] = NULL;
	}

	return ht;
}

void freeHashTable(HashTable* ht, int size) {
	for (int i = 0; i < size; i++) {
		if (ht->array[i]) free(ht->array[i]);
	}
	free(ht->array);
	free(ht);
}

void InsertHashTable(HashTable* ht, Data value) {
	int index = HashData(&value, ht->size);
	Node* newNode = (Node*)malloc(sizeof(Node));
	
	newNode->next = NULL;
	newNode->value = value;

	if (ht->array[index] == NULL) {
		ht->array[index] = newNode;
	}
	else if (ht->array[index] != NULL && ht->array[index]->value.type == value.type) {
		if (value.type == FLOAT_TYPE) {
			if (ht->array[index]->value.Float != value.Float) {
				newNode->next = ht->array[index];
				ht->array[index] = newNode;
			} 
		} else if (value.type == INT_TYPE) {
			if (ht->array[index]->value.Int != value.Int) {
				newNode->next = ht->array[index];
				ht->array[index] = newNode;
			}
		}
		else if (value.type == CHAR_TYPE) {
			if (!(strcmp(ht->array[index]->value.Char, value.Char))) {
				newNode->next = ht->array[index];
				ht->array[index] = newNode;
			}
		}
	}
	else {
		newNode->next = ht->array[index];
		ht->array[index] = newNode;
	}
}

bool removeElement(HashTable* ht, Data element) {
	unsigned int bucket = HashData(&element, ht->size);
	Node* curr = ht->array[bucket];
	Node* prev = NULL;

	while (curr != NULL) {
		if (EqualData(curr->value, element)) {
			if (prev == NULL) {
				ht->array[bucket] = curr->next;
			}
			else {
				prev->next = curr->next;
			}
			free(curr);
			return true;
		}
	}
	return false;

}


bool InitializeFromIntArray(HashTable* ht, int* array, int size) {
	for (int i = 0; i < size; i++) {
		Data* element = InitData(INT_TYPE);
		element->Int = array[i];
		InsertHashTable(ht, *element);
		FreeData(element);
	}
}

bool InitializeFromFloatArray(HashTable* ht, float* array, int size) {
	for (int i = 0; i < size; i++) {
		Data* element = InitData(FLOAT_TYPE);
		element->Float = array[i];
		InsertHashTable(ht, *element);
		FreeData(element);
	}
}
bool InitializeFromCharArray(HashTable* ht, char** array, int size) {
	for (int i = 0; i < size; i++) {
		Data* element = InitData(CHAR_TYPE);
		strcpy(element->Char,  array[i]);
		InsertHashTable(ht, *element);
		FreeData(element);
	}
}

bool isElementInSet(HashTable* ht, Data element) {
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->next = NULL;
	newNode->value = element;
	int index = HashData(&element, ht->size);
	if (ht->array[HashData(&element, ht->size)] == NULL) return false;
	else if (ht->array[HashData(&element, ht->size)] != NULL) {
		if (element.type == FLOAT_TYPE) {
			if (ht->array[index]->value.Float == element.Float) {
				return true;
			}
		}
		else if (element.type == INT_TYPE) {
			if (ht->array[index]->value.Int == element.Int) {
				return true;
			}
		}
		else if (element.type == CHAR_TYPE) {
			if ((strcmp(ht->array[index]->value.Char, element.Char))) {
				return true;
			}
		}
	}
	return false;

}


