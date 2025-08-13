/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_declaration_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 17:25:09 by pbongiov          #+#    #+#             */
/*   Updated: 2025/08/13 17:32:43 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void number_img_2(t_game *game)
{
	game->sprite->numbers[7] = mlx_xpm_file_to_image(game->mlx,
			"imgs/steps_&_numbers/07_bold.xpm", &game->sprite->w,
			&game->sprite->h);
	game->sprite->numbers[8] = mlx_xpm_file_to_image(game->mlx,
			"imgs/steps_&_numbers/08_bold.xpm", &game->sprite->w,
			&game->sprite->h);
	game->sprite->numbers[9] = mlx_xpm_file_to_image(game->mlx,
			"imgs/steps_&_numbers/09_bold.xpm", &game->sprite->w,
			&game->sprite->h);
	game->sprite->steps[0] = mlx_xpm_file_to_image(game->mlx,
			"imgs/assets/steps_&_numbers/S_bold.xpm", &game->sprite->w,
			&game->sprite->h);
	game->sprite->steps[1] = mlx_xpm_file_to_image(game->mlx,
			"imgs/assets/steps_&_numbers/T_bold.xpm", &game->sprite->w,
			&game->sprite->h);
	game->sprite->steps[2] = mlx_xpm_file_to_image(game->mlx,
			"imgs/assets/steps_&_numbers/E_bold.xpm", &game->sprite->w,
			&game->sprite->h);
	game->sprite->steps[3] = mlx_xpm_file_to_image(game->mlx,
			"imgs/assets/steps_&_numbers/P_bold.xpm", &game->sprite->w,
			&game->sprite->h);
}
void numbers_img_declaration(t_game *game)
{
	game->sprite->numbers[0] = mlx_xpm_file_to_image(game->mlx,
			"imgs/steps_&_numbers/00_bold.xpm", &game->sprite->w,
			&game->sprite->h);
	game->sprite->numbers[1] = mlx_xpm_file_to_image(game->mlx,
			"imgs/steps_&_numbers/01_bold.xpm", &game->sprite->w,
			&game->sprite->h);
	game->sprite->numbers[2] = mlx_xpm_file_to_image(game->mlx,
			"imgs/steps_&_numbers/02_bold.xpm", &game->sprite->w,
			&game->sprite->h);
	game->sprite->numbers[3] = mlx_xpm_file_to_image(game->mlx,
			"imgs/steps_&_numbers/03_bold.xpm", &game->sprite->w,
			&game->sprite->h);
	game->sprite->numbers[4] = mlx_xpm_file_to_image(game->mlx,
			"imgs/steps_&_numbers/04_bold.xpm", &game->sprite->w,
			&game->sprite->h);
	game->sprite->numbers[5] = mlx_xpm_file_to_image(game->mlx,
			"imgs/steps_&_numbers/05_bold.xpm", &game->sprite->w,
			&game->sprite->h);
	game->sprite->numbers[6] = mlx_xpm_file_to_image(game->mlx,
			"imgs/steps_&_numbers/06_bold.xpm", &game->sprite->w,
			&game->sprite->h);
	 number_img_2(game);
}
