/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_treatment_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:35:54 by pbongiov          #+#    #+#             */
/*   Updated: 2025/08/06 16:54:07 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

void row_and_col_len(t_game *game, char *filename)
{
	int i;
	int fd;
	char *s;

	i = 0;
	fd = open(filename, O_RDONLY);
	s = get_next_line(fd);
	if (!s)
		exit_game(game);
	game->map.width = ft_strlen(s);
	while(s && s[0] != '\n')
	{
		i++;
		free(s);
		s = get_next_line(fd);
	}
	free(s);
	close(fd);
	game->map.height = i;
}

void is_rectangular(char *s, t_game *game)
{
	static int i;

	if (ft_strlen(s) < 3)
	{
		free(s);
		free_map(game);
		exit(0);
	}
	if (i == 0)
		i = ft_strlen(s);
	else if (i != ft_strlen(s))
	{
		free(s);
		free_map(game);
		exit(0);
	}
	i = ft_strlen(s);
}

void is_closed(t_game *game)
{
	int i;
	
	i = 0;
	if (game->map.height < 3)
		error_msg(game);
	while (game->map.coordinate[0][i] && game->map.coordinate[0][i] != '\n')
	{
		if (game->map.coordinate[0][i] != '1'  || game->map.coordinate[game->map.height - 1][i] != '1')
			error_msg(game);
		i++;
	}
	i = 0;
	while (game->map.coordinate[i])
	{
		if (game->map.coordinate[i][0] != '1' || game->map.coordinate[i][game->map.width - 1] != '1')
			error_msg(game);
		i++;
	}
}
