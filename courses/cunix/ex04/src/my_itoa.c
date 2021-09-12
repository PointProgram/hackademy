#include "../include/test.h"
#include <stdlib.h>

char* my_itoa(int nmb)
{
	int tenth = 1, res, len = 0;
	do
	{
		if (len > 0)
		{
			tenth *= 10;
		}
		res = nmb/tenth;
		len++;
	} while (res > 9 || res < -9);
	
	char *str;
	int index;
       	if (nmb >= 0)
	{
		str = malloc (len + 1);
		index = 0;
	}
	else
	{	
		str = malloc (++len + 2);
		str[0] = '-';
		index = 1;
	}
	
	int numb = nmb;
	for (; index < len; index++) 
	{
		res = numb/tenth;
		numb -= res*tenth;
		str[index] = ((res > 0) ? (res = res) : (res = - res)) + '0';
		tenth /= 10;
	}
	str[len] = '\0';
	return str;
}	
