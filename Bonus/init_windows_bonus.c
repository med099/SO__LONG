/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_windows_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouali <moouali@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:50:30 by moouali           #+#    #+#             */
/*   Updated: 2024/05/25 23:28:15 by moouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	check_textures(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (!mlx->texture[i])
			break ;
		i++;
	}
	if (i == 16)
		return ;
	i = 0;
	while (i < 16)
	{
		if (mlx->texture[i])
			mlx_delete_texture(mlx->texture[i]);
		i++;
	}
	ft_exit("Error load PNG\n", 1);
}

static void	load_txtr_to_img(t_mlx *mlx)
{
	mlx->img[0] = mlx_texture_to_image(mlx->mlx, mlx->texture[0]);
	mlx->img[1] = mlx_texture_to_image(mlx->mlx, mlx->texture[1]);
	mlx->img[2] = mlx_texture_to_image(mlx->mlx, mlx->texture[2]);
	mlx->img[3] = mlx_texture_to_image(mlx->mlx, mlx->texture[3]);
	mlx->img[4] = mlx_texture_to_image(mlx->mlx, mlx->texture[4]);
	mlx->img[5] = mlx_texture_to_image(mlx->mlx, mlx->texture[5]);
	mlx->img[6] = mlx_texture_to_image(mlx->mlx, mlx->texture[6]);
	mlx->img[7] = mlx_texture_to_image(mlx->mlx, mlx->texture[7]);
	mlx->img[8] = mlx_texture_to_image(mlx->mlx, mlx->texture[8]);
	mlx->img[9] = mlx_texture_to_image(mlx->mlx, mlx->texture[9]);
	mlx->img[10] = mlx_texture_to_image(mlx->mlx, mlx->texture[10]);
	mlx->img[11] = mlx_texture_to_image(mlx->mlx, mlx->texture[11]);
	mlx->img[12] = mlx_texture_to_image(mlx->mlx, mlx->texture[12]);
	mlx->img[13] = mlx_texture_to_image(mlx->mlx, mlx->texture[13]);
	mlx->img[14] = mlx_texture_to_image(mlx->mlx, mlx->texture[14]);
	mlx->img[15] = mlx_texture_to_image(mlx->mlx, mlx->texture[15]);
}

void	load_img(t_mlx *mlx)
{
	mlx->texture[0] = mlx_load_png("./img/ST/st0.png");
	mlx->texture[1] = mlx_load_png("./img/ST/st1.png");
	mlx->texture[2] = mlx_load_png("./img/ST/st2.png");
	mlx->texture[3] = mlx_load_png("./img/ST/st3.png");
	mlx->texture[4] = mlx_load_png("./img/ST/st4.png");
	mlx->texture[5] = mlx_load_png("./img/ST/st5.png");
	mlx->texture[6] = mlx_load_png("./img/ST/st6.png");
	mlx->texture[7] = mlx_load_png("./img/ST/st7.png");
	mlx->texture[8] = mlx_load_png("./img/ST/st8.png");
	mlx->texture[9] = mlx_load_png("./img/floor.png");
	mlx->texture[10] = mlx_load_png("./img/red.png");
	mlx->texture[11] = mlx_load_png("./img/drag.png");
	mlx->texture[12] = mlx_load_png("./img/exit.png");
	mlx->texture[13] = mlx_load_png("./img/coin.png");
	mlx->texture[14] = mlx_load_png("./img/exit1.png");
	mlx->texture[15] = mlx_load_png("./img/ST/st0.png");
	check_textures(mlx);
	load_txtr_to_img(mlx);
}

static void	right_index(char c, t_mlx *mlx)
{
	if (c == '1')
		mlx->p = 9;
	else if (c == 'P')
	{
		mlx->p = 11; 
		mlx->x_plyr = mlx->i;
		mlx->y_plyr = mlx->j;
	}
	else if (c == 'E')
	{
		mlx->p = 12; 
		mlx->x_exit = mlx->i;
		mlx->y_exit = mlx->j;
	}
	else if (c == 'C')
	{
		mlx->p = 13;
		mlx->col++;
	}
	else if (c == 'S')
		mlx->p = 15;
}

void	load_img_to_windows(t_mlx *mlx)
{
	mlx->j = 0;
	mlx->col = 0;
	while (mlx->j < mlx->y)
	{
		mlx->i = 0;
		while (mlx->i < mlx->x)
		{
			mlx->p = 10;
			mlx_image_to_window(mlx->mlx, mlx->img[mlx->p],
				mlx->i * WIDTH, mlx->j * HEIGHT);
			right_index(mlx->map[mlx->j][mlx->i], mlx);
			mlx_image_to_window(mlx->mlx, mlx->img[mlx->p],
				mlx->i * WIDTH, mlx->j * HEIGHT);
			mlx->i++;
		}
		mlx->j++;
	}
}
