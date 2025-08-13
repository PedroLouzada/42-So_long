/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 17:17:45 by pbongiov          #+#    #+#             */
/*   Updated: 2025/08/13 17:30:46 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


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
	game->sprite->exit = mlx_xpm_file_to_image(game->mlx,
			"imgs/assets/exit.xpm", &game->sprite->w, &game->sprite->h);
	game->sprite->floor = mlx_xpm_file_to_image(game->mlx,
			"imgs/assets/grass.xpm", &game->sprite->w, &game->sprite->h);
	game->sprite->wall = mlx_xpm_file_to_image(game->mlx,
			"imgs/assets/wall.xpm", &game->sprite->w, &game->sprite->h);
	general_declaration(game);
	game->player.x *= 64;
	game->player.y *= 64;
	mlx_hook(game->window, 17, 0, exit_game, game);
	mlx_hook(game->window, 2, (1L << 0), key_press, game);
	mlx_hook(game->window, 3, (1L << 1), key_realease, game);
	mlx_loop_hook(game->mlx, player_movement, game);
}
