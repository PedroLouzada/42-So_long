/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 16:10:50 by pbongiov          #+#    #+#             */
/*   Updated: 2025/08/07 18:02:50 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void flood_collect_x(t_game *game)
{
 	int i;
	
	i = game->player.x;
	if (game->map.coordinate[game->player.y][game->player.x + 1] == 'C' || game->map.coordinate[game->player.y][game->player.x + 1] == 'E')
	{
		game->player.x += 1;
		if (game->map.coordinate[game->player.y][game->player.x] == 'E')
			game->map.coordinate[game->player.y][game->player.x] = 'F';
		else
			game->map.coordinate[game->player.y][game->player.x] = 'B';
		flood_fill(game);
	}
	game->player.x = i;
	if (game->player.x > 0 && (game->map.coordinate[game->player.y][game->player.x - 1] == 'C' || game->map.coordinate[game->player.y][game->player.x - 1] == 'E'))
	{
		game->player.x -= 1;
		if (game->map.coordinate[game->player.y][game->player.x] == 'E')
			game->map.coordinate[game->player.y][game->player.x] = 'F';
		else
			game->map.coordinate[game->player.y][game->player.x] = 'B';
		flood_fill(game);
	}
}

static void flood_collect_y(t_game *game)
{
	int i;
	
	i = game->player.y;
	if (game->map.coordinate[game->player.y + 1][game->player.x] == 'C' || game->map.coordinate[game->player.y + 1][game->player.x] == 'E')
	{
		game->player.y += 1;
		if (game->map.coordinate[game->player.y][game->player.x] == 'E')
			game->map.coordinate[game->player.y][game->player.x] = 'F';
		else
			game->map.coordinate[game->player.y][game->player.x] = 'B';
		flood_fill(game);
	}
	game->player.y = i;
	if (game->player.y > 0 && (game->map.coordinate[game->player.y - 1][game->player.x] == 'C' || game->map.coordinate[game->player.y - 1][game->player.x] == 'E'))
	{
		game->player.y -= 1;
		if (game->map.coordinate[game->player.y][game->player.x] == 'E')
			game->map.coordinate[game->player.y][game->player.x] = 'F';
		else
			game->map.coordinate[game->player.y][game->player.x] = 'B';
		flood_fill(game);
	}
}
static void flood_x(t_game *game)
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
}
static void flood_y(t_game *game)
{
	int i;
	
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

void	flood_fill(t_game *game)
{
	flood_x(game);
	flood_y(game);
	flood_collect_x(game);
	flood_collect_y(game);
}

