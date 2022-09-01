/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_game_basic.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 15:02:35 by vjean             #+#    #+#             */
/*   Updated: 2022/09/01 15:57:54 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_hook(int keycode, t_elem *init_map)
{
	init_map->t_images.moves += 1;
	if (keycode == 13)
		go_up(init_map);
	if (keycode == 0)
	{
		go_left(init_map);
		move_enemy_l(init_map);
	}
	if (keycode == 1)
		go_down(init_map);
	if (keycode == 2)
	{
		go_right(init_map);
		move_enemy_r(init_map);
	}
	if (keycode == 53)
	{
		mlx_destroy_window(init_map->mlx, init_map->win);
		printf("WTF! You quit this fucking amazing game!?!");
		exit (1);
	}
//	create_window(init_map);
}
//might need to keep count of the moves here to reuse it to the moves on
//screen

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
