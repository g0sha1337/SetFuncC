#include <stdio.h>
#include <stdlib.h>

#include "hashtable.h"
#include "hash.h"
// ...

int main() {

    Data* data = InitData(CHAR_TYPE);
    
    strcpy(data->Char, "228");
    printf("Data - chae = %s", data->Char);  
    
    printf("\nhashed value = %u\n\n", hash_data(data));

    // ...
    
    //free(set); // Не забудьте освободить память
    return 0;
}
