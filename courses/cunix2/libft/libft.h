#ifndef LIBFT_H_
#define LIBFT_H_
#include <stddef.h>
#include <stdlib.h>

void ft_bzero (void *s, size_t n);
char *ft_strchr (const char *str, int c);
int ft_isalpha (int ch);
int ft_isdigit (int ch);
int ft_isascii (int ch);
int ft_toupper (int ch);
int ft_tolower (int ch);
int ft_abs (int x);
div_t ft_div(int numer, int denom);
char *ft_strstr (const char *haystack, const char *needle);
void *ft_memset (void *str, int c, size_t n);
void *ft_memcpy (void *dest, const void *src, size_t n);
int ft_memcmp (const void *str1, const void * str2, size_t n);
void ft_striter(char *s, void (*f)(char *));
char *(ft_strjoin (char const *s1, char const *s2));
char *(ft_strtrim(char const *s));
char **(ft_strsplit(char const *s, char c));

#endif
