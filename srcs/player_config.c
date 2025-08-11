/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_config.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 16:51:14 by pbongiov          #+#    #+#             */
/*   Updated: 2025/08/11 21:49:33 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	player_movement(t_game *game)
{
	static unsigned long	last_time;
	unsigned long			current_time;

	current_time = get_time();
	if (current_time - last_time < 7)
		return (0);
	last_time = current_time;
	if (game->keys[W] && colision_check(game, 0))
		game->player.y -= 1;
	if (game->keys[S] && colision_check(game, 1))
		game->player.y += 1;
	if (game->keys[A] && colision_check(game, 2))
	{
		game->sprite->player.look_left = 1;
		game->player.x -= 1;
	}
	if (game->keys[D] && colision_check(game, 3))
	{
		game->sprite->player.look_left = 0;
		game->player.x += 1;
	}
	create_map(game);
	print_player(game);
	return (0);
}
