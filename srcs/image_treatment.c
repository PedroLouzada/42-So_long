/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_treatment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 18:02:11 by pbongiov          #+#    #+#             */
/*   Updated: 2025/08/14 18:46:58 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	count_digits(int n)
{
	int	i;

	i = 1;
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	draw_digits(t_game *game, int n, int x)
{
	int	i;

	if (n >= 10)
		draw_digits(game, n / 10, x - 32);
	i = n % 10;
	mlx_put_image_to_window(game->mlx, game->window, game->sprite->numbers[i],
		x, game->map.height * 64 - 48);
}

void	calculate_steps_sprite(t_game *game, int n, int x)
{
	int	start_x;

	start_x = x + (count_digits(n) - 1) * 32;
	draw_digits(game, n, start_x);
}

void	animation_time(t_game *game)
{
	static unsigned long	last_time;
	unsigned long			current_time;

	current_time = get_time();
	if (current_time - last_time < 160)
		return ;
	last_time = current_time;
	game->sprite->count_p++;
	if (game->sprite->count_p >= 3)
		game->sprite->count_p = 0;
	game->sprite->count_w++;
	if (game->sprite->count_w >= 6)
		game->sprite->count_w = 0;
	game->sprite->count_c++;
	if (game->sprite->count_c >= 4)
		game->sprite->count_c = 0;
	game->sprite->count_e++;
	if (game->sprite->count_e >= 4)
		game->sprite->count_e = 0;
}

void	print_steps(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->window, game->sprite->steps[0], 16,
		game->map.height * 64 - 48);
	mlx_put_image_to_window(game->mlx, game->window, game->sprite->steps[1], 48,
		game->map.height * 64 - 48);
	mlx_put_image_to_window(game->mlx, game->window, game->sprite->steps[2], 80,
		game->map.height * 64 - 48);
	mlx_put_image_to_window(game->mlx, game->window, game->sprite->steps[3],
		112, game->map.height * 64 - 48);
	mlx_put_image_to_window(game->mlx, game->window, game->sprite->steps[0],
		144, game->map.height * 64 - 48);
	calculate_steps_sprite(game, game->player.steps, 176);
}
