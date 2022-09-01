/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:06:01 by vjean             #+#    #+#             */
/*   Updated: 2022/09/01 14:04:02 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*moves_to_screen(t_elem *init_map)
{
	char	*nb_of_moves;
	char	*str;

	str = ft_itoa(init_map->t_images.moves);
	nb_of_moves = ft_strjoin("Moves: ", str);
	free (str);
	return (nb_of_moves);
}

void	init_mlx(t_elem *init_map)
{
	init_map->mlx = mlx_init();
	init_map->win = mlx_new_window(init_map->mlx,
			(ft_strlen(init_map->map[0]) - 1) * 64, init_map->x * 64,
			"so_long");
	xpm_to_image(init_map);
	create_window(init_map);
	mlx_hook(init_map->win, 2, 0, &ft_keys, init_map);
	mlx_hook(init_map->win, 17, 0, ft_exit, init_map);
	mlx_loop(init_map->mlx);
}
//new_window pour la size de la win row * 64 et column * 64
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
	check_all_map(init_map);
	init_map->t_images.moves = 0;
	init_mlx(init_map);
	return (0);
}
//is possible to move 'check_map' and 'size_map' en dehors du 'main' et call
//une autre fonction