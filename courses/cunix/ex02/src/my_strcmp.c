#include "../include/test.h"

int my_strcmp(char *str1, char *str2) 
{
	int index = 0;

	while(str1[index] != '\0' && str2[index] != '\0') {
		if(str1[index] != str2[index]) 
		{
			if(str1[index] > str2[index]) 
			{
				return 1;
			}
			else
			{
				return -1;
			}
		}
		index++;
	}
	return 0;
}
