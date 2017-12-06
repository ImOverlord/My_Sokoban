/*
** EPITECH PROJECT, 2017
** file_name.c
** File description:
** desc
*/

#ifndef MY_SOKOBAN_FUNCTION_H_
#define MY_SOKOBAN_FUNCTION_H_

#include "../src/printf/printf_header.h"

void show_help(void);
void no_arguments(void);
void check_if_map_exist(char *filename);
void check_characters_value(int p_count, int box_count, int zone_count);
void check_characters(char *map);
char *read_file(char *filename);
char *check_map(char *filename);
int get_player_pos(char *map);
int player_move(int move, int score, char *map, char *backup_map);
int game_logic(char *map, char *backup_map, int score, int play);
int game_main(char *map, char *backup_map);
int *get_map_size(char *map);
int score_win(char *map);
void move_box(char *map, int player, int box_position, int offset);
int player_move_it(int *player_pos, char *map, int mouvement, char *backup_map);
int valid_move(int *player_pos, char *map, int mouvement, char *backup_map);
int check_size(int lines, int cols, char *map);
int check_score(char *map, char *backup_map);

#endif