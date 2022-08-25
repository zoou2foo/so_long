/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:21:28 by vjean             #+#    #+#             */
/*   Updated: 2022/08/25 13:21:38 by vjean            ###   ########.fr       */
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

typedef struct s_elem
{
	int		x;
	int		y;
	int		fd;
	char	**map;
}	t_elem;

/*

*/

int	check_map(char *arg, int ac);
int	size_map(t_elem *init_map);
int	move_map_to_tab(t_elem *init_map);
int	validation_top_and_bottom(t_elem *init_map);
int	validation_right_and_left(t_elem *init_map);
int	check_sets_map(t_elem *init_map);
int	check_format(t_elem *init_map);

#endif