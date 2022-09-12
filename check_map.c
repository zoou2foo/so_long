/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:31:50 by vjean             #+#    #+#             */
/*   Updated: 2022/09/12 12:20:38 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_sets_map(t_elem *init_map)
{
	int		i;
	size_t	j;

	i = -1;
	init_map->fish = 0;
	while (++i < init_map->x)
	{
		j = -1;
		while (++j < ft_strlen(init_map->map[0]) - 1)
		{
			if (ft_strchr("01PECN", init_map->map[i][j]) == NULL)
			{
				printf("Error:\n unknown elements on the map");
				//free_dbl_ptr(init_map->map);
				free_all_map(init_map);
				exit (0);
			}
			if (init_map->map[i][j] == 'C')
				init_map->fish += 1;
		}
	}
	ft_no_collect(init_map);
}

//parce que l'ordi ne scanne pas de haut en bas (pour le 2e while ^)

void	check_format(t_elem *init_map)
{
	int	i;
	int	j;
	int	first_line;

	i = 0;
	first_line = ft_strlen(init_map->map[init_map->x - 1]);
	while (i < init_map->x)
	{
		j = 0;
		while (init_map->map[i][j] != '\0' && init_map->map[i][j] != '\n')
			j++;
		if (j != first_line)
		{
			printf("Error:\n map is not a rectangle or a square");
			free_all_map(init_map);
			exit (0);
		}
		i++;
	}
}

void	validation_top_and_bottom(t_elem *init_map)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(init_map->map[0]) - 1)
	{
		if (init_map->map[0][i] != '1')
		{
			printf("Error:\n map invalid (top)\n");
			free_all_map(init_map);
			exit (0);
		}
		i++;
	}
	i = 0;
	while (i < ft_strlen(init_map->map[init_map->x - 1]))
	{
		if (init_map->map[init_map->x - 1][i] != '1')
		{
			printf("Error:\n map invalid (bottom)\n");
			free_all_map(init_map);
			exit (0);
		}
		i++;
	}
}

void	validation_right_and_left(t_elem *init_map)
{
	int		j;
	int		first_line;

	j = 0;
	while (j < init_map->x - 1)
	{
		if (init_map->map[j][0] != '1')
		{
			printf("Error:\n map invalid (left)\n");
			free_all_map(init_map);
			exit (0);
		}
		j++;
	}
	j = 1;
	first_line = ft_strlen((init_map->map[0]));
	while (j < init_map->x - 1)
	{
		if (init_map->map[j][first_line - 2] != '1')
		{
			printf("Error:\n map invalid wall(right)\n");
			free_all_map(init_map);
			exit (0);
		}
		j++;
	}
}

//prob in validation of the right wall.. ^
//All good now! I was missing () to what I was sending to strlen

void	check_all_map(t_elem *init_map)
{
	backslash_n_map(init_map);
	validation_top_and_bottom(init_map);
	validation_right_and_left(init_map);
	check_sets_map(init_map);
	check_player(init_map);
	check_exit(init_map);
	check_format(init_map);
}
