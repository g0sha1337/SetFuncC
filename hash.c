#include "hash.h"
#include "hashtable.h"
unsigned int HashData(Data* data) {
	unsigned long result = 0;
	// my hashfunc 
	switch (data->type)
	{
	case CHAR_TYPE:
		for (int i = 0; i < strlen(data->Char); i++) {
			result += (int)data->Char[i] * i;
		}
		return result % HASHTABLE_SIZE;
	default:
		break;
	}




}