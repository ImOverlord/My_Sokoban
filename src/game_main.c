/*
** EPITECH PROJECT, 2017
** game_main.c
** File description:
** basic game mecanics
*/

#include "../include/function_header.h"
#include "../include/my_sokoban.h"

int get_player_pos(char *map)
{
	for (int i = 0; i < my_strlen(map); i++) {
		if (map[i] == 'P') {
			return (i);
		}
	}
	return (-1);
}

int player_move(int move, int score, char *map, char *backup_map)
{
	int player_pos = get_player_pos(map);

	if (move == 'A')
		score = valid_move(&player_pos, map, 1, backup_map);
	if (move == 'B')
		score = valid_move(&player_pos, map, 0, backup_map);
	if (move == 'C')
		score = valid_move(&player_pos, map, 2, backup_map);
	if (move == 'D')
		score = valid_move(&player_pos, map, 3, backup_map);
	return (score);
}

int game_logic(char *map, char *backup_map, int score, int play)
{
	int input;

	if (!play) {
		refresh();
		return (score);
	}
	mvprintw(0, 0, map);
	timeout(3000);
	input = getch();
	if (input == -1)
		return (-2);
	score = player_move(input, score, map, backup_map);
	if (input == 32)
		return (-1);
	refresh();
	return (score);
}

int check_size(int lines, int cols, char *map)
{
	clear();
	int *map_size = get_map_size(map);
	char *invalid_size = "Please Resize Window.";
	int size = (my_strlen(invalid_size)/2);

	if (map_size[0] >= cols || map_size[1] >= lines) {
		mvprintw(lines/2, cols/2 - size, invalid_size);
		return (0);
	}
	return (1);
}

int game_main(char *map, char *backup_map)
{
	int score_to_win = score_win(map);
	int score = 0;
	int play = 1;

	initscr();
	while (1) {
		play = check_size(LINES, COLS, map);
		score = game_logic(map, backup_map, score, play);
		if (score == -1 || score == -2)
			break;
		if (score == score_to_win)
			break;
		refresh();
	}
	endwin();
	if (score == -2)
		exit(1);
	if (score == score_to_win)
		exit(0);
	return (1);
}