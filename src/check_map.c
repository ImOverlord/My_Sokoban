/*
** EPITECH PROJECT, 2017
** check_map.c
** File description:
** checks if map is valid
*/

#include "../include/function_header.h"
#include "../include/my_sokoban.h"

void check_characters_value(int p_count, int box_count, int zone_count)
{
	if (p_count != 1) {
		my_printf("Error: Map is invalid.\n");
		exit(84);
	}
	if (box_count != zone_count) {
		my_printf("Error: Map is invalid.\n");
		exit(84);
	}
}

void check_characters(char *map)
{
	int p_count = 0;
	int box_count = 0;
	int zone_count = 0;

	for (int i = 0; map[i] != '\0'; i++) {
		if (map[i] == 'P')
			p_count++;
	}
	for (int i = 0; map[i] != '\0'; i++) {
		if (map[i] == 'X')
			box_count++;
	}
	for (int i = 0; map[i] != '\0'; i++) {
		if (map[i] == 'O')
			zone_count++;
	}
	check_characters_value(p_count, box_count, zone_count);
}

char *read_file(char *filename)
{
	int fd;
	char temp_buffer[2];
	char *buffer;
	int size = 0;

	fd = open(filename, O_RDONLY);
	while (read(fd, temp_buffer, 1)) {
		size++;
	}
	close(fd);
	buffer = malloc(sizeof(char) * size + 1);
	if (buffer == NULL)
		exit(84);
	fd = open(filename, O_RDONLY);
	read(fd, buffer, size);
	buffer[size] = '\0';
	close(fd);
	return (buffer);
}

char *check_map(char *filename)
{
	char *map;

	map = read_file(filename);
	check_characters(map);
	return (map);
}