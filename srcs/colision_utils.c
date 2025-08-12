/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colision_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 18:03:03 by pbongiov          #+#    #+#             */
/*   Updated: 2025/08/12 18:12:28 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int colision_top_down(t_game *game, int px_left, int px_right, int px_limit)
{
	if (game->map.coordinate[px_limit][px_left] == '1'
		|| game->map.coordinate[px_limit][px_right] == '1')
		return (0);
	if (game->map.coordinate[px_limit][px_left] == 'X'
		|| game->map.coordinate[px_limit][px_right] == 'X')
		exit_game(game);
	else if (game->map.coordinate[px_limit][px_left] == 'B'
		|| game->map.coordinate[px_limit][px_right] == 'B')
	{
		if (game->map.coordinate[px_limit][px_left] == 'B')
			game->map.coordinate[px_limit][px_left] = 'A';
		if (game->map.coordinate[px_limit][px_right] == 'B')
			game->map.coordinate[px_limit][px_right] = 'A';
		game->player.collect++;
		game->player.collect++;
	}
	return (1);
}

int colision_left_right(t_game *game, int px_top, int px_down, int px_limit)
{
	if (game->map.coordinate[px_top][px_limit] == '1'
		|| game->map.coordinate[px_down][px_limit] == '1')
		return (0);
	else if (game->map.coordinate[px_top][px_limit] == 'X'
		|| game->map.coordinate[px_down][px_limit] == 'X')
		exit_game(game);
	else if (game->map.coordinate[px_top][px_limit] == 'B'
	|| game->map.coordinate[px_down][px_limit] == 'B')
	{
		if (game->map.coordinate[px_top][px_limit] == 'B')
			game->map.coordinate[px_top][px_limit] = 'A';
		if (game->map.coordinate[px_down][px_limit] == 'B')
			game->map.coordinate[px_down][px_limit] = 'A';
		game->player.collect++;
	}
	else if (game->map.coordinate[px_top][px_limit] == 'F'
		|| game->map.coordinate[px_down][px_limit] == 'F')
	{
		if (game->player.collect == game->map.c)
			exit_game(game);
	}
	return (1);
}
