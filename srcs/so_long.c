/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:27:56 by pbongiov          #+#    #+#             */
/*   Updated: 2025/08/07 19:54:38 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int ac, char **av)
{
	static t_game	game;
	(void)ac;
	if (ac == 2)
	{
		game.sprite = malloc(sizeof(t_sprite));
		if (!game.sprite)
			return (0);
		map_validation(&game, av[1]);
		game_start(&game);
		create_map(&game);
		mlx_loop(game.mlx);
		exit_game(&game);
	}
	return (0);
}
