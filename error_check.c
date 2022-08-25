/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 08:31:32 by vjean             #+#    #+#             */
/*   Updated: 2022/08/25 13:21:10 by vjean            ###   ########.fr       */
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

int	size_map(t_elem *init_map)
{
	init_map->x = 0;
	while (get_next_line(init_map->fd) != NULL)
	{		
		printf("%d\n", init_map->x);
		init_map->x++;
	}
	return (1);
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
//something fucked up in validation of the right wall.. ^
//All good now! I was missing () to what I was sending to strlen

int	main(int ac, char **av)
{
	t_elem	*init_map;

	init_map = malloc(sizeof(t_elem));
	check_map(av[1], ac);
	init_map->fd = open(av[1], O_RDONLY);
	if (init_map->fd < 0)
		exit (0);
	size_map(init_map);
	close(init_map->fd);
	init_map->fd = open(av[1], O_RDONLY);
	if (init_map->fd < 0)
		exit (0);
	move_map_to_tab(init_map);
	validation_top_and_bottom(init_map);
	validation_right_and_left(init_map);
	check_sets_map(init_map);
	check_format(init_map);
	return (0);
}
