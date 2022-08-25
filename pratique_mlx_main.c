/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pratique_mlx_main.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 11:03:53 by vjean             #+#    #+#             */
/*   Updated: 2022/08/08 11:43:06 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}


int deal_key(int key, void *param)
{
	ft_putchar('X');
	return (0);
}

int main()
{
	void	*mlx_ptr;
	void	*win_ptr;
	
	mlx_ptr = mlx_init(); //pour démarrer graphic server
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "bob");
	//(mlx_ptr, int size x, int size y, char *title) mlx_ptr est le lien à la 
	//connexion au serveur, x et y sont pour la taille de la fenêtre, 
	//title pour le titre
	mlx_key_hook(win_ptr, deal_key, (void*)0); //void*0 ignore this param
	mlx_loop(mlx_ptr);
}