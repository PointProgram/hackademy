#include "../libft.h"
#include "../../../cunix/ex01/src/my_strlen.c"

char *ft_strjoin(char const *s1, char const *s2)
{
    int s_l1 = my_strlen((char *)s1), s_l2 = my_strlen((char *)s2), i = 0;
    char *s = (char *)malloc((s_l1 + s_l2) * sizeof(char) + 1);
    while (s1[i])
    {
        s[i] = s1[i];
        i++;
    }
    i = 0;
    while (s2[i])
    {
        s[s_l1 + i] = s2[i];
        i++;
    }
    s[s_l1 + s_l2] = '\0';
    if (!s)
    {
        return NULL;
    }
    return s;
}
