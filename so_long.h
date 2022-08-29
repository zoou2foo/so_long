/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:21:28 by vjean             #+#    #+#             */
/*   Updated: 2022/08/29 14:48:22 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "mlx/minilibx-linux/mlx.h"

typedef struct s_mlx
{
	int		size;
	int		size2;
	void	*player;
	void	*enemy;
	void	*collect;
	void	*wall;
	void	*exit;
}	t_images;

typedef struct s_elem
{
	int				*mlx;
	int				*win;
	int				x;
	int				y;
	int				fd;
	char			**map;
	struct s_mlx	t_images;
}	t_elem;

/*
//	void			*wall; dans s_elem
*/

int		check_map(char *arg, int ac);
int		size_map(t_elem *init_map);
int		move_map_to_tab(t_elem *init_map);
int		validation_top_and_bottom(t_elem *init_map);
int		validation_right_and_left(t_elem *init_map);
int		check_sets_map(t_elem *init_map);
int		check_format(t_elem *init_map);
void	close_game(int keycode, t_elem *init_map);
int		ft_keys(int keycode, t_elem *init_map);
void	check_all_map(t_elem *init_map);
void	init_mlx(t_elem *init_map);
void	game_put_image(t_elem *init_map);
void	xpm_to_image(t_elem *init_map);

#endif