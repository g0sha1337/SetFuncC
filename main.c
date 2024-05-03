#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "data.h"
#include "hashtable.h"
#include "hash.h"
#include "frontend.h"


int main() {
    int size = 16;

    Data* data = InitData(FLOAT_TYPE);
   
    
    //strcpy(data->Char, "228");
    //printf("Data - char = %s", data->Char);  
    data->Float = 0.234;
    printf("Data - int = %f", data->Float);
    
    printf("\nHashed value = %u\n\n", HashData(data, size));


    Data* data2 = InitData(INT_TYPE);
    data2->Int = 228;
    Data* data3 = InitData(INT_TYPE);
    data3->Int = 229;
    Data* data4 = InitData(CHAR_TYPE);
    strcpy(data4->Char, "some_words123");
    HashTable* hashtable = CreateHashTable(size);

    InsertHashTable(hashtable, *data2);
    InsertHashTable(hashtable, *data3);
    InsertHashTable(hashtable, *data);
    InsertHashTable(hashtable, *data4);

    //removeElement(hashtable, *data);
    //removeElement(hashtable, *data2);
    //removeElement(hashtable, *data3);
    if (isElementInSet(hashtable, *data4)) {
        printf("YES!!!!\n");
    } else printf("No.\n\n");
    printSet("A", hashtable);
    printHashTable(hashtable);
    

    /*InputIntArray();*/

    /*if (isElementInSet(hashtable, *data)) {
        printf("data exist in hashtable");
    }
    else {
        printf("data not found");
    }*/
    FreeData(data);
    freeHashTable(hashtable, size);
    return 0;
}
