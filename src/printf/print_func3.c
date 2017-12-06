/*
** EPITECH PROJECT, 2017
** print_func3.c
** File description:
** the print functions for printf
*/

#include "printf_header.h"

int print_lu(unsigned long nb)
{
	if (nb > 9) {
		print_lu(nb / 10);
		print_lu(nb % 10);
	} else {
		nb += 48;
		write(1, &nb, 1);
	}
	return (0);
}

void print_s(char *nb)
{
	write(1, nb, my_strlen(nb));
}

int print_ss(char *nb)
{
	char c;

	for (int i = 0; i < my_strlen(nb); i++) {
		if (nb[i] < 32 || nb [i] >= 127) {
			write(1, "\\", 1);
			print_oct(nb[i]);
		} else {
			c = nb[i];
			write(1, &c, 1);
		}
	}
}

int get_bin_count(int bin)
{
	int a = bin;
	int b = 0;
	int c = 0;
	int counter = 0;
	char *str;

	while (a != 0) {
		b = a / 2;
		c = a - (b*2);
		a = b;
		counter++;
	}
	return (counter);
}
int print_binary(unsigned int bin)
{
	int a = bin;
	int b = 0;
	int c = 0;
	int counter = get_bin_count(bin);
	char *str = malloc(counter);

	counter = 0;
	while (a != 0) {
		b = a / 2;
		c = a - (b*2);
		a = b;
		str[counter] = c + 48;
		counter++;
	}
	counter--;
	while (counter >= 0) {
		c = str[counter];
		write(1, &c, 1);
		counter--;
	}
}