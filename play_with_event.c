/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_with_event.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:12:37 by vjean             #+#    #+#             */
/*   Updated: 2022/08/26 16:42:43 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include "so_long.h"


//(below) to set up W A S D. pour compter le nb de moves
/*int key_hook(int keycode, t_vars *vars) 
{
	printf("hello from key_hook!\n"); //pour imprimer le nb de moves
	return (0);
}*/

//(below) pour fermer le jeu. Il faut set up ESC though. ASCII: 27 
void	close_game(int keycode, t_mlx *game)
{
	write(1, "x", 1);
	if (keycode == 53)
	{
		mlx_destroy_window(game->mlx, game->win);
		printf("Done");
		exit (1);
	}
	else
	{
		printf("Done 2");
		exit (1);
	}
}

int	ft_keys(int keycode, t_mlx *game)
{
	close_game(keycode, game);
	return (0);
}

int main(void)
{
	t_mlx	*game;
	char	*relative_path;
	int		img_width;
	int		img_height;

	img_width = 200;
	img_height = 150;
	relative_path = "images/penguin.xpm";
	game = malloc(sizeof(t_mlx));
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 640, 480, "so long");
	game->player = mlx_xpm_file_to_image(game, relative_path, &img_width, &img_height);
	mlx_put_image_to_window(game->mlx, game->win, game->player, 200, 200);
	mlx_hook(game->win, 2, 0, &ft_keys, game);
	mlx_loop(game->mlx);
}
