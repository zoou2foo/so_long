/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 15:02:35 by vjean             #+#    #+#             */
/*   Updated: 2022/08/30 15:27:16 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_hook(int keycode, t_elem *init_map)
{
	//if (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2)
	//	check_moves(keycode, init_map);
	if (keycode == 53)
	{
		mlx_destroy_window(init_map->mlx, init_map->win);
		printf("Done");
		exit (1);
	}
}

int	ft_exit(void)
{
	printf("Exit game: you close the window");
	exit (0);
}

int	ft_keys(int keycode, t_elem *init_map)
{
	key_hook(keycode, init_map);
	return (0);
}

void	check_player(t_elem *init_map)
{
	int		i;
	size_t	j;

	i = 0;
	init_map->penguin = 0;
	while (i < init_map->x)
	{
		j = 0;
		while (j < ft_strlen(init_map->map[0]) - 1)
		{
			if (init_map->map[i][j] == 'P')
			{
				init_map->penguin += 1;
			}
			j++;
		}
		i++;
	}
	if (init_map->penguin > 1 || init_map->penguin == 0)
	{
		printf("Error:\nIt has to be ONE player ONLY! Boo hoo");
		exit (0);
	}
}

void	check_exit(t_elem *init_map)
{
	int		i;
	size_t	j;

	i = 0;
	init_map->door = 0;
	while (i < init_map->x)
	{
		j = 0;
		while (j < ft_strlen(init_map->map[0]) - 1)
		{
			if (init_map->map[i][j] == 'E')
			{
				init_map->door += 1;
			}
			j++;
		}
		i++;
	}
	if (init_map->door > 1 || init_map->door == 0)
	{
		printf("Error:\nThere must be ONE exit only");
		exit (0);
	}
}
