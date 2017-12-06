/*
** EPITECH PROJECT, 2017
** printf.c
** File description:
** functions to calls flags
*/

#include "printf_header.h"

void print_flag_string(char s, int flag)
{
	if (s == 'p') {
		write(1, "0x", 2);
		print_hex(flag, 97-65);
	}
	if (s == 's')
		print_s(flag);
	if (s == 'S')
		print_ss(flag);
}

void print_flag(char s, int flag)
{
	if (s == 'd')
		print_d1(flag);
	if (s == 'c')
		print_c(flag);
	if (s == 'i')
		print_d1(flag);
	if (s == 'b')
		print_binary(flag);
	if (s == 'o')
		print_oct(flag);
	if (s == '%')
		write(1, &s, 1);
	if (s == 'X')
		print_hex(flag, 0);
	if (s == 'x')
		print_hex(flag, 97-65);
	if (s == 'u')
		print_u(flag);
	print_flag_string(s, flag);
}

void double_print_flag(char s, long flag)
{
	if (s == 'd')
		print_ld(flag);
	if (s == 'u')
		print_lu(flag);
}

void my_printf( char *str, ... )
{
	va_list arguments;
	char c;

	va_start ( arguments, str );
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == '%' && is_a_flag(str[i + 1])) {
			print_flag(str[i + 1], va_arg (arguments, char*));
			i++;
		} else if (str[i] == '%' &&
		is_a_2_flag(str[i + 1], str[i + 2])) {
			double_print_flag(str[i + 2], va_arg(arguments, long));
			i += 2;
		} else {
			c = str[i];
			c = (c != '%') ?  c : 0;
			write(1, &c, 1);
		}
	}
	va_end (arguments);
}