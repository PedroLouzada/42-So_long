/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:28:23 by pbongiov          #+#    #+#             */
/*   Updated: 2025/08/09 19:52:00 by pbongiov         ###   ########.fr       */
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
	int			p;
	int			c;
	int			e;
	char		**coordinate;
}				t_map;

typedef struct s_player
{
	int			x;
	int			y;
	int			collect;
	int			steps;
}				t_player;

typedef struct s_animation
{
	int			count_idle;
	int			count_walk;
	void		*player_idle[3];
	void		*player_walk[6];
}				t_animation;

typedef struct s_sprite
{
	int			w;
	int			h;
	void		*floor;
	void		*wall;
	void		*exit;
	void		*collectable;
	t_animation	player;
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
//==================== LEAK HANDLING ===============================
int				exit_game(t_game *game);
void			free_imgs(t_game *game);
void			error_msg(t_game *game);
void			free_map(t_game *game);
//======================= MOVMENT ==================================
int				key_press(int key, t_game *game);
int				player_movement(t_game *game);
int				key_realease(int key, t_game *game);
unsigned long	get_time(void);
int				colision_check(t_game *game, int i);
//======================= MAP PARSING ==============================
int				ft_strlen(char *s);
void			row_and_col_len(t_game *game, char *filename);
void			map_initialize(t_game *game, char *filename);
void			map_input(t_game *game, char *filename);
void			is_rectangular(char *s, t_game *game);
void			map_validation(t_game *game, char *filename);
void			is_closed(t_game *game);
void			char_check_before(t_game *game);
void			char_check_after(t_game *game);
void			flood_fill(char **map, int x, int y);
void			is_berfile(t_game *game, char *filename);
void			locate_player(t_game *game);
//======================== IMAGES ==================================
void			print_player(t_game *game);
void			create_map(t_game *game);
void			player_idle(t_game *game);
//====================== GAME GENERAL ==============================
void			game_start(t_game *game);
char			*get_next_line(int fd);

#endif