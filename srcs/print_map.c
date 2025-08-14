/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 19:20:01 by pbongiov          #+#    #+#             */
/*   Updated: 2025/08/14 18:30:09 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	get_pixel(void *img, int x, int y)
{
	char	*data_addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		offset;

	data_addr = mlx_get_data_addr(img, &bits_per_pixel, &size_line, &endian);
	offset = (y * size_line) + (x * (bits_per_pixel) / 8);
	return (*(unsigned int *)(data_addr + offset));
}

void	copy_buffer(t_game *game, int _pixel, int x, int y)
{
	char	*data_addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	char	*pixel;

	data_addr = mlx_get_data_addr(game->sprite->canva, &bits_per_pixel,
			&size_line, &endian);
	pixel = data_addr + (y * size_line + x * (bits_per_pixel / 8));
	*(int *)pixel = _pixel;
}

void	put_img(t_game *game, void *img, int sx, int sy)
{
	int	pixel;
	int	x;
	int	y;

	y = 0;
	while (y < 64)
	{
		x = 0;
		while (x < 64)
		{
			pixel = get_pixel(img, x, y);
			if (pixel != 16711935)
				copy_buffer(game, pixel, sx + x, sy + y);
			x++;
		}
		y++;
	}
}

void	create_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map.arr[y])
	{
		x = 0;
		while (game->map.arr[y][x])
		{
			if (game->map.arr[y][x] == '1')
				put_img(game, game->sprite->wall, x * 64, y * 64);
			else if (game->map.arr[y][x] == 'F')
				put_img(game, game->sprite->exit, x * 64, y * 64);
			else
				put_img(game, game->sprite->floor, x * 64, y * 64);
			if (game->map.arr[y][x] == 'B')
				put_img(game, game->sprite->collectable[game->sprite->count_c],
					x * 64, y * 64);
			else if (game->map.arr[y][x] == 'X')
				put_img(game, game->sprite->enemy[game->sprite->count_e], x
					* 64, y * 64);
			x++;
		}
		y++;
	}
}

void	print_player(t_game *game)
{
	mlx_clear_window(game->mlx, game->window);
	create_map(game);
	if (!game->player.look_left)
	{
		if (check_movment(game))
			put_img(game, game->sprite->p_idle[game->sprite->count_p],
				game->player.x, game->player.y);
		else
			put_img(game, game->sprite->p_walk[game->sprite->count_w],
				game->player.x, game->player.y);
	}
	else
	{
		if (!check_movment(game))
			put_img(game, game->sprite->p_idle_l[game->sprite->count_p],
				game->player.x, game->player.y);
		else
			put_img(game, game->sprite->p_walk_l[game->sprite->count_w],
				game->player.x, game->player.y);
	}
	mlx_put_image_to_window(game->mlx, game->window, game->sprite->canva, 0, 0);
	print_steps(game);
	animation_time(game);
}
