/*
** EPITECH PROJECT, 2017
** sys_func.c
** File description:
** system calls
*/

#include "printf_header.h"

int my_strcmp(char const *s1, char const *s2)
{
	int counter = 0;

	while (s1[counter] != '\0' && s2[counter] != '\0') {
		if (s1[counter] == s2[counter]) {
			counter++;
		} else if (s1[counter] > s2[counter]) {
			return (1);
		} else {
			return (-1);
		}
	}
	return (0);
}

int my_strlen(char const *s)
{
	int len = 0;

	while (s[len] != '\0') {
		len++;
	}
	return (len);
}
int my_put_nbr(int nb)
{
	if (nb < 0) {
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb > 9) {
		my_put_nbr(nb / 10);
		my_put_nbr(nb % 10);
	} else {
		nb += 48;
		write(1, &nb, 1);
	}
	return (0);
}