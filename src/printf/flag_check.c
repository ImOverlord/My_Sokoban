/*
** EPITECH PROJECT, 2017
** flag_check.c
** File description:
** functions to check flags
*/

#include "printf_header.h"

int is_a_flag(char c)
{
	char *flags= "%dscbSiboxXup";

	for (int i = 0; i < my_strlen(flags); i++) {
		if (c == flags[i])
			return (1);
	}
	return (0);
}
int is_a_2_flag(char a, char b)
{
	char *flags = "ldlu";

	for (int i = 0; i < my_strlen(flags); i+= 2) {
		if (a == flags[i] && b == flags[i + 1])
			return (1);
	}
	return (0);
}