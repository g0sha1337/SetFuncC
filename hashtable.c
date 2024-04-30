#include "hashtable.h"
#include <string.h>

Data* InitData(DataType type) {
	Data* data = (Data*)malloc(sizeof(Data));
	data->type = type;
	if (type == CHAR_TYPE) {
		data->Char = (char*)malloc(64 * sizeof(char));
	}
	
	return data;
}
void FreeData(Data* data) {
	if (data->type == CHAR_TYPE) free(data->Char);
	free(data);
}

HtItem* CreateItem (char* key, char* value){
	HtItem* item = (HtItem*) malloc(sizeof(HtItem));
	item->key = (char*)malloc(strlen(key)+1);
	item->value = (char*) malloc(strlen(value)+1);
	strcpy(item->key, key);
	strcpy(item->value, value);
	return item;
}

HashTable* CreateTable(int size){
	HashTable* table = (HashTable*)malloc(sizeof(HashTable));
	table->size = size;
	table->count = 0;
	table->items = (HtItem**) calloc(table->size, sizeof(HtItem*));

	for (int i =0; i<talbe->size; i++){
		table->items[i] = NULL;

	}
	return table;
}

void FreeItem(HtItem* item){
	free(item->key);
    free(item->value);
    free(item);
}

void FreeTable(HashTable* table){
	for (int i=0; i<table->size; i++){
		HtItem* item = table->items[i];
		if (item!=0) FreeItem(item);
	}
	free(table->items);
	free(table);
}


void PrintTable(HashTable* ht)
{
    printf("\nHash Table\n-------------------\n");

    for (int i = 0; i < ht->size; i++)
    {
        if (ht->items[i])
        {
            printf("Index:%d, Key:%s, Value:%s\n", i, ht->items[i] -> key, ht->items[i]->value);
        }
    }

    printf("-------------------\n\n");
}

