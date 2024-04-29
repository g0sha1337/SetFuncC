#include <stdio.h>
#include <stdlib.h>

#include "hashtable.h"

// ...

int main() {

    Data data;
    data.type = __int;
    data._int = 228;
    printf("Data - int = %d", data._int);  
    
    printf("\nhashed value = %u\n\n", md5hash(data));

    // ...
    
    //free(set); // Не забудьте освободить память
    return 0;
}
