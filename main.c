#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hashtable.h"
#include "hash.h"
// ...

int main() {

    Data* data = InitData(FLOAT_TYPE);
    
    //strcpy(data->Char, "228");
    //printf("Data - char = %s", data->Char);  
    data->Float = 3.14159;
    printf("Data - int = %f", data->Float);
    
    printf("\nHashed value = %u\n\n", HashData(data));

    // ...
    FreeData(data);
    //free(set); // Не забудьте освободить память
    return 0;
}
