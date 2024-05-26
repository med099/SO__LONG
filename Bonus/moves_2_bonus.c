/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouali <moouali@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 21:32:36 by moouali           #+#    #+#             */
/*   Updated: 2024/05/26 00:58:55 by moouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	print_moves(t_mlx *mlx)
{
	static int	i;
	char		nb[20];

	sprintf(nb, "move : %d\n", ++i);
	mlx_image_to_window(mlx->mlx, mlx->img[9], 0, 0);
	mlx_image_to_window(mlx->mlx, mlx->img[9], WIDTH, 0);
	mlx_put_string(mlx->mlx, nb, 0, 0);
}

void	load_the_right_img(t_mlx *mlx, char c, int x, int y)
{
	int	bl;

	bl = 9;
	if (c == '0')
		bl = 10;
	else if (c == 'P')
		bl = 11;
	else if (c == 'E')
		bl = 12;
	else if (c == 'C')
		bl = 13;
	else if (c == 'Q')
		bl = 14;
	mlx_image_to_window(mlx->mlx, mlx->img[bl], x * WIDTH, y * HEIGHT);
}

void	player_above_exit(t_mlx *mlx, int x, int y)
{
	if (mlx->map[mlx->y_plyr][mlx->x_plyr] == 'e')
	{
		if (mlx->map[mlx->y_plyr + y][mlx->x_plyr + x] == 'C')
		{
			load_the_right_img(mlx, '0', mlx->x_plyr + x, mlx->y_plyr + y);
			mlx->col--;
		}
		mlx->map[mlx->y_plyr + y][mlx->x_plyr + x] = 'P';
		load_the_right_img(mlx, '0', mlx->x_plyr, mlx->y_plyr);
		load_the_right_img(mlx, 'E', mlx->x_plyr, mlx->y_plyr);
		load_the_right_img(mlx, 'P', mlx->x_plyr + x, mlx->y_plyr + y);
	}
	else
	{
		mlx->map[mlx->y_plyr][mlx->x_plyr] = '0';
		load_the_right_img(mlx, '0', mlx->x_plyr, mlx->y_plyr);
		load_the_right_img(mlx, 'E', mlx->x_plyr + x, mlx->y_plyr + y);
		load_the_right_img(mlx, 'P', mlx->x_plyr + x, mlx->y_plyr + y);
		mlx->map[mlx->y_plyr + y][mlx->x_plyr + x] = 'e';
	}
	mlx->x_plyr += x;
	mlx->y_plyr += y;
	print_moves(mlx);
}
