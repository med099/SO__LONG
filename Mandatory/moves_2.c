/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouali <moouali@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 21:32:36 by moouali           #+#    #+#             */
/*   Updated: 2024/05/24 16:25:50 by moouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_moves(void)
{
	static int	i;

	ft_printf("move : %d\n", ++i);
}

void	load_the_right_img(t_mlx *mlx, char c, int x, int y)
{
	int	bl;

	bl = 0;
	if (c == '0')
		bl = 1;
	else if (c == 'P')
		bl = 2;
	else if (c == 'E')
		bl = 3;
	else if (c == 'C')
		bl = 4;
	else if (c == 'Q')
		bl = 5;
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
	print_moves();
}
