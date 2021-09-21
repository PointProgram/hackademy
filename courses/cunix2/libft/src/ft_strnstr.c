#include "../libft.h"

char *ft_strnstr(const char *haystack, const char *needle, size_t n) 
{
	int index = 0, index2 = 0, pntr = -1;
	if(haystack[0] == '\0' || needle[0] == '\0')
	{
		return (char *) haystack;
	}
	for (index = 0; haystack[index] != '\0'; index++)
	{
		if(haystack[index] == needle[0])
		{
			pntr = index;
			for(++index, index2 = 1; index2  < (int)n;index++, index2++)
			{
				if(haystack[index] != needle[index2])
				{
					break;
				}	
			}
			if(needle[index2] == '\0')
			{
				return (char *) &haystack[pntr];
			}
		}
	}
	return NULL;
}
