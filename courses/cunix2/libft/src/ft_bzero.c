#include "../libft.h"

void ft_bzero(void *s, size_t n)
{
    char *array = (char *)s;
    size_t i = 0;
    while (i < n)
    {
        array[i++] = '\0';
    }
    s = &array;
}
