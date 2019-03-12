/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** CPool_Day08_2018
*/

#ifndef CPOOL_DAY08_2018_MY_H
#define CPOOL_DAY08_2018_MY_H

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

# ifndef READ_SIZE
    # define READ_SIZE (1)
# endif /* ! READ_SIZE */

int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_find_prime_sup(int nb);
int my_getnbr(char const *str);
int my_is_prime(int nb);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_putchar(char c);
int my_putstr(char const *str);
char *my_revstr(char *str);
int my_showmem(char const *str);
int my_showstr(char const *str);
int check_sort(int *array, int size);
void my_sort_int_array(int *tab, int size);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);
int my_str_isupper(char const *str);
char *mu_strcapitalize(char *str);
char *my_strcat(char *dest, char const *src);
char *my_mstrcat(char *dest, char *src, int freeable);
int my_strcmp(char const *s1, char const *s2);
int my_cstrcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strstr(char *str, char const *to_find);
char *my_strupcase(char *str);
void my_swap(int *a, int *b);
char *my_strdup(char const *src);
char *concat_params(int ac, char **av);
int my_show_word_array(char *const *tab);
char **alloc_dest(char **dest, char const *str);
char *clean_str(char *str);
char **my_str_to_word_array(char const *str);
char *convert_base(char const *nbr, char const *base_from,
    char const *base_to);
int is_alpha(char c);
int is_number(char c);
int my_sort_word_array(char **tab);
int my_advanced_sort_word_array(char **tab, int(*cmp)(char *const *,
    char const *));
int intlen(int nb);
char *int_to_char(int nb);
char *long_to_char(long int nb);
char *malloc_str(int len);
char *realloc_str(char *str, int len);
char **malloc_tab(int size, int columns);
char **realloc_tab(char **tab, int size);
char *my_addchar(char *, char, int);
char **my_addline(char **tab, char *str);
int search_char(char *str, char c);
int my_printf(char *, ...);
char *dec_to_oct_str(int nb);
char *get_int(char *str, va_list print);
char *get_string(char *str, va_list print);
char *get_char(char *str, va_list print);
char *get_bin(char *str, va_list print);
char *get_string_unprint(char *str, va_list print);
char *get_long(char *str, va_list print);
char *decimal_to_octal(char *str, va_list print);
char *dec_to_octal(int nb);
char *ui_to_bin(unsigned int nb);
char *get_u_dec(char *str, va_list print);
char *decimal_to_hexa(char *str, va_list print);
char *decimal_to_hexa_caps(char *str, va_list print);
char *add_percent(char *str, va_list print);
void free_tab(char **tab);
int tab_size(char **tab);
char **tab_dup(char **tab);

typedef struct data {
    va_list print;
    char *str;
    int i;
    char *result;
    char **list;
} data_t;

#endif /*CPOOL_DAY08_2018_MY_H*/
