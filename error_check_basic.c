/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_basic.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 08:31:32 by vjean             #+#    #+#             */
/*   Updated: 2022/09/12 14:17:10 by vjean            ###   ########.fr       */
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
		exit (0);
	}
	return (1);
}

void	size_map(t_elem *init_map)
{
	char	*str;

	init_map->x = 0;
	str = get_next_line(init_map->fd);
	while (str != NULL)
	{	
		init_map->x++;
		free (str);
		str = get_next_line(init_map->fd);
	}
	free (str);
}

void	backslash_n_map(t_elem *init_map)
{
	int	len;

	len = ft_strlen(init_map->map[0]);
	if (len < init_map->x)
	{
		printf("Error:\n map invalid (empty)\n");
		free_all_map(init_map);
		exit (0);
	}
}

void	move_map_to_tab(t_elem *init_map)
{
	init_map->map = malloc(sizeof(char *) * init_map->x + 1);
	init_map->x = 0;
	init_map->map[init_map->x] = get_next_line(init_map->fd);
	if (init_map->map[init_map->x] == NULL)
	{
		printf("Error:\ninvalid map");
		free (init_map->map);
		exit (0);
	}
	while (1)
	{
		init_map->x++;
		init_map->map[init_map->x] = get_next_line(init_map->fd);
		if (init_map->map[init_map->x] == NULL)
		{
			break ;
		}
	}
}

void	free_all_map(t_elem *init_map)
{
	int	i;

	i = 0;
	while (i < init_map->x)
	{
		free (init_map->map[i]);
		i++;
	}
}
