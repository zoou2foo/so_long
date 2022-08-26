/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:21:28 by vjean             #+#    #+#             */
/*   Updated: 2022/08/26 16:25:52 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdarg.h>
# include <mlx.h>

typedef struct s_elem
{
	int		x;
	int		y;
	int		fd;
	char	**map;
}	t_elem;

typedef struct s_mlx
{
	int		*mlx;
	int		*win;
	void	*player;
}	t_mlx;
/*

*/

int		check_map(char *arg, int ac);
int		size_map(t_elem *init_map);
int		move_map_to_tab(t_elem *init_map);
int		validation_top_and_bottom(t_elem *init_map);
int		validation_right_and_left(t_elem *init_map);
int		check_sets_map(t_elem *init_map);
int		check_format(t_elem *init_map);
void	close_game(int keycode, t_mlx *game);
int		ft_keys(int keycode, t_mlx *game);
void	check_all_map(t_elem *init_map);
void	init_mlx(t_mlx *game);

#endif