/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_verification.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 20:42:14 by pbongiov          #+#    #+#             */
/*   Updated: 2025/08/13 22:49:13 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void exit_img_msg(t_game *game)
{
	write(2, "Envie um sprite valido!\n", 22);
	exit_game(game);
}

static void check_img_2(t_game *game)
{
	int i;

	i = 0;
	while (i < 5)
	{
		if (!game->sprite->animation.enemy[i])
			exit_img_msg(game);
		i++;
	}
	i = 0;
	while (i < 10)
	{
		if (!game->sprite->numbers[i])
			exit_img_msg(game);
		i++;
	}
}

void check_img(t_game *game)
{
	int i;

	i = 0;
	while (i < 6)
	{
		if (!game->sprite->animation.player_walk[i] || !game->sprite->animation.player_walk_left[i])
			exit_img_msg(game);
		i++;
	}
	i = 0;
	while (i < 3)
	{
		if (!game->sprite->animation.player_idle[i] || !game->sprite->animation.player_idle_left[i])
			exit_img_msg(game);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (!game->sprite->collectable[i] || !game->sprite->steps[i])
			exit_img_msg(game);
		i++;
	}
	check_img_2(game);
}