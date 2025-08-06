/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 17:17:45 by pbongiov          #+#    #+#             */
/*   Updated: 2025/08/06 15:59:56 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	exit_game(t_game *game)
{
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	free_imgs(game);
	free_map(game);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit (0);
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

void	game_start(t_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, 640, 480, "so_long");
	game->sprite->floor = mlx_xpm_file_to_image(game->mlx,
			"srcs/imgs/assets/grass.xpm", &game->sprite->w, &game->sprite->h);
	game->sprite->player = mlx_xpm_file_to_image(game->mlx,
			"srcs/default_00.xpm", &game->sprite->w, &game->sprite->h);
	mlx_hook(game->window, 17, 0, exit_game, game);
	mlx_hook(game->window, 2, (1L << 0), key_press, game);
	mlx_hook(game->window, 3, (1L << 1), key_realease, game);
	mlx_loop_hook(game->mlx, player_movement, game);
}

void	free_map(t_game * game)
{
	int	i;

	i = 0;
	while (game->map.coordinate[i])
	{
		free(game->map.coordinate[i]);
		i++;
	}
		free(game->map.coordinate);
		free(game->sprite);
}
void	error_msg(t_game *game)
{
	free_map(game);
	write(2, "Envie um mapa valido!\n", 22);
	exit(0);
}

void free_imgs(t_game *game)
{
	mlx_destroy_image(game->mlx, game->sprite->player);
	mlx_destroy_image(game->mlx, game->sprite->floor);
}