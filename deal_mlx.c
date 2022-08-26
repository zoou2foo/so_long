/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 15:02:35 by vjean             #+#    #+#             */
/*   Updated: 2022/08/26 15:03:13 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	close_game(int keycode, t_mlx *game)
{
	write(1, "x", 1);
	if (keycode == 53)
	{
		mlx_destroy_window(game->mlx, game->win);
		printf("Done");
		exit (1);
	}
	else
	{
		printf("Done 2");
		exit (1);
	}
}

int	ft_keys(int keycode, t_mlx *game)
{
	close_game(keycode, game);
	return (0);
}