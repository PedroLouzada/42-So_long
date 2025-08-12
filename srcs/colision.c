/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colision.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 19:30:04 by pedro             #+#    #+#             */
/*   Updated: 2025/08/12 18:11:30 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


static int	colision_top(t_game *game)
{
	int	px_left;
	int	px_right;
	int	px_limit;

	px_left = game->player.x / 64;
	px_right = (game->player.x + 63) / 64;
	px_limit = (game->player.y - 1) / 64;
	if (!colision_top_down(game, px_left, px_right, px_limit))
		return (0);
	return (1);
}

static int	colision_down(t_game *game)
{
	int	px_left;
	int	px_right;
	int	px_limit;

	px_left = game->player.x / 64;
	px_right = (game->player.x + 63) / 64;
	px_limit = (game->player.y + 64) / 64;
	if (!colision_top_down(game, px_left, px_right, px_limit))
		return (0);
	return (1);
}

static int	colision_left(t_game *game)
{
	int	px_top;
	int	px_down;
	int	px_limit;

	px_top = game->player.y / 64;
	px_down = (game->player.y + 63) / 64;
	px_limit = (game->player.x - 1) / 64;
	if (!colision_left_right(game, px_top, px_down, px_limit))
		return (0);
	return (1);
}

static int	colision_right(t_game *game)
{
	int	px_top;
	int	px_down;
	int	px_limit;

	px_top = game->player.y / 64;
	px_down = (game->player.y + 63) / 64;
	px_limit = (game->player.x + 64) / 64;
	if (!colision_left_right(game, px_top, px_down, px_limit))
		return (0);
	return (1);
}

int	colision(t_game *game, int i)
{
	if (i == 0 && !colision_top(game))
		return (0);
	if (i == 1 && !colision_down(game))
		return (0);
	if (i == 2 && !colision_left(game))
		return (0);
	if (i == 3 && !colision_right(game))
		return (0);
	return (1);
}
