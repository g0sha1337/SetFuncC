#pragma once
#define HASHTABLE_SIZE 65536 //2**16

//Data
typedef enum {
    INT_TYPE, CHAR_TYPE, FLOAT_TYPE
} DataType;

typedef struct Data{
    DataType type;
    int Int;
    char* Char;
    float Float;
} Data;


//HashTable

typedef struct HtItem{
    char* key; 
    char* value;
} HtItem;

typedef struct HashTable{
    HtItem** items;
    int size;
    int count;
} HashTable;

HtItem* CreateItem(char* key, char* value);
HashTable* CreateTable(int size);



Data* InitData(DataType type);
void FreeData(Data* data);
void FreeItem(HtItem* item);
void FreeTable(HashTable* table);
void PrintTable(HashTable* ht);
