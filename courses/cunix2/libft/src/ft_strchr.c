#include "../libft.h"

char *ft_strchr(const char *str, int c)
{
	int index = 0;
	for (index = 0; str[index] != '\0'; index++)
	{
		if(str[index] == (char)c)
		{
			return (char *) &str[index];
		}
		
	}
	return (c == '\0') ? (char *) &str[index] : NULL;
}
