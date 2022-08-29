/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 15:02:35 by vjean             #+#    #+#             */
/*   Updated: 2022/08/29 14:10:13 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	close_game(int keycode, t_elem *init_map)
{
	write(1, "x", 1);
	if (keycode == 53)
	{
		mlx_destroy_window(init_map->mlx, init_map->win);
		printf("Done");
		exit (1);
	}
	else
	{
		printf("Done 2");
		exit (1);
	}
}

int	ft_keys(int keycode, t_elem *init_map)
{
	close_game(keycode, init_map);
	return (0);
}