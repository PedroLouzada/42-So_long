/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:28:23 by pbongiov          #+#    #+#             */
/*   Updated: 2025/08/14 18:47:46 by pbongiov         ###   ########.fr       */
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
	char		**arr;
}				t_map;

typedef struct s_player
{
	int			x;
	int			y;
	int			collect;
	int			steps;
	int			look_left;
	int			die;
}				t_player;

typedef struct s_sprite
{
	int			w;
	int			h;
	void		*floor;
	void		*wall;
	void		*exit;
	void		*collectable[4];
	void		*steps[4];
	void		*numbers[10];
	int			count_p;
	int			count_e;
	int			count_w;
	int			count_c;
	void		*p_idle[3];
	void		*p_idle_l[3];
	void		*p_walk[6];
	void		*p_walk_l[6];
	void		*enemy[5];
	int			**buffer;
	void		*canva;
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
int				colision(t_game *game, int i);
void			step_count(t_game *game);
int				colision_top_down(t_game *game, int px_l, int px_r, int limit);
int				colision_left_right(t_game *game, int px_t, int px_d,
					int limit);
int				check_movment(t_game *game);
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
int				get_pixel(void *img, int x, int y);
void			put_img(t_game *game, void *img, int sx, int sy);
void			copy_buffer(t_game *game, int pixel, int x, int y);
void			numbers_img_declaration(t_game *game);
void			general_declaration(t_game *game);
void			calculate_steps_sprite(t_game *game, int n, int x);
void			check_img(t_game *game);
void			animation_time(t_game *game);
void			print_steps(t_game *game);
//====================== GAME GENERAL ==============================
void			game_start(t_game *game);
char			*get_next_line(int fd);
void			win_msg(void);
void			lose_msg(void);

#endif