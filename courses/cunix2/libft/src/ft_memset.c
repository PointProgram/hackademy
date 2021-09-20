#include "../libft.h"

void *ft_memset(void *str, int c, size_t n) 
{
	char *s_ptr = str;
	for(size_t i = 0; i < n; i++)
	{
		*(s_ptr+i) = (char) c;
	}	
	return str;
}
