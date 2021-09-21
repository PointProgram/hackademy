#include "../include/test.h"

unsigned int my_strlen(char* str) {
	unsigned int i = 0;

	while(str[i]) {
		i++;
	}
	return i;
}
