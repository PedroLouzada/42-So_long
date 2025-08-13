/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_treatment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 18:02:11 by pbongiov          #+#    #+#             */
/*   Updated: 2025/08/13 17:02:21 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	animation_time(t_game *game)
{
	static unsigned long	last_time;
	unsigned long			current_time;

	current_time = get_time();
	if (current_time - last_time < 160)
		return ;
	last_time = current_time;
	game->sprite->animation.count_player_idle++;
	if (game->sprite->animation.count_player_idle >= 3)
		game->sprite->animation.count_player_idle = 0;
	game->sprite->animation.count_walk++;
	if (game->sprite->animation.count_walk >= 6)
		game->sprite->animation.count_walk = 0;
	game->sprite->animation.count_collect++;
	if (game->sprite->animation.count_collect >= 4)
		game->sprite->animation.count_collect = 0;
	game->sprite->animation.count_enemy_idle++;
	if (game->sprite->animation.count_enemy_idle >= 4)
		game->sprite->animation.count_enemy_idle = 0;
}

static void	print_steps(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->window, game->sprite->steps[0], 16, game->map.height * 55);
	mlx_put_image_to_window(game->mlx, game->window, game->sprite->steps[1], 48, game->map.height * 55);
	mlx_put_image_to_window(game->mlx, game->window, game->sprite->steps[2], 80, game->map.height * 55);
	mlx_put_image_to_window(game->mlx, game->window, game->sprite->steps[3], 112, game->map.height * 55);
	mlx_put_image_to_window(game->mlx, game->window, game->sprite->steps[0], 144, game->map.height * 55);
}

void	print_player(t_game *game)
{
	mlx_clear_window(game->mlx, game->window);
	create_map(game);
	if (!game->player.look_left)
	{
		if ((!game->keys[W] && !game->keys[S] && !game->keys[A]
				&& !game->keys[D]) || ((game->keys[W] && game->keys[S])
				|| (game->keys[A] && game->keys[D])))
			put_img(game, game->sprite->animation.player_idle[game->sprite->animation.count_player_idle], game->player.x, game->player.y);
		else
			put_img(game,
				game->sprite->animation.player_walk[game->sprite->animation.count_walk], game->player.x, game->player.y);
	}
	else
	{
		if ((!game->keys[W] && !game->keys[S] && !game->keys[A] && !game->keys[D])
			|| ((game->keys[W] && game->keys[S]) || (game->keys[A] && game->keys[D])))
			put_img(game, game->sprite->animation.player_idle_left[game->sprite->animation.count_player_idle], game->player.x, game->player.y);
		else
			put_img(game, game->sprite->animation.player_walk_left[game->sprite->animation.count_walk], game->player.x, game->player.y);
	}
	mlx_put_image_to_window(game->mlx, game->window, game->sprite->animation.canva, 0, 0);
	print_steps(game);
	animation_time(game);
}
