
#include <openssl/md5.h>
#include <stdbool.h>
#include "hashtable.h"


// Функция для создания пустого множества
Data* set_create() {
    Data *set = malloc(HASH_MAP_SIZE* sizeof(Data));
    return set;
}


unsigned int md5hash(Data data){
    // return index of our array (hashtable) 

    unsigned char md5result[MD5_DIGEST_LENGTH]; 
    if (data.type == 0){
        char buffer[20]; // Достаточно большой, чтобы удержать любое значение int
        sprintf(buffer, "%u", data._int);

        // Создаем массив для хранения результата MD5
        unsigned char digest[MD5_DIGEST_LENGTH];
        MD5((unsigned char*)buffer, strlen(buffer), digest);

        // Конвертируем последние 4 байта MD5 в unsigned int
        unsigned int hash_value;
        memcpy(&hash_value, &digest[MD5_DIGEST_LENGTH - sizeof(unsigned int)], sizeof(unsigned int));
        
        return hash_value;

    } else if (data.type == 1){
        unsigned char digest[MD5_DIGEST_LENGTH];
        MD5((unsigned char*)data._char, strlen(data._char), digest);

        // Преобразуем последние 4 байта MD5 в unsigned int
        unsigned int hash_value;
        memcpy(&hash_value, &digest[MD5_DIGEST_LENGTH - sizeof(unsigned int)], sizeof(unsigned int));

        return hash_value;


    } else {
        char buffer[40]; 
        sprintf(buffer, "%f", data._float);

        // Вычисляем MD5
        unsigned char digest[MD5_DIGEST_LENGTH];
        MD5((unsigned char*)buffer, strlen(buffer), digest);

        // Преобразуем последние 4 байта MD5 в unsigned int
        unsigned int hash_value;
        memcpy(&hash_value, &digest[MD5_DIGEST_LENGTH - sizeof(unsigned int)], sizeof(unsigned int));

        return hash_value;
    }


    return -1; // if something went wrong
}
