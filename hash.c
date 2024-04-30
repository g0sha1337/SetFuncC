#include <string.h>
#include "hash.h"
#include "hashtable.h"
unsigned int HashData(Data* data) {

	unsigned long hashed = 0;
	unsigned int magic = 1337; //some magic number of hash func

	switch (data->type){
		case INT_TYPE:
			
			hashed = magic * (unsigned int)data->Int;
			break;
		case CHAR_TYPE:
			//printf("\nPered whilom\n\n");
			for (int i =0; i<strlen((char*) data->Char);i++){
				hashed = hashed * magic+ (unsigned int)((char*)data->Char)[i];
			}
			break;
		case FLOAT_TYPE:
			hashed = magic * (unsigned int)((float)data->Float * 100000000);
			break;
		default:
			//printf("Some error with hashing: wrong type..");
			//exit(-1);
			break;
	}
	return hashed < HASHTABLE_SIZE ? hashed : hashed % HASHTABLE_SIZE;
}