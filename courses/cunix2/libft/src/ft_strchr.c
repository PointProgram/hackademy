#include "../libft.h"

char *ft_strchr(const char *str, int c)
{
    int index = 0;
    while (str[index])
    {
        if (str[index] == (char)c)
        {
            return (char *) &str[index];
        }
        index++;
    }
    if (c == '\0')
    {
        return (char *)&str[index];
    }
    return  NULL;
}
