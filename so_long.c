/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:06:01 by vjean             #+#    #+#             */
/*   Updated: 2022/08/26 16:36:01 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_mlx(t_mlx *game)
{
	game->win = mlx_new_window(game->mlx, 640, 480, "so long");
	mlx_hook(game->win, 2, 0, &ft_keys, game);
	mlx_loop(game->mlx);
}

int	main(int ac, char **av)
{
	t_elem	*init_map;
	t_mlx	*game;

	init_map = malloc(sizeof(t_elem));
	game = malloc(sizeof(t_mlx));
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
	game->mlx = mlx_init();
	init_mlx(game);
	return (0);
}
//is possible to move 'check_map' and 'size_map' en dehors du 'main' et call
//une autre fonction