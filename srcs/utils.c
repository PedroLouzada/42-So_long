/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 17:17:45 by pbongiov          #+#    #+#             */
/*   Updated: 2025/08/13 22:41:06 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void step_count(t_game *game)
{
	static int early_position_x;
	static int early_position_y;

	if (early_position_x == 0 && early_position_y == 0)
	{
		early_position_x = (game->player.x + 32) / 64;
		early_position_y = (game->player.y + 32)/ 64;
	}
	if ((game->player.x + 32) / 64 != early_position_x || (game->player.y + 32) / 64 != early_position_y)
	{
		early_position_x = (game->player.x + 32)/ 64;
		early_position_y = (game->player.y + 32)/ 64;
		game->player.steps++;
	}
}

static void	ft_bzero(void *s, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)s)[i] = '\0';
		i++;
	}
}

static void	*ft_calloc(size_t num, size_t size)
{
	void	*var;

	if (size != 0 && num > (size_t)-1 / size)
		return (NULL);
	var = malloc(num * size);
	if (!var)
		return (NULL);
	ft_bzero(var, (num * size));
	return (var);
}

void	game_start(t_game *game)
{
	int i;

	i = 0;
	game->sprite->animation.buffer = ft_calloc(game->map.height * 64, sizeof(int *));
	while (i < game->map.width)
		game->sprite->animation.buffer[i++] = ft_calloc(game->map.width * 64, sizeof(int));
	game->player.look_left = 0;
	game->mlx = mlx_init();
	game->sprite->animation.canva = mlx_new_image(game->mlx, game->map.width * 64, game->map.height * 64);
	game->window = mlx_new_window(game->mlx, game->map.width * 64,
			game->map.height * 64, "so_long");
	general_declaration(game);
	game->player.x *= 64;
	game->player.y *= 64;
	mlx_hook(game->window, 17, 0, exit_game, game);
	mlx_hook(game->window, 2, (1L << 0), key_press, game);
	mlx_hook(game->window, 3, (1L << 1), key_realease, game);
	mlx_loop_hook(game->mlx, player_movement, game);
}
void	error_msg(t_game *game)
{
	free_map(game);
	write(2, "Envie um mapa valido!\n", 22);
	exit(0);
}