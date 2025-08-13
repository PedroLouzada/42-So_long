/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_verification.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 20:42:14 by pbongiov          #+#    #+#             */
/*   Updated: 2025/08/13 21:10:42 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void check_img(game)
{
	int i;

	i = 0;
	while (i < 5)
	{
		if (!game->sprite->animation->player_walk[i] || game->sprite->animation->player_walk_left[i])
			exit_img_msg(game);
		i++;
	}
	i = 0;
	while (i < 3)
	{
		if (!game->sprite->animation.player_idle[i] || game->sprite->animation.player_idle_left[i])
			exit_img_msg(game);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (!game->sprite->collectable[i])
			exit_img_msg(game);
		i++
	}
}

stativ void
