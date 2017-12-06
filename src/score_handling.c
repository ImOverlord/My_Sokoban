/*
** EPITECH PROJECT, 2017
** score_handling.c
** File description:
** function to retrieve player score
*/

#include "../include/function_header.h"
#include "../include/my_sokoban.h"

int check_score(char *map, char *backup_map)
{
	int score = 0;

	for (int i = 0; i < my_strlen(backup_map); i++) {
		if (backup_map[i] == 'O' && map[i] == 'X') {
			score++;
		}
		if (backup_map[i] == 'O' && map[i] == ' ') {
			map[i] = 'O';
		}
	}
	return (score);
}