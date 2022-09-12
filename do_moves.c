/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:36:30 by vjean             #+#    #+#             */
/*   Updated: 2022/09/12 12:21:59 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player_up(t_elem *init_map, size_t i, int ii)
{
	if (init_map->map[i - 1][ii] == 'C')
		init_map->fish--;
	if (init_map->map[i - 1][ii] == 'N')
		end_game(init_map);
	init_map->map[i - 1][ii] = 'P';
	init_map->map[i][ii] = '0';
	init_map->t_images.moves++;
	create_window(init_map);
}

void	move_player_left(t_elem *init_map, size_t i, int ii)
{
	if (init_map->map[i][ii - 1] == 'C')
		init_map->fish--;
	if (init_map->map[i][ii - 1] == 'N')
		end_game(init_map);
	init_map->map[i][ii - 1] = 'P';
	init_map->map[i][ii] = '0';
	init_map->t_images.moves++;
	create_window(init_map);
}

void	move_player_down(t_elem *init_map, size_t i, int ii)
{
	if (init_map->map[i + 1][ii] == 'C')
		init_map->fish--;
	if (init_map->map[i + 1][ii] == 'N')
		end_game(init_map);
	init_map->map[i + 1][ii] = 'P';
	init_map->map[i][ii] = '0';
	init_map->t_images.moves++;
	create_window(init_map);
}

void	move_player_right(t_elem *init_map, size_t i, int ii)
{
	if (init_map->map[i][ii + 1] == 'C')
		init_map->fish--;
	if (init_map->map[i][ii + 1] == 'N')
		end_game(init_map);
	init_map->map[i][ii + 1] = 'P';
	init_map->map[i][ii] = '0';
	init_map->t_images.moves++;
	create_window(init_map);
}

void	end_game(t_elem *init_map)
{
	printf("You've been killed by a baby shark! Doo doo doo doo");
	mlx_destroy_window(init_map->mlx, init_map->win);
	//free_dbl_ptr(init_map->map);
	free_all_map(init_map);
	exit (0);
}
