/*
** EPITECH PROJECT, 2017
** print_func.c
** File description:
** the print functions for printf
*/

#include "printf_header.h"

int print_c(int c)
{
	write(1, &c , 1);
	return (0);
}

int print_d1(int nb)
{
	my_put_nbr(nb);
	return (0);
}

int print_u(unsigned int nb)
{
	if (nb > 9) {
		print_u(nb / 10);
		print_u(nb % 10);
	} else {
		nb += 48;
		write(1, &nb, 1);
	}
	return (0);
}

int print_ld(long nb)
{
	if (nb < 0) {
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb > 9) {
		print_ld(nb / 10);
		print_ld(nb % 10);
	} else {
		nb += 48;
		write(1, &nb, 1);
	}
	return (0);
}