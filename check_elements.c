/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:31:50 by vjean             #+#    #+#             */
/*   Updated: 2022/08/25 13:19:52 by vjean            ###   ########.fr       */
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
			if (ft_strchr("01PEC", init_map->map[i][j]) == NULL)
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
