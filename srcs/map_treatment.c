/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_treatment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:31:08 by pbongiov          #+#    #+#             */
/*   Updated: 2025/08/12 14:57:09 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map_initialize(t_game *game, char *filename)
{
	int	i;

	i = 0;
	row_and_col_len(game, filename);
	game->map.coordinate = malloc(sizeof(char *) * (game->map.height + 1));
	if (!game->map.coordinate)
		return ;
	while (i < game->map.height)
	{
		game->map.coordinate[i] = malloc(game->map.width + 1);
		if (!game->map.coordinate[i])
		{
			free_map(game);
			exit(0);
		}
		game->map.coordinate[i][game->map.width] = '\0';
		i++;
	}
	game->map.coordinate[game->map.height] = NULL;
}

void	map_input(t_game *game, char *filename)
{
	int		i;
	int		j;
	int		fd;
	char	*s;

	map_initialize(game, filename);
	i = 0;
	fd = open(filename, O_RDONLY);
	s = get_next_line(fd);
	if (!s)
		return ;
	while (i < game->map.height)
	{
		j = 0;
		is_rectangular(s, game);
		while (s[j] && j < game->map.width)
		{
			game->map.coordinate[i][j] = s[j];
			j++;
		}
		free(s);
		s = get_next_line(fd);
		i++;
	}
	close(fd);
}

void	locate_player(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map.coordinate[y])
	{
		x = 0;
		while (game->map.coordinate[y][x])
		{
			if (game->map.coordinate[y][x] == 'P')
			{
				game->player.x = x;
				game->player.y = y;
				break ;
			}
			x++;
		}
		y++;
	}
}

void	flood_fill(char **map, int x, int y)
{
	char	c;

	c = map[y][x];
	if (c == '1' || c == 'F' || c == 'B' || c == 'A' || c == 'X')
		return ;
	if (c == '0')
		map[y][x] = 'A';
	else if (c == 'C')
		map[y][x] = 'B';
	else if (c == 'E')
		map[y][x] = 'F';
	else
		map[y][x] = 'A';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

void	map_validation(t_game *game, char *filename)
{
	is_berfile(game, filename);
	map_input(game, filename);
	is_closed(game);
	char_check_before(game);
	locate_player(game);
	flood_fill(game->map.coordinate, game->player.x, game->player.y);
	char_check_after(game);
}
