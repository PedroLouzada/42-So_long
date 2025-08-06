/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:28:23 by pbongiov          #+#    #+#             */
/*   Updated: 2025/08/04 17:28:46 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100

typedef struct s_map
{
	int			height;
	int			width;
	int			player;
	int			collectable;
	int			exit;
	int			empty_space;
	char		**coordinate;
}				t_map;

typedef struct s_player
{
	int			x;
	int			y;
	int			steps;
}				t_player;

typedef struct s_sprite
{
	int			w;
	int			h;
	void		*floor;
	void		*wall;
	void		*exit;
	void		*collectable;
	void		*player;
}				t_sprite;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	char		keys[80000];
	t_map		map;
	t_player	player;
	t_sprite	*sprite;
}				t_game;

int				exit_game(t_game *game);
int				key_press(int key, t_game *game);
void			free_game(t_game *game);
int				player_movement(t_game *game);
int				key_realease(int key, t_game *game);
unsigned long	get_time(void);
void			print_images(t_game *game);
void			game_start(t_game *game);
char			*get_next_line(int fd);
void			error_msg(void);
int				row_len(char *filename);
int				coll_len(char *filename);
void			map_initialize(t_game *game, char *filename);
void			map_input(t_game *game, char *filename);

#endif