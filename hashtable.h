#pragma once
#define DEFAULT_HASH_TABLE_SIZE 10000


typedef struct {
    union hashtable
    {
        int _int;
        char _char;
        float _float;
    };
} data;

typedef struct Entry{
    char* Key; 
    data Data;
    Entry* next;
} Entry;

typedef struct HashTable {
    Entry *entries[DEFAULT_HASH_TABLE_SIZE];
} HashTable;


