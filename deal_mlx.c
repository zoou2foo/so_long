/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 15:02:35 by vjean             #+#    #+#             */
/*   Updated: 2022/08/30 12:46:07 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_hook(int keycode, t_elem *init_map)
{
	if (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2)
		check_moves(keycode, init_map);
	else if (keycode == 53)
	{
		mlx_destroy_window(init_map->mlx, init_map->win);
		printf("Done");
		exit (1);
	}
}

int	ft_keys(int keycode, t_elem *init_map)
{
	key_hook(keycode, init_map);
	return (0);
}