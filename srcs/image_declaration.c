/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_declaration.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:18:36 by pbongiov          #+#    #+#             */
/*   Updated: 2025/08/13 22:41:15 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	player_walk(t_game *game)
{
	game->sprite->animation.player_walk[0] = mlx_xpm_file_to_image(game->mlx,
			"imgs/player/walk_01.xpm", &game->sprite->w, &game->sprite->h);
	game->sprite->animation.player_walk[1] = mlx_xpm_file_to_image(game->mlx,
			"imgs/player/walk_02.xpm", &game->sprite->w, &game->sprite->h);
	game->sprite->animation.player_walk[2] = mlx_xpm_file_to_image(game->mlx,
			"imgs/player/walk_03.xpm", &game->sprite->w, &game->sprite->h);
	game->sprite->animation.player_walk[3] = mlx_xpm_file_to_image(game->mlx,
			"imgs/player/walk_04.xpm", &game->sprite->w, &game->sprite->h);
	game->sprite->animation.player_walk[4] = mlx_xpm_file_to_image(game->mlx,
			"imgs/player/walk_05.xpm", &game->sprite->w, &game->sprite->h);
	game->sprite->animation.player_walk[5] = mlx_xpm_file_to_image(game->mlx,
			"imgs/player/walk_06.xpm", &game->sprite->w, &game->sprite->h);
	game->sprite->animation.player_walk_left[0] = mlx_xpm_file_to_image(game->mlx,
			"imgs/player/walk_left_01.xpm", &game->sprite->w, &game->sprite->h);
	game->sprite->animation.player_walk_left[1] = mlx_xpm_file_to_image(game->mlx,
			"imgs/player/walk_left_02.xpm", &game->sprite->w, &game->sprite->h);
	game->sprite->animation.player_walk_left[2] = mlx_xpm_file_to_image(game->mlx,
			"imgs/player/walk_left_03.xpm", &game->sprite->w, &game->sprite->h);
	game->sprite->animation.player_walk_left[3] = mlx_xpm_file_to_image(game->mlx,
			"imgs/player/walk_left_04.xpm", &game->sprite->w, &game->sprite->h);
	game->sprite->animation.player_walk_left[4] = mlx_xpm_file_to_image(game->mlx,
			"imgs/player/walk_left_05.xpm", &game->sprite->w, &game->sprite->h);
	game->sprite->animation.player_walk_left[5] = mlx_xpm_file_to_image(game->mlx,
			"imgs/player/walk_left_06.xpm", &game->sprite->w, &game->sprite->h);
}

static void	player_idle(t_game *game)
{
	game->sprite->animation.player_idle[0] = mlx_xpm_file_to_image(game->mlx,
			"imgs/player/default_00.xpm", &game->sprite->w, &game->sprite->h);
	game->sprite->animation.player_idle[1] = mlx_xpm_file_to_image(game->mlx,
			"imgs/player/default_01.xpm", &game->sprite->w, &game->sprite->h);
	game->sprite->animation.player_idle[2] = mlx_xpm_file_to_image(game->mlx,
			"imgs/player/default_02.xpm", &game->sprite->w, &game->sprite->h);
	game->sprite->animation.player_idle_left[0] = mlx_xpm_file_to_image(game->mlx,
			"imgs/player/default_left_00.xpm", &game->sprite->w,
			&game->sprite->h);
	game->sprite->animation.player_idle_left[1] = mlx_xpm_file_to_image(game->mlx,
			"imgs/player/default_left_01.xpm", &game->sprite->w,
			&game->sprite->h);
	game->sprite->animation.player_idle_left[2] = mlx_xpm_file_to_image(game->mlx,
			"imgs/player/default_left_02.xpm", &game->sprite->w,
			&game->sprite->h);
}

static void	collect_imgs(t_game *game)
{
	game->sprite->collectable[0] = mlx_xpm_file_to_image(game->mlx,
			"imgs/assets/collectable/chicken_00.xpm", &game->sprite->w,
			&game->sprite->h);
	game->sprite->collectable[1] = mlx_xpm_file_to_image(game->mlx,
			"imgs/assets/collectable/chicken_01.xpm", &game->sprite->w,
			&game->sprite->h);
	game->sprite->collectable[2] = mlx_xpm_file_to_image(game->mlx,
			"imgs/assets/collectable/chicken_02.xpm", &game->sprite->w,
			&game->sprite->h);
	game->sprite->collectable[3] = mlx_xpm_file_to_image(game->mlx,
			"imgs/assets/collectable/chicken_03.xpm", &game->sprite->w,
			&game->sprite->h);
}

static void	enemy_imgs(t_game *game)
{
	game->sprite->animation.enemy[0] = mlx_xpm_file_to_image(game->mlx,
			"imgs/enemy/Mushroom_idle_00.xpm", &game->sprite->w,
			&game->sprite->h);
	game->sprite->animation.enemy[1] = mlx_xpm_file_to_image(game->mlx,
			"imgs/enemy/Mushroom_idle_01.xpm", &game->sprite->w,
			&game->sprite->h);
	game->sprite->animation.enemy[2] = mlx_xpm_file_to_image(game->mlx,
			"imgs/enemy/Mushroom_idle_02.xpm", &game->sprite->w,
			&game->sprite->h);
	game->sprite->animation.enemy[3] = mlx_xpm_file_to_image(game->mlx,
			"imgs/enemy/Mushroom_idle_03.xpm", &game->sprite->w,
			&game->sprite->h);
	game->sprite->animation.enemy[4] = mlx_xpm_file_to_image(game->mlx,
			"imgs/enemy/Mushroom_idle_03.xpm", &game->sprite->w,
			&game->sprite->h);
}

void	general_declaration(t_game *game)
{
	game->sprite->exit = mlx_xpm_file_to_image(game->mlx,
			"imgs/assets/exit.xpm", &game->sprite->w, &game->sprite->h);
	game->sprite->floor = mlx_xpm_file_to_image(game->mlx,
			"imgs/assets/grass.xpm", &game->sprite->w, &game->sprite->h);
	game->sprite->wall = mlx_xpm_file_to_image(game->mlx,
			"imgs/assets/wall.xpm", &game->sprite->w, &game->sprite->h);
	player_idle(game);
	player_walk(game);
	collect_imgs(game);
	enemy_imgs(game);
	numbers_img_declaration(game);
	check_img(game);
}
