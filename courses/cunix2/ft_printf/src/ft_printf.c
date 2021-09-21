#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "../../../cunix/ex04/src/my_atoi.c"
#include "../../../cunix/ex04/src/my_itoa.c"
#include "../../../cunix/ex01/src/my_strlen.c"

typedef enum flg {zero, plus, space} flags;

typedef struct
{
    int flag[3];
    int width;
    char type;
    
} specifiers;


specifiers specifiers_init(specifiers spec)
{
    spec.width = 0;
    for (int i = 0; i < 3; i++)
    {
        spec.flag[i] = 0;
    }
    spec.type = '\0';
    return spec;
}

int get_index(const char *s, char c, int index)
{
    while (s[index])
    {
        if (s[index] == c)
        {
            return index;
        }
        index++;
    }
    return index;
}

char *gt_ln(const char *s, int start, int len)
{
    char *mm = (char *)malloc((len - start) * sizeof(char) + 1);
    for (int i = start; i < len; i++)
    {
        mm[i - start] = s[i];
    }
    mm[len] = '\0';
    return mm;
}

char *concat(char *s1, char *s2)
{
    int ln = 0, s_len = (int)my_strlen(s1);
    
    while (s2[ln])
    {
        ln++;
    }

    char *p_str = (char *) malloc((s_len + ln) * sizeof(char) + 1);
    
    p_str = s1;
    
    int i = 0;
    while (s2[i] != 0)
    {
        p_str[s_len + i] = s2[i];
        i++;
    }   
    p_str[s_len + ln] = '\0';
    s_len += i;
    return p_str;
}

char *convert_type(specifiers specs, void *el)
{
    char *s;
    if (specs.type == 'c')
    {
        s = (char *)malloc(2 * sizeof(char));
        s[0] = *(char *)el;
        s[1] = '\0';
    }
    else if (specs.type == 's')
    {
        s = (char *)el;
        if (s == NULL)
        {
            s = (char *)malloc(6 * sizeof(char) + 1);
            s = "(null)";
        }
    }
    else if (specs.type == 'd' || specs.type == 'i')
    {
        s = my_itoa((*(int *)el));
    }
    char chr;
    int llls;
    if (specs.width > (int)my_strlen(s))
    {
        llls = specs.width - my_strlen(s);
    }
    else
    {
        llls = 0;
    }
    char *ps;
    if (specs.type == 'd' || specs.type == 'i')
    {
        chr = (specs.flag[0]) ? '0' : ' ';
        int i = 1;
        if (llls > 0)
        {
            ps = (char *)malloc(specs.width * sizeof(char) + 1);
        }
        else if ((specs.flag[1] || specs.flag[2]) && s[0] != '-')
        {
            ps = (char *)malloc(sizeof(char) + 1);
            llls++;
        }
        if ((specs.flag[1] || (specs.flag[1] && !specs.flag[2])) && s[0] != '-')
        {
            ps[0] = '+';
        }
        else if (specs.flag[2] && !specs.flag[1] && s[0] != '-')
        {
            ps[0] = ' ';
        }
        else if (specs.flag[0] && s[0] == '-' && llls > 0)
        {
            ps[0] = '-';
            s[0] = '0';
        }
        else
        {
            i = 0;
        }
        if (llls > 0)
        {
            while (i < llls)
            {
                ps[i] = chr;
                i++;
            }
            ps[llls] = '\0';
            s = concat(ps, s);
        }
    }
    else
    {
        if (llls > 0)
        {
            ps = (char *)malloc(specs.width * sizeof(char) + 1);
            for (int i = 0; i < llls; i++)
            {
                ps[i] = ' ';
            }
            ps[llls] = '\0';
            s = concat(ps, s);
        }
        
    }
    
     return s;
}

specifiers check_flag(specifiers spec, const char *s_code, int *ind)
{
    while (s_code[*ind])
    {
        if (s_code[*ind] == '0')
        {
            spec.flag[0]++;
        }
        else if (s_code[*ind] == '+')
        {
            spec.flag[1]++;
        }
        else if (s_code[*ind] == ' ')
        {
            spec.flag[2]++;
        }
        else if (spec.flag[0] > 1 || spec.flag[1] > 1 || spec.flag[2] > 2)
        {
            exit(1);
        }
        else
        {
            break;
        }
        (*ind)++;
    }
    
    return spec;
}

int ft_printf(const char *format, ...)
{
    va_list arg_list;
    const char *format_code;
    char *get_s = (char *)malloc(sizeof(char)), *conv;
    va_start(arg_list, format);
    int i = 0, num;
    format_code = format;
    get_s[0] = '\0';
    while (format_code[i])
    {
        num = get_index(format_code, '%', i);
        get_s = concat(get_s, gt_ln(format_code, i, num));
        specifiers spec = specifiers_init(spec);
        i = num;
        if (format_code[num] != '\0')
        {
            i++;
            
            if (format_code[i] == '%')
            {
                get_s = concat(get_s, "%");
                i++;
                continue;
            }
            else
            {
                int j = i;
                while (format_code[j] >= '0' && format_code[j] <= '9')
                {
                    j++;
                }
                if (format_code[j] == '%')
                {
                    get_s = concat(get_s, "%");
                    i = j + 1;
                    continue;
                }
            }
            spec = check_flag(spec, format_code, &i);
	    
            if (format_code[i] > '0' && format_code[i] <= '9')
            {
                int len = 1;
                i++;
		
                while (format_code[i] >= '0' && format_code[i] <= '9')
                {
                    len++;
                    i++;
                }
                char *number = (char *)malloc(len * sizeof(char) + 1);
                for (int l = 0; len != 0; len--, l++)
                {
                    number[l] = format_code[i - len];
                }
                spec.width = my_atoi(number);
            }
            
            if (format_code[i] == 'c')
            {
                spec.type = 'c';
		char c = va_arg(arg_list, int);
                conv = convert_type(spec, &c);
                i++;
            }
            else if (format_code[i] == 's')
            {
                spec.type = 's';
                conv = convert_type(spec, va_arg(arg_list, char *));
                i++;
            }
            else if (format_code[i] == 'd')
            {
                spec.type = 'd';
		int d = va_arg(arg_list, int);
                conv = convert_type(spec, &d);
                i++;
            }
            else if (format_code[i] == 'i')
            {
                spec.type = 'i';
		int i_t = va_arg(arg_list, int);
                conv = convert_type(spec, &i_t);
                i++;
            }
            get_s = concat(get_s, conv);
        }
    }
    va_end(arg_list);
    write(1, get_s, my_strlen(get_s));
    return 1;
}
