/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_treatment_utils_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 18:28:04 by pbongiov          #+#    #+#             */
/*   Updated: 2025/08/09 16:50:09 by pbongiov         ###   ########.fr       */
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
	while (game->map.coordinate[i])
	{
		j = 0;
		while (game->map.coordinate[i][j])
		{
			if (game->map.coordinate[i][j] == 'C')
				collect++;
			else if (game->map.coordinate[i][j] == 'E')
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
	int	i;
	int	j;

	i = 0;
	while (game->map.coordinate[i])
	{
		j = 0;
		while (game->map.coordinate[i][j])
		{
			if (game->map.coordinate[i][j] == 'P')
				game->map.p++;
			else if (game->map.coordinate[i][j] == 'C')
				game->map.c++;
			else if (game->map.coordinate[i][j] == 'E')
				game->map.e++;
			else if (game->map.coordinate[i][j] != '1'
				&& game->map.coordinate[i][j] != '\n'
				&& game->map.coordinate[i][j] != '0')
				error_msg(game);
			j++;
		}
		i++;
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
