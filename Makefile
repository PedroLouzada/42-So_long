# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/21 17:25:21 by pbongiov          #+#    #+#              #
#    Updated: 2025/08/19 14:15:32 by pbongiov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a

MLX_SRCS = \
	$(MLX_DIR)/mlx_init.c \
	$(MLX_DIR)/mlx_new_window.c \
	$(MLX_DIR)/mlx_loop.c \
	$(MLX_DIR)/mlx_hook.c \
	$(MLX_DIR)/mlx_key_hook.c \
	$(MLX_DIR)/mlx_mouse_hook.c \
	$(MLX_DIR)/mlx_expose_hook.c \
	$(MLX_DIR)/mlx_destroy_window.c \
	$(MLX_DIR)/mlx_put_image_to_window.c \
	$(MLX_DIR)/mlx_new_image.c \
	$(MLX_DIR)/mlx_get_data_addr.c \
	$(MLX_DIR)/mlx_clear_window.c \
	$(MLX_DIR)/mlx_string_put.c

SRCS_FILES = get_next_line.c so_long.c utils.c player_config.c \
			 map_treatment.c map_treatment_utils.c image_declaration.c \
			 map_treatment_utils_2.c  image_treatment.c movment_config.c \
			 leak_handling.c print_map.c colision.c colision_utils.c \
			 image_declaration_2.c image_verification.c end_msg.c

SRCS_DIR = srcs

SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))

OBJS_DIR = objs

OBJS =$(addprefix $(OBJS_DIR)/, $(SRCS_FILES:.c=.o))

CFLAGS = -g -Wall -Wextra -Werror -I$(MLX_DIR)
MLXFLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

CC = cc

all: $(MLX_LIB) $(NAME)

$(MLX_LIB): $(MLX_SRCS)
	@$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS)  $(OBJS) -o $(NAME) $(MLXFLAGS)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean:		clean
	rm -rf $(NAME) $(OBJS_DIR)

re:		fclean 	all

r:
	make re && clear && ./so_long maps/teste.ber

.PHONY : all clean fclean re