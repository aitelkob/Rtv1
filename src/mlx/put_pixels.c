/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixels.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 14:54:59 by yait-el-          #+#    #+#             */
/*   Updated: 2021/02/07 16:17:13 by yait-el-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rtv1.h"

/*void    imageput(t_mlix *mlix, int x, int y, int color)
{
    int i;

    if (x >= 0 && x <= mlix->win_x && y >= 0 && y <= (mlix->win_y))
    {
        printf("%d\n", mlix->size_line);
        i = (x * mlix->bits_per_pixel / 8) + (y * mlix->size_line);
        mlix->img[i] = color;
        mlix->img[++i] = color >> 8;
        mlix->img[++i] = color >> 16;
    }
}*/
//////////////// rire kan5awer fe code hena ft_put_pixel like imageput
//rire melit hhhh
//ketbto 7itache bari te5dem img -> char
void            ft_put_pixel(t_mlix *mlx,int x ,int y,int color)
{
	int i;
	unsigned int p;
	i = 0;
	p = x * (mlx->bits_per_pixel / 8) + y * ( 4);
	while (i < (mlx->bits_per_pixel / 8))
	{
		mlx->d[p + i] = color;
		color >>= 8;
		i++;
	}
	/*
	i = (x * fdf->bits_per_pixel / 8) + (y * fdf->size_line);
    fdf->data_addr[i] = color; // B — Blue
    fdf->data_addr[++i] = color >> 8; // G — Green
    fdf->data_addr[++i] = color >> 16; // R — Red
    fdf->data_addr[++i] = 0; // Alpha channel*/
}
