#define _CRT_SECURE_NO_WARNINGS
#include <malloc.h>
#include <string.h>

#include "hashtable.h"
#include "hash.h"

bool EqualData(Data data1, Data data2) {
	if (data1.type == data2.type) {
		if (data1.type == FLOAT_TYPE) {
			return data1.Float == data2.Float;
		}
		else if (data1.type == INT_TYPE) {
			return data1.Int == data2.Int;
		}
		else if (data1.type == CHAR_TYPE) {
			return strcmp(data1.Char, data2.Char) == 0;
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
// code inspection
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
		
		if (curr->next != (void*)0) { //yaya ima stupid prog kid that likes bad code

			prev = curr;
			curr = curr->next;
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
	int index = HashData(&element, ht->size);

	Node* temp = ht->array[index];


	while (temp != NULL) {



		if (temp->value.type == element.type) {
			if (element.type == FLOAT_TYPE) {
				return temp->value.Float == element.Float;
			}
			if (element.type == INT_TYPE) {
				return temp->value.Int == element.Int;
			}
			if (element.type == CHAR_TYPE) {
				return strcmp(temp->value.Char, element.Char) == 0;
			}
		}
		else if (temp->next != NULL) {
			temp = temp->next;
		}
		else if (temp = NULL) break;
		else break;
	}
	//if (ht->array[index] == NULL) printf("\n\n\n\nht->array[i] == NULL  --->  TRUE\n\n");
	return false;
}


HashTable* MergeHashTables(HashTable* ht1, HashTable* ht2) {
	HashTable* result = CreateHashTable(ht1->size + ht2->size);

	for (int i = 0; i < ht1->size; i++) {
		if (ht1->array[i] != NULL) InsertHashTable(result, ht1->array[i]->value);
	}
	for (int i = 0; i < ht2->size; i++) {
		if (ht2->array[i] != NULL) InsertHashTable(result, ht2->array[i]->value);
	}

	return result;
}