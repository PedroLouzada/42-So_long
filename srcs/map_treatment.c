/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_treatment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:31:08 by pbongiov          #+#    #+#             */
/*   Updated: 2025/08/04 20:34:20 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void map_initialize(t_game *game, char *filename)
{
	int i;

	i = 0;
	row_and_col_len(game, filename);
	game->map.coordinate = malloc(sizeof(char *) * (game->map.height + 1));
	if (!game->map.coordinate)
		return;
	while(i <= game->map.height)
	{
		game->map.coordinate[i] = malloc(game->map.width + 1);
		if (!game->map.coordinate[i])
			exit_game(game);
		game->map.coordinate[i][game->map.width] = '\0';
		i++;
	}
	game->map.coordinate[game->map.height] = NULL;
}

static void print_map(t_game *game)
{
	int i = 0;

	while (game->map.coordinate[i])
	{
		printf("%s", game->map.coordinate[i]);
		i++;
	}
}

void	map_input(t_game *game, char *filename)
{
	int i;
	int j;
	int fd;
	char *s;

	map_initialize(game, filename);
	i = 0;
	fd = open(filename, O_RDONLY);
	s = get_next_line(fd);
	if (!s)
		return;
	while (i < game->map.height)
	{
		j = 0;
		while(s[j])
		{
			game->map.coordinate[i][j] = s[j];
			j++;
		}
		free(s);
		s = get_next_line(fd);
		i++;
	}
	close(fd);
	print_map(game);
}
void map_validation(t_game *game, char *filename)
{
	map_input(game, filename);
	is_rectangular(game);
}