/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movment_config.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 18:54:30 by pbongiov          #+#    #+#             */
/*   Updated: 2025/08/14 18:46:49 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
