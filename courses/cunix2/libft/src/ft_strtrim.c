#include "../libft.h"

char *ft_strtrim(char const *s)
{
    short beg = 0, end = 0, beg_check = 1;
    int i = 0;
    while (s[i] != '\0')
    {
        end = i + 1;
        if (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
        {
            if (beg_check && beg == i)
            {
                beg = i + 1;
            }
            else
            {
                beg_check = 0;
                end = i;
                while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
                {
                    i++;
                }
            }
            if (s[i] == '\0')
            {
                continue;
            }
        }
        i++;
    }
    char *s_trim = (char *)malloc((i - beg - (i - end)) * sizeof(char) + 1);

    for (int j = beg, l = 0; j < end; j++, l++)
    {
        s_trim[l] = s[j]; 
    }
    s_trim[(i - beg - (i - end))] = '\0';
    return s_trim;
}
