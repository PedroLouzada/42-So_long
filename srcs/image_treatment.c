/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_treatment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 18:02:11 by pbongiov          #+#    #+#             */
/*   Updated: 2025/08/09 20:03:07 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	player_idle(t_game *game)
{
	game->sprite->player.player_idle[0] = mlx_xpm_file_to_image(game->mlx,
			"imgs/player/default_00.xpm", &game->sprite->w, &game->sprite->h);
	game->sprite->player.player_idle[1] = mlx_xpm_file_to_image(game->mlx,
			"imgs/player/default_01.xpm", &game->sprite->w, &game->sprite->h);
	game->sprite->player.player_idle[2] = mlx_xpm_file_to_image(game->mlx,
			"imgs/player/default_02.xpm", &game->sprite->w, &game->sprite->h);
	game->sprite->player.player_walk[0] = mlx_xpm_file_to_image(game->mlx,
			"imgs/player/walk_01.xpm", &game->sprite->w, &game->sprite->h);
	game->sprite->player.player_walk[1] = mlx_xpm_file_to_image(game->mlx,
			"imgs/player/walk_02.xpm", &game->sprite->w, &game->sprite->h);
	game->sprite->player.player_walk[2] = mlx_xpm_file_to_image(game->mlx,
			"imgs/player/walk_03.xpm", &game->sprite->w, &game->sprite->h);
	game->sprite->player.player_walk[3] = mlx_xpm_file_to_image(game->mlx,
			"imgs/player/walk_04.xpm", &game->sprite->w, &game->sprite->h);
	game->sprite->player.player_walk[4] = mlx_xpm_file_to_image(game->mlx,
			"imgs/player/walk_05.xpm", &game->sprite->w, &game->sprite->h);
	game->sprite->player.player_walk[5] = mlx_xpm_file_to_image(game->mlx,
			"imgs/player/walk_06.xpm", &game->sprite->w, &game->sprite->h);
}

static void	animation_time(t_game *game)
{
	static unsigned long	last_time;
	unsigned long			current_time;

	current_time = get_time();
	if (current_time - last_time < 160)
		return ;
	last_time = current_time;
	game->sprite->player.count_idle++;
	if (game->sprite->player.count_idle == 3)
		game->sprite->player.count_idle = 0;
	game->sprite->player.count_walk++;
	if (game->sprite->player.count_walk == 5)
		game->sprite->player.count_walk = 0;
}

void	print_player(t_game *game)
{
	mlx_clear_window(game->mlx, game->window);
	create_map(game);
	if ((!game->keys[W] && !game->keys[S] && !game->keys[A] && !game->keys[D]) || ((game->keys[W] && game->keys[S]) || (game->keys[A] && game->keys[D])))
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprite->player.player_idle[game->sprite->player.count_idle], game->player.x, game->player.y);
	else
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprite->player.player_walk[game->sprite->player.count_walk], game->player.x, game->player.y);	
	animation_time(game);
}
