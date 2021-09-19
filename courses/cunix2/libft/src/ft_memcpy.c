#include "../libft.h"

void *ft_memcpy(void *dest, const void *src, size_t n) 
{
	char *dest_ptr = dest;
        const char *source_ptr = src;
	for(size_t i = 0; i < n; i++)
	{
		*(dest_ptr+i) = *(source_ptr+i);
	}

	return dest;
}
