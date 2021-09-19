#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

//write
//malloc
//free
//exit
//stdarg
//
//conv c, s, d, i
//man %%
//flags 0, +, space
//man minimum field-width
//

void format_specifier(const char *s)
{
	int i = 0;
	//%flags/width/specifier
	while(s[i])
	{
		if(s[i] == '%')
		{

		}
	}
}

int len(const char * s)
{
	int i = 0;
	while(s[i++])
	{
		;
	}
	return i;
}
int get_len(const char *format, char c)
{
	int i = 0;
	while(s[i])
	{
		if(s[i] == c)
		{
			return i;
		}	
		i++;
	}
	return -1;
}

char *concat(char *s1, char *s2)
{

}
int ft_printf(const char * format, ...)
{
	va_list arg_list;
	const char *format_code;
	
	va_start(arg_list, format);
	int i = 0;
	format_code = format;
	while (format_code[i])
	{
		i++;
		write(1, format_code[i], 1);
	}

	va_end(arg_list);
	return 1;
}
