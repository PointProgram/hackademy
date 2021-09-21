#include "../libft.h"

int ft_tolower(int ch) 
{
    return ((ch >= 'A' && ch <= 'Z') ? ch + 32 : ch); 
}
