/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_treatment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:31:08 by pbongiov          #+#    #+#             */
/*   Updated: 2025/08/06 21:23:29 by pbongiov         ###   ########.fr       */
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
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map.coordinate[i])
	{
		j = 0;
		while (game->map.coordinate[i][j])
		{
			if (game->map.coordinate[i][j] == 'P')
			{
				game->player.x = j;
				game->player.y = i;
			}
			j++;
		}
		i++;
	}
	printf("x: %i\ny: %i\n", game->player.x, game->player.y);
}

/*void game_state(t_game *game)
{
	printf("--------------- game state ---------------\n");
	printf("map:\n");
	printf("\theight: %i\n", game->map.height);
	printf("\twidth: %i\n", game->map.width);
	printf("player:\n");
	printf("\tplayer x: %i\n", game->player.x);
	printf("\tplayer y: %i\n", game->player.y);
	printf("--------------- game state ---------------\n");
}*/

	
void	flood_fill(t_game *game)
{
	int i;
	i = game->player.x;
	if (game->map.coordinate[game->player.y][game->player.x + 1] == '0')
	{
		game->player.x += 1;
		game->map.coordinate[game->player.y][game->player.x] = 'A';
		flood_fill(game);
	}
	game->player.x = i;
	if (game->player.x > 0 && game->map.coordinate[game->player.y][game->player.x - 1] == '0')
	{
		game->player.x -= 1;
		game->map.coordinate[game->player.y][game->player.x] = 'A';
		flood_fill(game);
	}
	i = game->player.y;
	if (game->map.coordinate[game->player.y + 1][game->player.x] == '0')
	{
		game->player.y += 1;
		game->map.coordinate[game->player.y][game->player.x] = 'A';
		flood_fill(game);
	}
	game->player.y = i;
	if (game->player.y > 0 && game->map.coordinate[game->player.y - 1][game->player.x] == '0')
	{
		game->player.y -= 1;
		game->map.coordinate[game->player.y][game->player.x] = 'A';
		flood_fill(game);
	}
}
static void print_map(char **arr)
{
    int i = 0;
	
    while (arr[i])
    {
        printf("%s\n", arr[i]);
        i++;
    }
}

void	map_validation(t_game *game, char *filename)
{
	map_input(game, filename);
	is_closed(game);
	char_check(game);
	locate_player(game);
	flood_fill(game);
	print_map(game->map.coordinate);
}
