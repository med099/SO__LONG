/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_windows.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouali <moouali@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:50:30 by moouali           #+#    #+#             */
/*   Updated: 2024/05/25 23:27:55 by moouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_textures(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (!mlx->texture[i])
			break ;
		i++;
	}
	if (i == 6)
		return ;
	i = 0;
	while (i < 6)
	{
		if (mlx->texture[i])
			mlx_delete_texture(mlx->texture[i]);
		i++;
	}
	ft_exit(NULL, "Error load PNG\n", 1);
}

void	load_img(t_mlx *mlx)
{
	mlx->texture[0] = mlx_load_png("./img/floor.png");
	mlx->texture[1] = mlx_load_png("./img/red.png");
	mlx->texture[2] = mlx_load_png("./img/plr.png");
	mlx->texture[3] = mlx_load_png("./img/exit.png");
	mlx->texture[4] = mlx_load_png("./img/coin.png");
	mlx->texture[5] = mlx_load_png("./img/exit1.png");
	check_textures(mlx);
	mlx->img[0] = mlx_texture_to_image(mlx->mlx, mlx->texture[0]);
	mlx->img[1] = mlx_texture_to_image(mlx->mlx, mlx->texture[1]);
	mlx->img[2] = mlx_texture_to_image(mlx->mlx, mlx->texture[2]);
	mlx->img[3] = mlx_texture_to_image(mlx->mlx, mlx->texture[3]);
	mlx->img[4] = mlx_texture_to_image(mlx->mlx, mlx->texture[4]);
	mlx->img[5] = mlx_texture_to_image(mlx->mlx, mlx->texture[5]);
}

static void	right_index(char c, t_mlx *mlx)
{
	if (c == '1')
		mlx->p = 0;
	else if (c == 'P')
	{
		mlx->p = 2; 
		mlx->x_plyr = mlx->i;
		mlx->y_plyr = mlx->j;
	}
	else if (c == 'E')
	{
		mlx->p = 3; 
		mlx->x_exit = mlx->i;
		mlx->y_exit = mlx->j;
	}
	else if (c == 'C')
	{
		mlx->p = 4;
		mlx->col++;
	}
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
			mlx->p = 1;
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
