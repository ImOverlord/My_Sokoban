/*
** EPITECH PROJECT, 2017
** my_sokoban.c
** File description:
** main function
*/

#include "./printf/printf_header.h"
#include "../include/my_sokoban.h"
#include "../include/function_header.h"

int main(int ac, char *argv[])
{
	char *map_main;
	char *backup_map;
	int reset = 1;

	if (ac == 1)
		no_arguments();
	if (ac > 1 && my_strcmp(argv[1], "-h") == 0)
		show_help();
	else
		check_if_map_exist(argv[1]);
	map_main = check_map(argv[1]);
	backup_map = check_map(argv[1]);
	while (reset) {
		reset = game_main(map_main, backup_map);
		map_main = check_map(argv[1]);
		backup_map = check_map(argv[1]);
	}
	return (0);
}