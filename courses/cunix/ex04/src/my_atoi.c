#include "../include/test.h"

int tenth_part(int power)
{
	int number = 1;

	for(int i = 0; i < power - 1; i++) 
	{
		number *= 10;
	}
	return number; 
}

int my_atoi(const char *nptr)
{
	int len = 0, index, sum = 0, neg_check = 0;
	for(index = 0; nptr[index] != '\0'; index++)
	{
		if(index == 0 && nptr[index] == '-')
		{
			neg_check = 1;
			continue;
		}
		if(nptr[index] < '0' || nptr[index] > '9')
		{
			break;
		}
		len++;
	}
	(neg_check) ? (index = 1) : (index = 0);

	while(len != 0) 
	{
		sum += (nptr[index++] - '0') * tenth_part(len);
		len--;
	}
	
	return (neg_check) ? -sum : sum;
}
