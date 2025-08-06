# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/21 17:25:21 by pbongiov          #+#    #+#              #
#    Updated: 2025/08/04 15:35:35 by pbongiov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS_FILES = get_next_line.c so_long.c utils.c player_config.c map_treatment.c map_treatment_utils.c image_treatment.c

SRCS_DIR = srcs

SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))

OBJS_DIR = objs

OBJS	=$(addprefix $(OBJS_DIR)/, $(SRCS_FILES:.c=.o))

CFLAGS = -g -Wall -Wextra -Werror
MLXFLAGS = -Lmlx -lmlx -lXext -lX11 -lm

CC = cc

all:	$(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS)  $(OBJS) -o $(NAME) $(MLXFLAGS)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	rm -rf $(OBJS)

fclean:		clean
	rm -rf $(NAME)

re:		fclean 	all

r:
	make re && clear && ./so_long

.PHONY : all clean fclean re