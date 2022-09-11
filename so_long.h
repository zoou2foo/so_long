/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:21:28 by vjean             #+#    #+#             */
/*   Updated: 2022/09/11 17:54:05 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "minilibx_opengl_20191021/mlx.h"
//# include <mlx.h>

typedef struct s_mlx
{
	int		size;
	int		size2;
	void	*player;
	void	*enemy;
	void	*collect;
	void	*wall;
	void	*floor;
	void	*exit;
	int		moves;
}	t_images;

typedef struct s_elem
{
	int				*mlx;
	int				*win;
	int				x;
	int				y;
	int				fd;
	int				row;
	int				col;
	int				fish;
	int				penguin;
	int				door;
	char			**map;
	struct s_mlx	t_images;
}	t_elem;

int		check_map(char *arg, int ac);
void	size_map(t_elem *init_map);
int		move_map_to_tab(t_elem *init_map);
int		validation_top_and_bottom(t_elem *init_map);
int		validation_right_and_left(t_elem *init_map);
void	check_sets_map(t_elem *init_map);
int		check_format(t_elem *init_map);
void	key_hook(int keycode, t_elem *init_map);
int		ft_keys(int keycode, t_elem *init_map);
void	check_all_map(t_elem *init_map);
void	init_mlx(t_elem *init_map);
void	create_window(t_elem *init_map);
void	xpm_to_image(t_elem *init_map);
void	ft_put_image(int index, size_t j, t_elem *init_map);
void	ft_put_image_two(int index, size_t j, t_elem *init_map);
void	check_player(t_elem *init_map);
void	check_exit(t_elem *init_map);
int		ft_exit(t_elem *init_map);
void	key_moves(int keycode, t_elem *init_map);
void	go_up(t_elem *init_map);
void	move_player_up(t_elem *init_map, size_t i, int ii);
void	end_game_winner(t_elem *init_map);
void	end_game(t_elem *init_map);
void	go_left(t_elem *init_map);
void	move_player_left(t_elem *init_map, size_t i, int ii);
void	go_down(t_elem *init_map);
void	move_player_down(t_elem *init_map, size_t i, int ii);
void	go_right(t_elem *init_map);
void	move_player_right(t_elem *init_map, size_t i, int ii);
void	put_image_all(t_elem *init_map, int index, size_t j);
char	*moves_to_screen(t_elem *init_map);
void	free_dbl_ptr(char **ptr);
void	ft_no_collect(t_elem *init_map);
void	backslash_n_map(t_elem *init_map);

#endif