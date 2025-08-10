/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 17:17:45 by pbongiov          #+#    #+#             */
/*   Updated: 2025/08/10 20:43:37 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	game_start(t_game *game)
{
	game->sprite->player.look_left = 0;
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, game->map.width * 64,
			game->map.height * 64, "so_long");
	game->sprite->exit = mlx_xpm_file_to_image(game->mlx,
			"imgs/assets/exit.xpm", &game->sprite->w, &game->sprite->h);
	game->sprite->floor = mlx_xpm_file_to_image(game->mlx,
			"imgs/assets/grass.xpm", &game->sprite->w, &game->sprite->h);
	game->sprite->wall = mlx_xpm_file_to_image(game->mlx,
			"imgs/assets/wall.xpm", &game->sprite->w, &game->sprite->h);
	player_idle(game);
	player_walk(game);
	collect_imgs(game);
	game->player.x *= 64;
	game->player.y *= 64;
	mlx_hook(game->window, 17, 0, exit_game, game);
	mlx_hook(game->window, 2, (1L << 0), key_press, game);
	mlx_hook(game->window, 3, (1L << 1), key_realease, game);
	mlx_loop_hook(game->mlx, player_movement, game);
}
