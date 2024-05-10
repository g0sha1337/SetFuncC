#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
#include "manager.h"
#include "data.h"
#include "hashtable.h"

void printData(Data data);
void printShortData(Data data);
void printHashTable(HashTable* table);
void printSet(HashTable* ht, char* SetName);
void AskNameOfSet(char* str);
void printNode(SetNode* node, bool ShowHashTable);
void printList(ListOfSets* list);
int MainMenuOptions();
void OptionPeekedMenu(int key, ListOfSets* list);
bool SetOptinsMunu(ListOfSets* list, int index);
bool InputNewElement(HashTable* ht);
bool DeleteElement(HashTable* ht);
bool ProcessTwoSets(ListOfSets* list, int index1, int index2);
SetNode MergeTwoSets(SetNode* Set1, SetNode* Set2);
SetNode IntersectTwoSets(SetNode* set1, SetNode* set2);
SetNode DifferenceTwoSets(SetNode* set1, SetNode* set2);