/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_treatment_utils_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 18:28:04 by pbongiov          #+#    #+#             */
/*   Updated: 2025/08/14 18:06:14 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	char_check_after(t_game *game)
{
	int	i;
	int	j;
	int	collect;

	i = 0;
	collect = 0;
	game->map.e = 0;
	while (game->map.arr[i])
	{
		j = 0;
		while (game->map.arr[i][j])
		{
			if (game->map.arr[i][j] == 'C')
				collect++;
			else if (game->map.arr[i][j] == 'E')
				game->map.e++;
			j++;
		}
		i++;
	}
	if (collect != 0 || game->map.e != 0)
		error_msg(game);
}

void	char_check_before(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map.arr[y])
	{
		x = 0;
		while (game->map.arr[y][x])
		{
			if (game->map.arr[y][x] == 'P')
				game->map.p++;
			else if (game->map.arr[y][x] == 'C')
				game->map.c++;
			else if (game->map.arr[y][x] == 'E')
				game->map.e++;
			else if (game->map.arr[y][x] != '1' && game->map.arr[y][x] != '0'
				&& game->map.arr[y][x] != 'X')
				error_msg(game);
			x++;
		}
		y++;
	}
	if (game->map.p != 1 || game->map.c == 0 || game->map.e != 1)
		error_msg(game);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}
