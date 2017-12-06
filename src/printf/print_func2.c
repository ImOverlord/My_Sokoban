/*
** EPITECH PROJECT, 2017
** print_func2.c
** File description:
** the print functions for printf
*/

#include "printf_header.h"

int get_count_oct(int oct)
{
	int a = oct;
	int b = 0;
	int c = 0;
	int counter = 0;
	char *str;

	while (a != 0) {
		b = a / 8;
		c = a - (b*8);
		a = b;
		counter++;
	}
	return (counter);
}

int print_oct(int oct)
{
	int a = oct;
	int b = 0;
	int c = 0;
	int counter = get_count_oct(oct);
	char *str = malloc(counter);

	counter = 0;
	while (a != 0) {
		b = a / 8;
		c = a - (b*8);
		a = b;
		str[counter] = c + 48;
		counter++;
	}
	counter--;
	while (counter >= 0) {
		char c = str[counter];
		write(1, &c, 1);
		counter--;
	}
}

int get_count_hex(int hex)
{
	int a = hex;
	int b = 0;
	int c = 0;
	int counter = 0;
	char *str;

	while (a != 0) {
		b = a / 16;
		c = a - (b*16);
		a = b;
		counter++;
	}
	return (counter);
}

void convert_hex_char(char *str, int cap)
{
	for (int i = 0; i < my_strlen(str); i++) {
		if (str[i] >= 58) {
			str[i] += (65-58) + cap;
		}
	}
}

int print_hex(int hex, int cap)
{
	int a = (hex < 0) ? hex * -1 : hex;
	int b = 0;
	int c = 0;
	int counter = 0;
	char *str = malloc(get_count_hex(a));

	while (a != 0) {
		b = a / 16;
		c = a - (b*16);
		a = b;
		str[counter] = c + 48;
		counter++;
	}
	counter--;
	convert_hex_char(str, cap);
	while (counter >= 0) {
		c = str[counter];
		write(1, &c, 1);
		counter--;
	}
}