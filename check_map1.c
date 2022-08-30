/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:31:50 by vjean             #+#    #+#             */
/*   Updated: 2022/08/30 08:56:21 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_sets_map(t_elem *init_map)
{
	int		i;
	size_t	j;

	i = 0;
	while (i < init_map->x)
	{
		j = 0;
		while (j < ft_strlen(init_map->map[0]) - 1)
		{
			if (ft_strchr("01PECN", init_map->map[i][j]) == NULL)
			{
				printf("Error:\n missing important elements on the map");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

//parce que le fucking d'ordi ne scanne pas de haut en bas (pour le 2e while ^)

int	check_format(t_elem *init_map)
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
			return (0);
		}
		i++;
	}
	return (1);
}

int	validation_top_and_bottom(t_elem *init_map)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(init_map->map[0]) - 1)
	{
		if (init_map->map[0][i] != '1')
		{
			printf("Error:\n map invalid (top)\n");
			return (0);
		}
		i++;
	}
	i = 0;
	printf("Valeur de x: %d\n", init_map->x);
	while (i < ft_strlen(init_map->map[init_map->x - 1]))
	{
		if (init_map->map[init_map->x - 1][i] != '1')
		{
			printf("Error:\n map invalid (bottom)\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	validation_right_and_left(t_elem *init_map)
{
	int		j;
	int		first_line;

	j = 0;
	while (j < init_map->x - 1)
	{
		if (init_map->map[j][0] != '1')
		{
			printf("Error:\n map invalid (left)\n");
			return (0);
		}
		j++;
	}
	j = 0;
	first_line = ft_strlen((init_map->map[init_map->x - 1]) - 2);
	while (j < init_map->x)
	{
		if (init_map->map[j][first_line] != '1')
		{
			printf("Error:\n map invalid wall(right)\n");
			return (0);
		}
		j++;
	}
	return (1);
}

void	check_all_map(t_elem *init_map)
{
	validation_top_and_bottom(init_map);
	validation_right_and_left(init_map);
	check_sets_map(init_map);
	check_format(init_map);
}
