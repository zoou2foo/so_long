/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:11:21 by vjean             #+#    #+#             */
/*   Updated: 2022/08/30 20:05:11 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
//break below to not go through with this function
void	go_up(t_elem *init_map)
{
	size_t i;
	int ii;

	i = 0;
	while (i < ft_strlen(init_map->map[0]) - 1)
	{
		ii = 0;
		while (init_map->map[i][ii] != '\n')
		{
			if (init_map->map[i][ii] == 'P' && init_map->map[i - 1][ii] != '1'
				&& init_map->map[i - 1][ii] != 'E')
			{
				move_player_up(init_map, i, ii);
				break ;
			}
			if (init_map->map[i][ii] == 'P' && init_map->map[i - 1][ii] == 'E'
				&& init_map->fish == 0)
				end_game_winner(init_map);
			ii++;
		}
		i++;
	}
}

void move_player_up(t_elem *init_map, size_t i, int ii)
{
	if (init_map->map[i - 1][ii] == 'C')
		init_map->fish--;
	if (init_map->map[i - 1][ii] == 'N')
		end_game(init_map);
	init_map->map[i - 1][ii] = 'P';
	init_map->map[i][ii] = '0';
	printf("%d MOVES\n", init_map->t_images.moves += 1);
}
/*	maybe need init_map->map[i][ii] = '0' at the beginning. Does not make sense
to me there
maybe need else if fish = 0 but not sure. Does not make sense either.		
	else if (init_map->map[i - 1][ii] == 'E' && init_map->fish == 0)
	{
		printf("Winner! Gagnant!");
		mlx_destroy_window(init_map->mlx, init_map->win);
		exit (0);
	}
	return (0); */

void end_game_winner(t_elem *init_map)
{
	printf("Winner! Gagnant!");
	mlx_destroy_window(init_map->mlx, init_map->win);
	exit (0);
}

void end_game(t_elem *init_map)
{
	printf("You've been killed by a baby shark! Doo doo doo doo");
	mlx_destroy_window(init_map->mlx, init_map->win);
	exit (0);
}