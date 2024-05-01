#pragma once
#include <stdlib.h>
#include <stdbool.h>
#include "data.h"
//Data



//HashTable
typedef struct Node {
    int key;                // ���� ����
    Data value;              // ��������, ��������� � ������
    struct Node* next;  // ��������� �� ��������� ������� � �������
} Node;

typedef struct HashTable { //hash table
    int size;        // ������ �������
    Node** array; // ������ ���������� �� �������� (����) �������
} HashTable;

bool EqualData(Data data1, Data data2);
HashTable* CreateHashTable(int size);
void freeHashTable(HashTable* ht, int size);
void InsertHashTable(HashTable* ht,  Data value);
bool removeElement(HashTable* ht, Data element);
void printSet(char* SetName, HashTable* ht);
//void printData(Data data);
//void printHashTable(HashTable* table);
bool InitializeFromIntArray(HashTable* ht, int* array, int size);
bool InitializeFromFloatArray(HashTable* ht, float* array, int size);
bool InitializeFromCharArray(HashTable* ht, char** array, int size);
bool isElementInSet(HashTable* ht, Data element);
