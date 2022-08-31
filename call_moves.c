/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:11:21 by vjean             #+#    #+#             */
/*   Updated: 2022/08/31 16:37:29 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
//break below to not go through with this function
void	go_up(t_elem *init_map)
{
	int	i;
	int	ii;

	i = 0;
	while (i < init_map->x - 1)
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

void	go_left(t_elem *init_map)
{
	int	i;
	int	ii;

	i = 0;
	while (i < init_map->x - 1)
	{
		ii = 0;
		while (init_map->map[i][ii] != '\n')
		{
			if (init_map->map[i][ii] == 'P' && init_map->map[i][ii - 1] != '1'
				&& init_map->map[i][ii - 1] != 'E')
			{
				move_player_left(init_map, i, ii);
				break ;
			}
			if (init_map->map[i][ii] == 'P' && init_map->map[i][ii - 1] == 'E'
				&& init_map->fish == 0)
				end_game_winner(init_map);
			ii++;
		}
		i++;
	}
}

//int result pour ne pas descendre d'un coup, car le break me sortait seulement
//du 2e while(le break était là, du if).
void	go_down(t_elem *init_map)
{
	int	i;
	int	ii;
	int	flag;

	i = 0;
	flag = 0;
	while (i < init_map->x - 1 && flag != 1)
	{
		ii = 0;
		while (init_map->map[i][ii] != '\n')
		{
			if (init_map->map[i][ii] == 'P' && init_map->map[i + 1][ii] != '1'
				&& init_map->map[i + 1][ii] != 'E')
			{
				move_player_down(init_map, i, ii);
				flag = 1;
			}
			if (init_map->map[i][ii] == 'P' && init_map->map[i + 1][ii] == 'E'
				&& init_map->fish == 0)
				end_game_winner(init_map);
			ii++;
		}
		i++;
	}
}

void	go_right(t_elem *init_map)
{
	int	i;
	int	ii;

	i = 0;
	while (i < init_map->x - 1)
	{
		ii = 0;
		while (init_map->map[i][ii] != '\n')
		{
			if (init_map->map[i][ii] == 'P' && init_map->map[i][ii + 1] != '1'
				&& init_map->map[i][ii + 1] != 'E')
			{
				move_player_right(init_map, i, ii);
				break ;
			}
			if (init_map->map[i][ii] == 'P' && init_map->map[i][ii + 1] == 'E'
				&& init_map->fish == 0)
				end_game_winner(init_map);
			ii++;
		}
		i++;
	}
}

void	end_game_winner(t_elem *init_map)
{
	printf("Winner! Gagnant!");
	mlx_destroy_window(init_map->mlx, init_map->win);
	exit (0);
}
