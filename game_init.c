/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 09:21:30 by vjean             #+#    #+#             */
/*   Updated: 2022/08/29 15:27:58 by vjean            ###   ########.fr       */
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
}

void	game_put_image(t_elem *init_map)
{
	int		index;
	size_t	j;

	index = 0;
	while (index < init_map->x)
	{
		j = 0;
		while (j < ft_strlen(init_map->map[0]) - 1)
		{
			if (init_map->map[index][j] == '1')
			{
				mlx_put_image_to_window(init_map->mlx,
					init_map->win, init_map->t_images.wall, 0, 0);
			}
			j++;
		}
		index++;
	}
}
//quand finit la rangée remet colonne à zéro
//chaque fois que j'ajoute une image additionne 64 += autant pour ranger que 
//colonne. Quand la première rangée est complète. On remet colonne à zéro et on
//additionne 64 à x (ou rangée)