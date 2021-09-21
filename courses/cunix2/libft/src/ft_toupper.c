#include "../libft.h"

int ft_toupper(int ch) 
{
    return ((ch >= 'a'  && ch <= 'z') ? ch - 32 : ch); 
}
