#include "hashtable.h"


Data* InitData(DataType type) {
	Data* data = (Data*)malloc(sizeof(Data));
	data->type = type;
	if (type == CHAR_TYPE) {
		data->Char = (char*)malloc(64 * sizeof(char));
	}
	
	return data;
}
void FreeData(Data* data){
	if (data->type == CHAR_TYPE) free(data->Char);
	free(data);
}
