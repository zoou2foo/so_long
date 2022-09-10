/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_basic.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 08:31:32 by vjean             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/09/09 22:07:50 by vjean            ###   ########.fr       */
=======
/*   Updated: 2022/09/06 11:13:56 by vjean            ###   ########.fr       */
>>>>>>> 02f64d124c6e142eae9097fbe7d2b0b46c61956a
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
	char	*str;

	init_map->x = 0;
	str = get_next_line(init_map->fd);
	while (str != NULL)
	{	
		free (str);
		init_map->x++;
		str = get_next_line(init_map->fd);
	}
}

int	move_map_to_tab(t_elem *init_map)
{
	init_map->map = malloc(sizeof(char *) * init_map->x + 1);
	init_map->x = 0;
	init_map->map[init_map->x] = get_next_line(init_map->fd);
	if (init_map->map[init_map->x] == NULL)
	{
		printf("Error:\ninvalid map");
		exit ;
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
	return (1);
}
