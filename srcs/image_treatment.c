/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_treatment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 18:02:11 by pbongiov          #+#    #+#             */
/*   Updated: 2025/07/26 18:23:37 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void print_images(t_game *game)
{
	mlx_clear_window(game->mlx, game->window);
	mlx_put_image_to_window(game->mlx, game->window, game->sprite->floor, 0, 0);
	mlx_put_image_to_window(game->mlx, game->window, game->sprite->player, game->player.x, game->player.y);
}
