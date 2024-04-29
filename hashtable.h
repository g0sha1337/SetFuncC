#pragma once
#define HASH_MAP_SIZE 65536


typedef struct Data{
    enum type{
        __int, __char, __float
    }type;
    int _int;
    char _char[64];
    float _float;
} Data;



