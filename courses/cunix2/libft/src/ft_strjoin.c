#include "../libft.h"

char *ft_strjoin (char const *s1, char const *s2)
{
	int i = 0, j = 0, len = 0;

	for (; s1[i] != '\0'; i++)
	{
		len++;
	}

	for (; s2[j] != '\0'; j++)
	{
		len++;
	}
	
	char *s = (char *) malloc(len * sizeof(char) + 1);
	
	for (int l = i; l != 0; l--)
	{
		s[i - l] = s1[i -l];
	}
	for (int k = j; k != 0; k--)
	{
		s[j - k + i] = s2[j - k];
	}
	s[len] = '\0';
	if(s == NULL)
		return NULL;
	return s;
}
