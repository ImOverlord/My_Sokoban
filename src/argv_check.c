/*
** EPITECH PROJECT, 2017
** argv_check.c
** File description:
** function to check argv
*/

#include "../include/my_sokoban.h"
#include "./printf/printf_header.h"
#include "../include/function_header.h"

void show_help(void)
{
	my_printf("USAGE\n");
	my_printf("\t\t./my_sokoban map\n\n");
	my_printf("DESCRIPTION\n");
	my_printf("\tmap\tfile representing the warehouse map, containing");
	my_printf(" '#' for walls,\n\t\t'P' for the player, 'X', for");
	my_printf(" boxes and 'O' for storage locations.\n");
	exit(0);
}

void no_arguments(void)
{
	my_printf("Missing Arguments\n");
	exit(84);
}

void check_if_map_exist(char *filename)
{
	FILE * fp;

	fp = fopen (filename, "r");
	if (fp == 0) {
		my_printf("Error: map not found\n");
		exit(84);
	}
	fclose(fp);
}