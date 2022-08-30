/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 08:31:32 by vjean             #+#    #+#             */
/*   Updated: 2022/08/30 11:41:20 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map(char *arg, int ac)
{
	int		ext;

	if (ac != 2)
	{
		printf("Error:\n must have one argument only.");
		exit (0);
	}
	ext = ft_strlen(arg) - 4;
	if (ft_strncmp(&arg[ext], ".ber", 4) != 0)
	{	
		printf("Error:\n the argument must be a .ber extension");
		return (0);
	}
	return (1);
}

void	size_map(t_elem *init_map)
{
	init_map->x = 0;
	while (get_next_line(init_map->fd) != NULL)
	{		
		printf("%d\n", init_map->x);
		init_map->x++;
	}
}

int	move_map_to_tab(t_elem *init_map)
{
	init_map->map = malloc(sizeof(char *) * init_map->x + 1);
	init_map->x = 0;
	init_map->map[init_map->x] = get_next_line(init_map->fd);
	printf("%s", init_map->map[init_map->x]);
	while (1)
	{
		init_map->x++;
		init_map->map[init_map->x] = get_next_line(init_map->fd);
		printf("%s", init_map->map[init_map->x]);
		if (init_map->map[init_map->x] == NULL)
		{
			break ;
		}
	}
	return (1);
}
//something fucked up in validation of the right wall.. ^
//All good now! I was missing () to what I was sending to strlen
//créer une fonction pour free ou non?