/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_enemy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:19:52 by vjean             #+#    #+#             */
/*   Updated: 2022/09/01 15:35:32 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_enemy_r(t_elem *init_map)
{
	int	i;
	int	ii;

	i = 0;
	while (i < init_map->x - 1)
	{
		ii = 0;
		while (init_map->map[i][ii] != '\n')
		{
			if (init_map->map[i][ii] == 'N' && init_map->map[i][ii + 1] != '1'
				&& init_map->map[i][ii + 1] != 'C'
				&& init_map->map[i][ii + 1] != 'E')
				move_enemy_right(init_map, i, ii);
		}
		ii++;
	}
	i++;
}

void	move_enemy_right(t_elem *init_map, int i, int ii)
{
	init_map->map[i][ii + 1] = 'N';
	init_map->map[i][ii] = '0';
}

void	move_enemy_l(t_elem *init_map)
{
	int	i;
	int	ii;

	i = 0;
	while (i < init_map->x - 1)
	{
		ii = 0;
		while (init_map->map[i][ii] != '\n')
		{
			if (init_map->map[i][ii] == 'N' && init_map->map[i][ii - 1] != '1'
				&& init_map->map[i][ii - 1] != 'C'
				&& init_map->map[i][ii - 1] != 'E')
				move_enemy_left(init_map, i, ii);
		}
		ii++;
	}
	i++;
}

void	move_enemy_left(t_elem *init_map, int i, int ii)
{
	init_map->map[i][ii - 1] = 'N';
	init_map->map[i][ii] = '0';
}