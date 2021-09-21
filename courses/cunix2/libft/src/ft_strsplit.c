#include "../libft.h"

const char *find_lim(const char *s, char c, int index)
{
    int i = 0;
    if (s[0] != c)
    {
        return s;
    }
    while (s[i])
    {
        if (s[i] == c && s[i + 1] != c && s[i + 1 != '\0' && i >= index])
        {
            return (char *)&s[i + 1];
        }
        i++;
    }
    return s;
}

char **ft_strsplit(char const *s, char c)
{
    int i = 0, len = 0, delim = 0, sep_cnt;
    char **split_arr;
    const char *qq;

    while (s[i])
    {
        if (s[i] == c)
        {
            if (s[i + 1] != c && s[i + 1] != '\0')
            {
                delim++;
            }
        }
        i++;	    
    }
    if (s[i] == c)
    {
        delim = 1;
    }
    if (delim == 0 && len != i)
    {
        split_arr = (char **)malloc(sizeof(char *));
        split_arr[0] = (char *)malloc(sizeof(char));
        split_arr[0] = (char *)s;
        return split_arr;
    }
    split_arr = (char **)malloc(sizeof(char *));

    for (i = 0; i < delim; i++)
    {
        split_arr[i] = (char *)malloc(sizeof(char));
    }
    sep_cnt = 0;
    int j = 0;
    while (delim != 0)
    {
        int jj = 0;
        qq = find_lim(s, c, j);

        while (qq[jj] != c)
        {
            if (qq[jj] == '\0')
            {
                break;
            }
            j++;
            jj++;
        }
        char *sl = (char *)malloc(jj * sizeof(char) + 1);
        ft_memcpy(sl, qq, jj);
        sl[jj] = '\0';
        split_arr[sep_cnt] = sl;
        sep_cnt++; 
        delim--;
    }
    //free(qq);
    return split_arr;
}
