#include "../libft.h"

char ** ft_strsplit (char const *s, char c)
{
	int i = 0, len = 0, delim = 0;
	char **split_arr;
	while(s[i])
	{
		len++;
	}
	while(s[i])
	{
		if (s[i] == c && s[i+1] != c)
		{
			delim++;
		}
	}
	split_arr = (int **)malloc(sizeof(int *));
	char **pp, *qq;
	for (i = 0; i < 1; i++)
	{
		arr[i] = (int *)malloc(delim * sizeof(int));
	}
	int sep_cnt = 0;
	while (delim != 0)
	{
		//if (f[i] == c && s[i + 1] !=c)
		//{

		//}
		qq = ft_strchr( s, c);

		*qq = '\0';

		split_arr[sep_cnt] = qq;
		sep_cnt++;
	}
	return split_arr;
}
