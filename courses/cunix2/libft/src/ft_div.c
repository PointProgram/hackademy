#include "../libft.h"

div_t ft_div(int numer, int denom) 
{
	div_t div_val;
	div_val.quot = numer / denom; 
	div_val.rem = numer % denom;
	return div_val; 
}
