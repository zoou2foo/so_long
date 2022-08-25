/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_with_event.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:12:37 by vjean             #+#    #+#             */
/*   Updated: 2022/08/25 16:36:17 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>

typedef struct s_vars {
    void    *mlx;
    void    *win;
}   t_vars;

//(below) to set up W A S D. pour compter le nb de moves
int key_hook(int keycode, t_vars *vars) 
{
    printf("hello from key_hook!\n"); //pour imprimer le nb de moves
    return (0);
}

//(below) pour fermer le jeu. Il faut set up ESC though. ASCII: 27 
int close(int keycode, t_vars *vars)
{
    mlx_destroy_window(vars->mlx, vars->win);
    return (0);
}

int main(void)
{
    t_vars  vars;

    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 640, 480, "so long");
    mlx_key_hook(vars.win, key_hook, &vars);
    mlx_loop(vars.mlx);
}