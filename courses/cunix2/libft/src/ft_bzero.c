#include "../libft.h"

void ft_bzero(void *s, size_t n)
{
	char *array = (char *)s;
	for(size_t i = 0; i < n; i++)
	{
		array[i] = '\0';
	}
	s = &array;
}
