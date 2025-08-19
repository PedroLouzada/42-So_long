/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_config.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 16:51:14 by pbongiov          #+#    #+#             */
/*   Updated: 2025/08/19 14:13:51 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	player_movement(t_game *game)
{
	if (game->keys[W] && colision(game, 0))
		game->player.y -= 1;
	if (game->keys[S] && colision(game, 1))
		game->player.y += 1;
	if (game->keys[A] && colision(game, 2))
	{
		game->player.look_left = 1;
		game->player.x -= 1;
	}
	if (game->keys[D] && colision(game, 3))
	{
		game->player.look_left = 0;
		game->player.x += 1;
	}
	create_map(game);
	print_player(game);
	step_count(game);
	return (0);
}

int	check_movment(t_game *game)
{
	if ((!game->keys[W] && !game->keys[S] && !game->keys[A] && !game->keys[D])
		|| ((game->keys[W] && game->keys[S]) || (game->keys[A]
				&& game->keys[D])))
		return (0);
	return (1);
}
