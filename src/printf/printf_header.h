/*
** EPITECH PROJECT, 2017
** print_header.h
** File description:
** Header file for printf
*/

#ifndef MY_PRINTF_H_
#define MY_PRINTF_H_

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int print_c(int c);
int print_d1(int nb);
int print_u(unsigned int nb);
int print_ld(long nb);
int get_count_oct(int oct);
int print_oct(int oct);
int get_count_hex(int hex);
void convert_hex_chat(char *str, int cap);
int print_hex(int hex, int cap);
int print_lu(unsigned long nb);
void print_s(char *nb);
int print_ss(char *nb);
int get_bin_count(int bin);
int print_binary(unsigned int bin);
int is_a_flag(char c);
int is_a_2_flag(char a, char b);
void print_flag(char s, int flag);
void double_print_flag(char s, long flag);
void my_printf(char *str, ...);
int my_put_nbr(int nb);
int my_strlen(char const *s);
int my_strcmp(char const *s1, char const *s2);
#endif