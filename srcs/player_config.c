/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_config.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 16:51:14 by pbongiov          #+#    #+#             */
/*   Updated: 2025/08/04 15:30:41 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int player_movement(t_game *game)
{
	static unsigned long last_time;
	unsigned long current_time;

	current_time = get_time();
	if (current_time - last_time < 7)
		return (0);
	last_time = current_time;
	if (game->keys[W])
		game->player.y -= 1;
	if (game->keys[A])
		game->player.x -= 1;
	if (game->keys[S])
		game->player.y  += 1;
	if (game->keys[D])
		game->player.x += 1;
	print_images(game);
	return (0);
}
