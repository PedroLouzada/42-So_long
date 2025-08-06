/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_treatment_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:35:54 by pbongiov          #+#    #+#             */
/*   Updated: 2025/08/04 19:23:32 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int row_len(char *filename)
{
	int i;
	int fd;
	char *s;

	i = 0;
	fd = open(filename, O_RDONLY);
	s = get_next_line(fd);
	if (!s)
		return (0);
	while(s[i] && s[i] != '\n')
		i++;
	free(s);
	close (fd);
	return (i);
}

int coll_len(char *filename)
{
	int i;
	int fd;
	char *s;

	i = 0;
	fd = open(filename, O_RDONLY);
	s = get_next_line(fd);
	while(s && s[0] != '\n')
	{
		i++;
		free(s);
		s = get_next_line(fd);
	}
	free(s);
	close(fd);
	return (i);
}
