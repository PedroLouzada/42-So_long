/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colision_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 18:03:03 by pbongiov          #+#    #+#             */
/*   Updated: 2025/08/14 18:04:39 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	colision_top_down(t_game *game, int px_l, int px_r, int limit)
{
	if (game->map.arr[limit][px_l] == '1' || game->map.arr[limit][px_r] == '1')
		return (0);
	if (game->map.arr[limit][px_l] == 'X' || game->map.arr[limit][px_r] == 'X')
	{
		lose_msg();
		exit_game(game);
	}
	if (game->map.arr[limit][px_l] == 'B' || game->map.arr[limit][px_r] == 'B')
	{
		if (game->map.arr[limit][px_l] == 'B')
			game->map.arr[limit][px_l] = 'A';
		if (game->map.arr[limit][px_r] == 'B')
			game->map.arr[limit][px_r] = 'A';
		game->player.collect++;
	}
	if (game->map.arr[limit][px_l] == 'F' || game->map.arr[limit][px_r] == 'F')
	{
		if (game->player.collect == game->map.c)
		{
			win_msg();
			exit_game(game);
		}
	}
	return (1);
}

int	colision_left_right(t_game *game, int px_t, int px_d, int limit)
{
	if (game->map.arr[px_t][limit] == '1' || game->map.arr[px_d][limit] == '1')
		return (0);
	if (game->map.arr[px_t][limit] == 'X' || game->map.arr[px_d][limit] == 'X')
	{
		lose_msg();
		exit_game(game);
	}
	if (game->map.arr[px_t][limit] == 'B' || game->map.arr[px_d][limit] == 'B')
	{
		if (game->map.arr[px_t][limit] == 'B')
			game->map.arr[px_t][limit] = 'A';
		if (game->map.arr[px_d][limit] == 'B')
			game->map.arr[px_d][limit] = 'A';
		game->player.collect++;
	}
	if (game->map.arr[px_t][limit] == 'F' || game->map.arr[px_d][limit] == 'F')
	{
		if (game->player.collect == game->map.c)
		{
			win_msg();
			exit_game(game);
		}
	}
	return (1);
}
