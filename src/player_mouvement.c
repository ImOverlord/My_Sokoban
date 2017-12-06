/*
** EPITECH PROJECT, 2017
** player_mouvements.c
** File description:
** functions to control player mouvement
*/

#include "../include/function_header.h"
#include "../include/my_sokoban.h"

void move_box(char *map, int player, int box_position, int offset)
{
	map[box_position] = ' ';
	map[box_position + offset] = 'X';
	map[player] = ' ';
	map[player + offset] = 'P';
}

int player_move_it(int *player_pos, char *map, int mouvement, char *backup_map)
{
	int player = *player_pos;
	int *map_size = get_map_size(map);
	int offset[4] = {map_size[0] + 1, -(map_size[0] + 1), 1, -1};
	int box_position = player + offset[mouvement];
	int score = 0;

	if (map[box_position + offset[mouvement]] == ' ') {
		move_box(map, player, box_position, offset[mouvement]);
		player = get_player_pos(map);
		*player_pos = player;
	}
	if (map[box_position + offset[mouvement]] == 'O') {
		move_box(map, player, box_position, offset[mouvement]);
		player = get_player_pos(map);
		*player_pos = player;
		score = 1;
	}
	score = check_score(map, backup_map);
	return (score);
}

int valid_move(int *player_pos, char *map, int mouvement, char *backup_map)
{
	int player = *player_pos;
	int *map_size = get_map_size(map);
	int offset[4] = {map_size[0] + 1, -(map_size[0] + 1), 1, -1};
	int score = 0;

	if (map[player + offset[mouvement]] == ' ') {
		map[player] = ' ';
		map[player + offset[mouvement]] = 'P';
		player = get_player_pos(map);
		*player_pos = player;
	} else if (map[player + offset[mouvement]] == 'X') {
		score = player_move_it(&player, map, mouvement, backup_map);
		*player_pos = player;
	}
	score = check_score(map, backup_map);
	return (score);
}