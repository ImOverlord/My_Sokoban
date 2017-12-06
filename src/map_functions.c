/*
** EPITECH PROJECT, 2017
** map_functions.c
** File description:
** function to get information about map
*/

#include "../include/function_header.h"
#include "../include/my_sokoban.h"

int *get_map_size(char *map)
{
	int *map_size = malloc (sizeof(int) * 2);
	int width = 0;
	int height = 0;

	while (map[width] != '\n') {
		width++;
	}
	height = my_strlen(map) / (width + 1);
	map_size[0] = width;
	map_size[1] = height;
	return (map_size);
}

int score_win(char *map)
{
	int score = 0;

	for (int i = 0; i < my_strlen(map); i++) {
		if (map[i] == 'O') {
			score++;
		}
	}
	return (score);
}