/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 19:20:01 by pbongiov          #+#    #+#             */
/*   Updated: 2025/08/07 20:53:26 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	create_map(t_game *game)
{
	int i;
	int j;
	
	i = 0;
	while(game->map.coordinate[i])
	{
		j = 0;
		while (game->map.coordinate[i][j])
		{
			if (game->map.coordinate[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->window, game->sprite->floor, j * 64, i * 64);
			else if (game->map.coordinate[i][j] == 'F')
				mlx_put_image_to_window(game->mlx, game->window, game->sprite->floor, j * 64, i * 64);
			else if (game->map.coordinate[i][j] == 'B')
				mlx_put_image_to_window(game->mlx, game->window, game->sprite->floor, j * 64, i * 64);
			else
				mlx_put_image_to_window(game->mlx, game->window, game->sprite->floor, j * 64, i * 64);
			j++;
		}
		i++;
	}
}
