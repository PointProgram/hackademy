#include "../include/test.h"

char *my_strcpy(char *dest, const char *src) 
{
	int index = 0;

	while(src[index] != '\0')
      	{
		dest[index] = src[index]; 
		index++;
	}
	dest[index] = '\0';
	return dest;
}	
