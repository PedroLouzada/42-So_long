/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movment_config.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 18:54:30 by pbongiov          #+#    #+#             */
/*   Updated: 2025/08/12 19:38:01 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void print_steps(t_game *game)
{
	mlx_string_put(game->mlx, game->window, 0, game->map.height * 64, 0, "STEPS: ");
}

int	key_press(int key, t_game *game)
{
	game->keys[key] = 1;
	if (key == ESC)
		exit_game(game);
	return (0);
}

int	key_realease(int key, t_game *game)
{
	game->keys[key] = 0;
	return (0);
}

unsigned long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
