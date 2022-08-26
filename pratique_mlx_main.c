/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pratique_mlx_main.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 11:03:53 by vjean             #+#    #+#             */
/*   Updated: 2022/08/26 13:37:03 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <unistd.h>
#include "so_long.h"

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int	deal_key(int key, t_momo *test)
{
	ft_putchar('X');
	if (key == 53)
	{
		mlx_destroy_window(test->mlx, test->win);
		printf("Done");
		exit (0);
	}
	else
	{
		printf("Coucou");
		exit (0);
	}

	return (0);
}

int main()
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_momo	*test;

	test = malloc(sizeof(t_momo));
	test->mlx = mlx_init(); //pour démarrer graphic server
	test->win = mlx_new_window(test->mlx, 500, 500, "bob");
	//(mlx_ptr, int size x, int size y, char *title) mlx_ptr est le lien à la 
	//connexion au serveur, x et y sont pour la taille de la fenêtre, 
	//title pour le titre
	mlx_key_hook(test->win, &deal_key, test);
	mlx_loop(test->mlx);
}