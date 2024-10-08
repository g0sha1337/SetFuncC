#pragma once
typedef enum {
    INT_TYPE, CHAR_TYPE, FLOAT_TYPE
} DataType;

typedef struct Data {
    DataType type;
    int Int;
    char* Char;
    float Float;
} Data;



Data* InitData(DataType type);
void FreeData(Data* data);