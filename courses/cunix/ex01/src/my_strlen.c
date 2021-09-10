#include "../include/test.h"

unsigned int my_strlen(char* str) {
	unsigned int len = 0;

	for(unsigned int index_len = 0; str[index_len] != '\0'; index_len++) {
		len++;
	}
	return len;
}
