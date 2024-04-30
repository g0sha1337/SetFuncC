//#include <openssl/md5.h>
//#include <stdbool.h>
#include "hashtable.h"

#define MD5_DIGEST_LENGTH 32

Data* InitData(DataType type) {
	Data* data = (Data*)malloc(sizeof(Data));
	data->type = type;
	if (type == CHAR_TYPE) {
		data->Char = (char*)malloc(64 * sizeof(char));
	}
	
	return data;
}

