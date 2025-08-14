/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leak_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 18:56:31 by pbongiov          #+#    #+#             */
/*   Updated: 2025/08/14 18:20:28 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	if (game->map.arr)
	{
		while (game->map.arr[i])
		{
			free(game->map.arr[i]);
			i++;
		}
		free(game->map.arr);
	}
	if (game->sprite)
		free(game->sprite);
}

static void	free_imgs_3(t_game *game)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (game->sprite->p_walk_l[i])
			mlx_destroy_image(game->mlx, game->sprite->p_walk_l[i]);
		if (game->sprite->p_walk[i])
			mlx_destroy_image(game->mlx, game->sprite->p_walk[i]);
		i++;
	}
	i = 0;
	while (i < 10)
	{
		if (game->sprite->numbers[i])
			mlx_destroy_image(game->mlx, game->sprite->numbers[i]);
		i++;
	}
}

static void	free_imgs_2(t_game *game)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (game->sprite->enemy[i])
			mlx_destroy_image(game->mlx, game->sprite->enemy[i]);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (game->sprite->collectable[i])
			mlx_destroy_image(game->mlx, game->sprite->collectable[i]);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (game->sprite->steps[i])
			mlx_destroy_image(game->mlx, game->sprite->steps[i]);
		i++;
	}
}

void	free_imgs(t_game *game)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (game->sprite->p_idle_l[i])
			mlx_destroy_image(game->mlx, game->sprite->p_idle_l[i]);
		if (game->sprite->p_idle[i])
			mlx_destroy_image(game->mlx, game->sprite->p_idle[i]);
		i++;
	}
	free_imgs_2(game);
	free_imgs_3(game);
	if (game->sprite->floor)
		mlx_destroy_image(game->mlx, game->sprite->floor);
	if (game->sprite->exit)
		mlx_destroy_image(game->mlx, game->sprite->exit);
	if (game->sprite->wall)
		mlx_destroy_image(game->mlx, game->sprite->wall);
	if (game->sprite->canva)
		mlx_destroy_image(game->mlx, game->sprite->canva);
}

int	exit_game(t_game *game)
{
	int	i;

	i = 0;
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	while (game->sprite->buffer[i])
		free(game->sprite->buffer[i++]);
	free(game->sprite->buffer);
	free_imgs(game);
	free_map(game);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
}
