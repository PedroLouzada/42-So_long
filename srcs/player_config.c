/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_config.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 16:51:14 by pbongiov          #+#    #+#             */
/*   Updated: 2025/08/08 20:09:29 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int player_movement(t_game *game)
{
    static unsigned long last_time;
    unsigned long current_time;

    current_time = get_time();
    if (current_time - last_time < 7)
        return (0);
    last_time = current_time;
    if (game->keys[W] && colision_check(game, 0))
        game->player.y -= 1;
    if (game->keys[S] && colision_check(game, 1))
        game->player.y += 1;
    if (game->keys[A] && colision_check(game, 2))
        game->player.x -= 1;
    if (game->keys[D] && colision_check(game, 3))
        game->player.x += 1;
    print_images(game);
    return (0);
}
