/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouali <moouali@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 09:42:54 by moouali           #+#    #+#             */
/*   Updated: 2024/05/26 10:42:27 by moouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_enemy_up(t_mlx *mlx)
{
	mlx_image_to_window(mlx->mlx, mlx->img[10],
		mlx->x_drag * WIDTH, mlx->y_drag * HEIGHT);
	mlx->map[mlx->y_drag][mlx->x_drag] = '0';
	mlx->y_drag--;
	mlx->map[mlx->y_drag][mlx->x_drag] = 'D';
	mlx_image_to_window(mlx->mlx, mlx->img[16],
		mlx->x_drag * WIDTH, mlx->y_drag * HEIGHT);
}

void	move_enemy_down(t_mlx *mlx)
{
	mlx_image_to_window(mlx->mlx, mlx->img[10],
		mlx->x_drag * WIDTH, mlx->y_drag * HEIGHT);
	mlx->map[mlx->y_drag][mlx->x_drag] = '0';
	mlx->y_drag++;
	mlx->map[mlx->y_drag][mlx->x_drag] = 'D';
	mlx_image_to_window(mlx->mlx, mlx->img[16],
		mlx->x_drag * WIDTH, mlx->y_drag * HEIGHT);
}

void	move_enemy(void *par)
{
	t_mlx		*mlx;
	static int	j;
	static int	i;

	mlx = (t_mlx *)par;
	while (j++ < 18)
		return ;
	if (j == 19)
		j = 0;
	if (mlx->map[mlx->y_drag + 1][mlx->x_drag] == '0' && i)
		move_enemy_down(mlx);
	else if (mlx->map[mlx->y_drag - 1][mlx->x_drag] == '0' && !i)
		move_enemy_up(mlx);
	else if (mlx->map[mlx->y_drag - 1][mlx->x_drag] == 'P' 
			|| mlx->map[mlx->y_drag + 1][mlx->x_drag] == 'P')
		ft_exit(mlx, "Game Over\n", 0);
	else if (i)
		i = 0;
	else
		i = 1;
}
