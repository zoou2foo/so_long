/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 09:21:30 by vjean             #+#    #+#             */
/*   Updated: 2022/08/30 10:37:29 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	xpm_to_image(t_elem *init_map)
{
	init_map->t_images.wall = mlx_xpm_file_to_image(init_map->mlx,
			"images/iceberg.xpm", &init_map->t_images.size2,
			&init_map->t_images.size);
	init_map->t_images.player = mlx_xpm_file_to_image(init_map->mlx,
			"images/penguin.xpm", &init_map->t_images.size2,
			&init_map->t_images.size);
	init_map->t_images.collect = mlx_xpm_file_to_image(init_map->mlx,
			"images/fish.xpm", &init_map->t_images.size2,
			&init_map->t_images.size);
	init_map->t_images.exit = mlx_xpm_file_to_image(init_map->mlx,
			"images/door.xpm", &init_map->t_images.size2,
			&init_map->t_images.size);
	init_map->t_images.enemy = mlx_xpm_file_to_image(init_map->mlx,
			"images/shark.xpm", &init_map->t_images.size2,
			&init_map->t_images.size);
	init_map->t_images.floor = mlx_xpm_file_to_image(init_map->mlx,
			"images/ocean.xpm", &init_map->t_images.size2,
			&init_map->t_images.size);
}

void	ft_put_image(int index, size_t j, t_elem *init_map)
{
	if (init_map->map[index][j] == '1')
	{
		mlx_put_image_to_window(init_map->mlx,
			init_map->win, init_map->t_images.wall, init_map->row,
			init_map->col);
	}
	if (init_map->map[index][j] == '0')
	{
		mlx_put_image_to_window(init_map->mlx, init_map->win,
			init_map->t_images.floor, init_map->row,
			init_map->col);
	}
}

void	ft_put_image_two(int index, size_t j, t_elem *init_map)
{
	if (init_map->map[index][j] == 'N')
	{
		mlx_put_image_to_window(init_map->mlx, init_map->win,
			init_map->t_images.enemy, init_map->row,
			init_map->col);
	}
	if (init_map->map[index][j] == 'P')
	{
		mlx_put_image_to_window(init_map->mlx, init_map->win,
			init_map->t_images.player, init_map->row,
			init_map->col);
	}
	if (init_map->map[index][j] == 'E')
	{
		mlx_put_image_to_window(init_map->mlx, init_map->win,
			init_map->t_images.exit, init_map->row,
			init_map->col);
	}
	if (init_map->map[index][j] == 'C')
	{
		mlx_put_image_to_window(init_map->mlx, init_map->win,
			init_map->t_images.collect, init_map->row,
			init_map->col);
	}
}

void	game_put_image(t_elem *init_map)
{
	int		index;
	size_t	j;

	index = 0;
	while (index < init_map->x)
	{
		j = 0;
		init_map->row = 0;
		while (j < ft_strlen(init_map->map[0]) - 1)
		{
			if (init_map->map[index][j] == '1'
				|| init_map->map[index][j] == '0')
			{
				ft_put_image(index, j, init_map);
			}
			else
			{	
				ft_put_image_two(index, j, init_map);
			}
			j++;
			init_map->row += 64;
		}
		init_map->col += 64;
		index++;
	}
}
