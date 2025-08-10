/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 19:20:01 by pbongiov          #+#    #+#             */
/*   Updated: 2025/08/10 21:59:57 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	create_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.coordinate[i])
	{
		j = 0;
		while (game->map.coordinate[i][j])
		{
			if (game->map.coordinate[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->window,
					game->sprite->wall, j * 64, i * 64);
			else if (game->map.coordinate[i][j] == 'F')
				mlx_put_image_to_window(game->mlx, game->window,
					game->sprite->exit, j * 64, i * 64);
			else if (game->map.coordinate[i][j] == 'B')
				mlx_put_image_to_window(game->mlx, game->window,
					game->sprite->collectable[game->sprite->player.count_collect], j * 64, i * 64);
			else
				mlx_put_image_to_window(game->mlx, game->window,
					game->sprite->floor, j * 64, i * 64);
			j++;
		}
		i++;
	}
}
