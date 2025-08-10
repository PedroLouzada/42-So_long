/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_treatment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 18:02:11 by pbongiov          #+#    #+#             */
/*   Updated: 2025/08/10 22:06:03 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	player_walk(t_game *game)
{
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
	game->sprite->player.player_walk_left[0] = mlx_xpm_file_to_image(game->mlx,
			"imgs/player/walk_left_01.xpm", &game->sprite->w, &game->sprite->h);
	game->sprite->player.player_walk_left[1] = mlx_xpm_file_to_image(game->mlx,
			"imgs/player/walk_left_02.xpm", &game->sprite->w, &game->sprite->h);
	game->sprite->player.player_walk_left[2] = mlx_xpm_file_to_image(game->mlx,
			"imgs/player/walk_left_03.xpm", &game->sprite->w, &game->sprite->h);
	game->sprite->player.player_walk_left[3] = mlx_xpm_file_to_image(game->mlx,
			"imgs/player/walk_left_04.xpm", &game->sprite->w, &game->sprite->h);
	game->sprite->player.player_walk_left[4] = mlx_xpm_file_to_image(game->mlx,
			"imgs/player/walk_left_05.xpm", &game->sprite->w, &game->sprite->h);
	game->sprite->player.player_walk_left[5] = mlx_xpm_file_to_image(game->mlx,
			"imgs/player/walk_left_06.xpm", &game->sprite->w, &game->sprite->h);
}

void	player_idle(t_game *game)
{
	game->sprite->player.player_idle[0] = mlx_xpm_file_to_image(game->mlx,
			"imgs/player/default_00.xpm", &game->sprite->w, &game->sprite->h);
	game->sprite->player.player_idle[1] = mlx_xpm_file_to_image(game->mlx,
			"imgs/player/default_01.xpm", &game->sprite->w, &game->sprite->h);
	game->sprite->player.player_idle[2] = mlx_xpm_file_to_image(game->mlx,
			"imgs/player/default_02.xpm", &game->sprite->w, &game->sprite->h);
	game->sprite->player.player_idle_left[0] = mlx_xpm_file_to_image(game->mlx,
			"imgs/player/default_left_00.xpm", &game->sprite->w,
			&game->sprite->h);
	game->sprite->player.player_idle_left[1] = mlx_xpm_file_to_image(game->mlx,
			"imgs/player/default_left_01.xpm", &game->sprite->w,
			&game->sprite->h);
	game->sprite->player.player_idle_left[2] = mlx_xpm_file_to_image(game->mlx,
			"imgs/player/default_left_02.xpm", &game->sprite->w,
			&game->sprite->h);
}

void	collect_imgs(t_game *game)
{
	game->sprite->collectable[0] = mlx_xpm_file_to_image(game->mlx,
			"imgs/assets/chicken_00.xpm", &game->sprite->w,
			&game->sprite->h);
	game->sprite->collectable[1] = mlx_xpm_file_to_image(game->mlx,
			"imgs/assets/chicken_01.xpm", &game->sprite->w,
			&game->sprite->h);
	game->sprite->collectable[2] = mlx_xpm_file_to_image(game->mlx,
			"imgs/assets/chicken_02.xpm", &game->sprite->w,
			&game->sprite->h);
	game->sprite->collectable[3] = mlx_xpm_file_to_image(game->mlx,
			"imgs/assets/chicken_03.xpm", &game->sprite->w,
			&game->sprite->h);
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
	if (game->sprite->player.count_idle >= 3)
		game->sprite->player.count_idle = 0;
	game->sprite->player.count_walk++;
	if (game->sprite->player.count_walk >= 6)
		game->sprite->player.count_walk = 0;
	game->sprite->player.count_collect++;
	if (game->sprite->player.count_collect >= 4)
		game->sprite->player.count_collect = 0;
}

void	print_player(t_game *game)
{
	void	*img;

	mlx_clear_window(game->mlx, game->window);
	create_map(game);
	if (!game->sprite->player.look_left)
	{
		if ((!game->keys[W] && !game->keys[S] && !game->keys[A]
				&& !game->keys[D]) || ((game->keys[W] && game->keys[S])
				|| (game->keys[A] && game->keys[D])))
			img = game->sprite->player.player_idle[game->sprite->player.count_idle];
		else
			img = game->sprite->player.player_walk[game->sprite->player.count_walk];
	}
	else
	{
		if ((!game->keys[W] && !game->keys[S] && !game->keys[A]
				&& !game->keys[D]) || ((game->keys[W] && game->keys[S])
				|| (game->keys[A] && game->keys[D])))
			img = game->sprite->player.player_idle_left[game->sprite->player.count_idle];
		else
			img = game->sprite->player.player_walk_left[game->sprite->player.count_walk];
	}
	if (img)
		mlx_put_image_to_window(game->mlx, game->window, img, game->player.x,
			game->player.y);
	animation_time(game);
}
