/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playing_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjean <vjean@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:35:51 by vjean             #+#    #+#             */
/*   Updated: 2022/08/25 16:06:41 by vjean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

typedef struct s_data
{
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}   t_data;


void    my_mlx_pixel_put(t_data *data, int x, int y, int colour)
{
    char *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = colour;
}

int main()
{
    void    *mlx;
    void    *mlx_win;
    t_data  img;
    
    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1920, 1080, "So long");
    img.img = mlx_new_image(mlx, 1920, 1080);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
        &img.endian);
    my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
    mlx_put_image_to_window(mlx, mlx_win, img.img, 250, 250);
    mlx_put_image_to_window(mlx, mlx_win, img.img, 250, 251);
    mlx_put_image_to_window(mlx, mlx_win, img.img, 250, 252);
    mlx_put_image_to_window(mlx, mlx_win, img.img, 250, 253);
    mlx_loop(mlx);
}