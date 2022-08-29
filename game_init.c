/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 09:21:30 by vjean             #+#    #+#             */
/*   Updated: 2022/08/29 10:30:56 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_mlx *game)
{
	char	*relative_path;
	int		img_w;
	int		img_h;

	relative_path = "images/ocean.xpm";
	game->mlx = mlx_init();
	game->floor = mlx_xpm_file_to_image(game, relative_path, &img_w, &img_h);
	while ()
	mlx_put_image_to_window(game->mlx, game->win, game->player, 0, 0);
}