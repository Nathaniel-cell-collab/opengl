/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** jsp
*/
#ifndef MY_H_
    #define MY_H_
    #include <stdarg.h>
    #include <stdio.h>
int my_strcmp_all_case(char const *s1, char const *s2);
void *my_memcpy(void *dest, void *src, int len);
void *my_memset(void *ptr, int set, int size);
void *my_calloc(void *op, int set, int size);
int my_str_is_alpha_and(char *str, char c);
int my_is_alpha(char c);
int my_isdigit(char c);
char *my_str_change_char(char *str, char to_change, char for_change);
void print_tab(char **tab);
int my_strncmp(char const *s1, char const *s2, int size);
void my_free_array(char **array);
int my_datecmp(char const *path, char *file1, char *file2);
int my_isalphanum(char c);
int my_len_array(char **array);
int check_flags(char *flags);
int is_instr(char *str, char c);
char **my_evil_array(char **array);
char *my_str_lower_case(char *str);
char **my_sort_array(char **array);
int my_strcmp(char const *s1, char const *s2);
char **my_str_to_word_array(char const *str, char sep);
char *my_strndup(char const *src, int start, int end);
void my_strncat(char *dest, char const *src, int nb);
void digit_flag_conditions(char const *format, int *pp, int *pn, int count);
int my_put_unsigned_va(va_list list, ...);
int my_put_unsigned(unsigned int nb);
int my_getnbr(char const *str, int p);
int char_isdigit(char a);
int len_nbr(int nb);
int my_putnbr_base(unsigned nbr, char const *base);
int my_put_adress(long unsigned nbr);
int my_strlen(char const *str);
int my_printf(char const *format, ...);
int my_put_nbr(int nb);
int my_put_float(double fl, int n);
int my_putstr(char *str);
int my_putchar(int c);
int my_put_adress_va(va_list list, ...);
int my_putchar_va(va_list list, ...);
int my_putstr_va(va_list list, ...);
int my_put_nbr_va(va_list list, ...);
int my_put_float_va(va_list list, ...);
int is_binary_va(va_list list, ...);
int is_octal_va(va_list list, ...);
int is_hexlower_va(va_list list, ...);
int is_hexupper_va(va_list list, ...);
char *my_strdup(char const *src);
char *my_strcpy(char *dest, char *src);
char *get_full_path(char *dir, char *exec);
#endif
