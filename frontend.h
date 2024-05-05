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
void printNode(SetNode* node);
void printList(ListOfSets* list);
int MainMenuOptions();
void OptionPeekedMenu(int key, ListOfSets* list);
bool SetOptinsMunu(ListOfSets* list, int index);
