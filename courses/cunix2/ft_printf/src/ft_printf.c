#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

typedef enum flg {zero, plus, space} flags;

typedef struct
{
    int flag[3];
    int width;
    char type;
    
} specifiers;

int tenth_part(int power)
{
	int number = 1;

	for(int i = 0; i < power - 1; i++) 
	{
		number *= 10;
	}
	return number; 
}

int my_atoi(const char *nptr)
{
	int len = 0, index, sum = 0, neg_check = 0;
	for(index = 0; nptr[index] != '\0'; index++)
	{
		if(index == 0 && nptr[index] == '-')
		{
			neg_check = 1;
			continue;
		}
		if(nptr[index] < '0' || nptr[index] > '9')
		{
			break;
		}
		len++;
	}
	(neg_check) ? (index = 1) : (index = 0);

	while(len != 0) 
	{
		sum += (nptr[index++] - '0') * tenth_part(len);
		len--;
	}
	
	return (neg_check) ? -sum : sum;
}

specifiers specifiers_init(specifiers spec)
{
    spec.width = 0;
    for(int i = 0; i < 3; i++)
    {
        spec.flag[i] = 0;
    }
    spec.type = '\0';
    return spec;
}

int my_strlen(char *s)
{
    int i = 0;
    while(s[i])
    {
        i++;
    }
    return i;
}

int get_index(const char *s, char c, int index)
{
    while(s[index])
    {
        if (s[index] == c)
        {
            return index;
        }
        index++;
    }
    return index;
}

char* my_itoa(int nmb)
{
	int tenth = 1, res, len = 0;
	do
	{
		if (len > 0)
		{
			tenth *= 10;
		}
		res = nmb/tenth;
		len++;
	} while (res > 9 || res < -9);
	
	char *str;
	int index;
       	if (nmb >= 0)
	{
		str = malloc (len + 1);
		index = 0;
	}
	else
	{	
		str = malloc (++len + 2);
		str[0] = '-';
		index = 1;
	}
	
	int numb = nmb;
	for (; index < len; index++) 
	{
		res = numb/tenth;
		numb -= res*tenth;
		str[index] = ((res > 0) ? (res = res) : (res = - res)) + '0';
		tenth /= 10;
	}
	str[len] = '\0';
	return str;
}

char *gt_ln(const char* s, int start, int len)
{
    char *mm = (char *)malloc((len - start)*sizeof(char) + 1);
    for(int i = start; i < len; i++)
    {
        mm[i-start] = s[i];
    }
    mm[len] = '\0';
    return mm;
}

char *concat(char *s1, char *s2)
{
    int ln = 0, s_len = my_strlen(s1);
    while(s2[ln])
    {
        ln++;
    }

    char *p_str = (char *) malloc((s_len + ln)*sizeof(char) + 1);
    
    p_str = s1;
    
    int i = 0;
    while(s2[i] != 0)
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
    switch(specs.type)
    {
        case 'c':
            s = (char *)malloc(2* sizeof(char));
            s[0] = *(char *)el;
            s[1] = '\0';
            printf("{Urt %c}\n", *(char *)el);
            break;
        case 's':
            s = (char *)el;
            printf("{Urt %s}\n", (char *)el);
            break;
        case 'd':
        case 'i':
            s = my_itoa((*(int *)el));
            printf("{Urt %d}\n", *(int *)el);
            break;
    }
    char chr;
    int llls;
    if(specs.width > my_strlen(s))
        llls = specs.width - my_strlen(s);
    else
        llls = 0;
    char *ps;
    if (specs.type == 'd' || specs.type == 'i')
    {
        chr = (specs.flag[0]) ? '0' : ' ';
        int i = 1;
        if (llls > 0)
            ps = (char *)malloc(specs.width * sizeof(char) + 1);
        else if(specs.flag[1] || specs.flag[2])
        {
            ps = (char *)malloc(sizeof(char) + 1);
            llls++;
        }
        if(specs.flag[1] || (specs.flag[1] && !specs.flag[2]))
        {
            ps[0] = '+';
           
        }
        else if (specs.flag[2] && !specs.flag[1])
        {
            ps[0] = ' ';
        }
        else
        {
            i = 0;
        }
        if (llls > 0)
        {
         for(; i < llls; i++)
            {
                ps[i] = chr;
            }
            ps[llls] = '\0';
            s = concat(ps, s);
        }
    }
    else
    {
        if(llls > 0)
        {
            ps = (char *)malloc(specs.width * sizeof(char) + 1);
            for(int i = 0; i < llls; i++)
            {
                ps[i] = ' ';
            }
            ps[llls] = '\0';
            s = concat(ps, s);
        }
        
    }
    
    
    //printf("\nString is |%s|", s);
    return s;
}

specifiers check_flag(specifiers spec, const char *s_code, int *ind)
{
    while(s_code[*ind])
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
            //printf("Error specifiers expanded!\n");
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
    //get_s[0] = '\0';
    while (format_code[i])
    {
        num = get_index(format_code, '%', i);
        char *wtf = gt_ln(format_code, i, num);
        get_s = concat(get_s, gt_ln(format_code, i, num));
        specifiers spec = specifiers_init(spec);
        i = num;
        if (format_code[num] != '\0')
        {
            int ind = num;
            i++;
            
            if(format_code[i] == '%')
            {
                get_s = concat(get_s, "%");
                i++;
                continue;
            }

            spec = check_flag(spec, format_code, &i);

            if(format_code[i] > '0' && format_code[i] <= '9')
            {
                int len = 1, beg = i;
                i++;
                
                while (format_code[i] >= '0' && format_code[i] <= '9')
                {
                    len++;
                    i++;
                }
                char *number = (char *)malloc(len * sizeof(char) + 1);
                for(int l = 0; len != 0; len--, l++)
                {
                    number[l] = format_code[i - len];
                }
                spec.width = my_atoi(number);
                //printf("\nnum is %d and flag %d\n", spec.width, spec.flag);
            }
            
            if (format_code[i] == 'c')
            {
                spec.type = 'c';
                int ch = va_arg(arg_list, int);
                //get_s = concat(gt_ln(format_code, ind), "hh", &ind);
                //printf("|\nch format %c\n %s \n- ind %d\n|", ch, concat(gt_ln(format_code, ind), "hh", &ind), ind);
                conv = convert_type(spec, &ch);
                i++;
            }
            else if (format_code[i] == 's')
            {
                 spec.type = 's';
                char *ss = va_arg(arg_list, char *);
                //if()
                //printf("\nss format %s\n", ss);
                conv = convert_type(spec, ss);
                i++;
            }
            else if (format_code[i] == 'd')
            {
                spec.type = 'd';
                int ii = va_arg(arg_list, int);
                //printf("\nii format %d\n", ii);
                conv = convert_type(spec, &ii);
                i++;
            }
            else if (format_code[i] == 'i')
            {
                spec.type = 'i';
                int iii = va_arg(arg_list, int);
                //printf("\niii format %d\n", iii);
                conv = convert_type(spec, &iii);
                i++;
            }
            get_s = concat(get_s, conv);
        }
        
        //i++;
    }
    va_end(arg_list);
    write(1, get_s, my_strlen(get_s));
    return 1;
}
