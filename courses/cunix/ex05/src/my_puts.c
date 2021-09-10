#include "../include/test.h"
#include <unistd.h>
#include <stdlib.h>

int my_puts (const char *s)
{
	int len = 0, ind = 0;
	for ( int i = 0; s[i] != '\0'; i++)
	{
		len++;
	}
	char *tmp = malloc (len + 1);

	while(s[ind] != '\0')
       	{
		tmp[ind] = s[ind];
		ind++;
	}
	tmp[len] = '\n';	
	return write(1, tmp, len + 1);
}
