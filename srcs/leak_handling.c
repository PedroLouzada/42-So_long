/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leak_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 18:56:31 by pbongiov          #+#    #+#             */
/*   Updated: 2025/08/12 18:39:06 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	if (game->map.coordinate)
	{
		while (game->map.coordinate[i])
		{
			free(game->map.coordinate[i]);
			i++;
		}
		free(game->map.coordinate);
	}
	if (game->sprite)
		free(game->sprite);
}

void	error_msg(t_game *game)
{
	free_map(game);
	write(2, "Envie um mapa valido!\n", 22);
	exit(0);
}

void	free_imgs(t_game *game)
{
	int i;

	i = 0;
	while (i < 3)
	{
		if (game->sprite->animation.player_idle_left[i])
			mlx_destroy_image(game->mlx, game->sprite->animation.player_idle_left[i]);
		if (game->sprite->animation.player_idle[i])
			mlx_destroy_image(game->mlx, game->sprite->animation.player_idle[i]);
		i++;
	}
	i = 0;
	while (i < 6)
	{
		if (game->sprite->animation.player_walk_left[i])
			mlx_destroy_image(game->mlx, game->sprite->animation.player_walk_left[i]);
		if (game->sprite->animation.player_walk[i])
			mlx_destroy_image(game->mlx, game->sprite->animation.player_walk[i]);
		i++;
	}
	i = 0;
	while (i < 5)
	{
		if (game->sprite->animation.enemy[i])
			mlx_destroy_image(game->mlx, game->sprite->animation.enemy[i]);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (game->sprite->collectable[i])
			mlx_destroy_image(game->mlx, game->sprite->collectable[i]);
		i++;
	}
	if (game->sprite->floor)
		mlx_destroy_image(game->mlx, game->sprite->floor);
	if (game->sprite->exit)
		mlx_destroy_image(game->mlx, game->sprite->exit);
	if (game->sprite->wall)
		mlx_destroy_image(game->mlx, game->sprite->wall);
	if (game->sprite->animation.canva)
		mlx_destroy_image(game->mlx, game->sprite->animation.canva);
}

int	exit_game(t_game *game)
{
	int i;

	i = 0;
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	free_imgs(game);
	free_map(game);
	while (game->sprite->animation.buffer[i])
		free(game->sprite->animation.buffer[i++]);
	free(game->sprite->animation.buffer);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
}
