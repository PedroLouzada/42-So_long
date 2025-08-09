/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leak_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 18:56:31 by pbongiov          #+#    #+#             */
/*   Updated: 2025/08/09 15:59:11 by pbongiov         ###   ########.fr       */
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
	mlx_destroy_image(game->mlx, game->sprite->player);
	mlx_destroy_image(game->mlx, game->sprite->floor);
	mlx_destroy_image(game->mlx, game->sprite->exit);
	mlx_destroy_image(game->mlx, game->sprite->wall);
	mlx_destroy_image(game->mlx, game->sprite->collectable);
}

int	exit_game(t_game *game)
{
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	free_imgs(game);
	free_map(game);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
}
