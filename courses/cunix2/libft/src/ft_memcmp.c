#include "../libft.h"

int ft_memcmp(const void *str1, const void *str2, size_t n) 
{
	const char *s1 = str1, *s2 = str2;
	for(size_t i = 0; i < n; i++)
	{
		if (*(s1+i) != *(s2+i))
		{
			if (*(s1 + i) < *(s2 + i))
			{
				return 1;
			}
			else
			{
				return -1;
			}
		}
	}

	return 0;
}
