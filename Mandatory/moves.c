/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouali <moouali@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 22:49:54 by moouali           #+#    #+#             */
/*   Updated: 2024/05/25 22:05:31 by moouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_to_right(t_mlx *mlx)
{
	if ((mlx->map[mlx->y_plyr][mlx->x_plyr + 1] == 'E'
		|| mlx->map[mlx->y_plyr][mlx->x_plyr + 1] == 'e') && mlx->col)
		player_above_exit(mlx, 1, 0);
	else if (mlx->map[mlx->y_plyr][mlx->x_plyr] == 'e' && mlx->col
			&& (mlx->map[mlx->y_plyr][mlx->x_plyr + 1] == '0'
		|| mlx->map[mlx->y_plyr][mlx->x_plyr + 1] == 'C'))
		player_above_exit(mlx, 1, 0);
	else if (mlx->map[mlx->y_plyr][mlx->x_plyr + 1] == '0'
		|| mlx->map[mlx->y_plyr][mlx->x_plyr + 1] == 'C')
	{
		if (mlx->map[mlx->y_plyr][mlx->x_plyr + 1] == 'C')
			mlx->col--;
		mlx->map[mlx->y_plyr][mlx->x_plyr] = '0';
		mlx->map[mlx->y_plyr][mlx->x_plyr + 1] = 'P';
		load_the_right_img(mlx, '0', mlx->x_plyr, mlx->y_plyr);
		load_the_right_img(mlx, '0', mlx->x_plyr + 1, mlx->y_plyr);
		load_the_right_img(mlx, 'P', mlx->x_plyr + 1, mlx->y_plyr);
		mlx->x_plyr++;
		print_moves();
	}
	else if ((mlx->map[mlx->y_plyr][mlx->x_plyr + 1] == 'e'
		|| mlx->map[mlx->y_plyr][mlx->x_plyr + 1] == 'E') && !mlx->col)
		ft_exit(mlx, "You WIN", 0);
}

void	move_to_left(t_mlx *mlx)
{
	if ((mlx->map[mlx->y_plyr][mlx->x_plyr - 1] == 'E'
		|| mlx->map[mlx->y_plyr][mlx->x_plyr - 1] == 'e') && mlx->col)
		player_above_exit(mlx, -1, 0);
	else if (mlx->map[mlx->y_plyr][mlx->x_plyr] == 'e' && mlx->col
			&& (mlx->map[mlx->y_plyr][mlx->x_plyr - 1] == '0'
		|| mlx->map[mlx->y_plyr][mlx->x_plyr - 1] == 'C'))
		player_above_exit(mlx, -1, 0);
	else if (mlx->map[mlx->y_plyr][mlx->x_plyr - 1] == '0'
		|| mlx->map[mlx->y_plyr][mlx->x_plyr - 1] == 'C')
	{
		if (mlx->map[mlx->y_plyr][mlx->x_plyr - 1] == 'C')
			mlx->col--;
		mlx->map[mlx->y_plyr][mlx->x_plyr] = '0';
		mlx->map[mlx->y_plyr][mlx->x_plyr - 1] = 'P';
		load_the_right_img(mlx, '0', mlx->x_plyr, mlx->y_plyr);
		load_the_right_img(mlx, '0', mlx->x_plyr - 1, mlx->y_plyr);
		load_the_right_img(mlx, 'P', mlx->x_plyr - 1, mlx->y_plyr);
		mlx->x_plyr--;
		print_moves();
	}
	else if ((mlx->map[mlx->y_plyr][mlx->x_plyr - 1] == 'e'
		|| mlx->map[mlx->y_plyr][mlx->x_plyr - 1] == 'E') && !mlx->col)
		ft_exit(mlx, "You WIN", 0);
}

void	move_up(t_mlx *mlx)
{
	if ((mlx->map[mlx->y_plyr - 1][mlx->x_plyr] == 'E'
		|| mlx->map[mlx->y_plyr - 1][mlx->x_plyr] == 'e') && mlx->col)
		player_above_exit(mlx, 0, -1);
	else if (mlx->map[mlx->y_plyr][mlx->x_plyr] == 'e' && mlx->col
			&& (mlx->map[mlx->y_plyr - 1][mlx->x_plyr] == '0'
		|| mlx->map[mlx->y_plyr - 1][mlx->x_plyr] == 'C'))
		player_above_exit(mlx, 0, -1);
	else if (mlx->map[mlx->y_plyr - 1][mlx->x_plyr] == '0'
		|| mlx->map[mlx->y_plyr - 1][mlx->x_plyr] == 'C')
	{
		if (mlx->map[mlx->y_plyr - 1][mlx->x_plyr] == 'C')
			mlx->col--;
		mlx->map[mlx->y_plyr][mlx->x_plyr] = '0';
		mlx->map[mlx->y_plyr - 1][mlx->x_plyr] = 'P';
		load_the_right_img(mlx, '0', mlx->x_plyr, mlx->y_plyr);
		load_the_right_img(mlx, '0', mlx->x_plyr, mlx->y_plyr - 1);
		load_the_right_img(mlx, 'P', mlx->x_plyr, mlx->y_plyr - 1);
		mlx->y_plyr--;
		print_moves();
	}
	else if ((mlx->map[mlx->y_plyr - 1][mlx->x_plyr] == 'e'
		|| mlx->map[mlx->y_plyr - 1][mlx->x_plyr] == 'E') && !mlx->col)
		ft_exit(mlx, "You WIN", 0);
}

void	move_down(t_mlx *mlx)
{
	if ((mlx->map[mlx->y_plyr + 1][mlx->x_plyr] == 'E'
		|| mlx->map[mlx->y_plyr + 1][mlx->x_plyr] == 'e') && mlx->col)
		player_above_exit(mlx, 0, 1);
	else if (mlx->map[mlx->y_plyr][mlx->x_plyr] == 'e' && mlx->col
			&& (mlx->map[mlx->y_plyr + 1][mlx->x_plyr] == '0'
		|| mlx->map[mlx->y_plyr + 1][mlx->x_plyr] == 'C'))
		player_above_exit(mlx, 0, 1);
	else if (mlx->map[mlx->y_plyr + 1][mlx->x_plyr] == '0'
		|| mlx->map[mlx->y_plyr + 1][mlx->x_plyr] == 'C')
	{
		if (mlx->map[mlx->y_plyr + 1][mlx->x_plyr] == 'C')
			mlx->col--;
		mlx->map[mlx->y_plyr][mlx->x_plyr] = '0';
		mlx->map[mlx->y_plyr + 1][mlx->x_plyr] = 'P';
		load_the_right_img(mlx, '0', mlx->x_plyr, mlx->y_plyr);
		load_the_right_img(mlx, '0', mlx->x_plyr, mlx->y_plyr + 1);
		load_the_right_img(mlx, 'P', mlx->x_plyr, mlx->y_plyr + 1);
		mlx->y_plyr++;
		print_moves();
	}
	else if ((mlx->map[mlx->y_plyr + 1][mlx->x_plyr] == 'e'
		|| mlx->map[mlx->y_plyr + 1][mlx->x_plyr] == 'E') && !mlx->col)
		ft_exit(mlx, "You WIN", 0);
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	if (!mlx->col)
		load_the_right_img(mlx, 'Q', mlx->x_exit, mlx->y_exit);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action)
		ft_exit(mlx, "you exit the game\n", 0);
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action
		&& mlx->map[mlx->y_plyr][mlx->x_plyr + 1] != '1')
		move_to_right(param);
	else if (keydata.key == MLX_KEY_LEFT && keydata.action
		&& mlx->map[mlx->y_plyr][mlx->x_plyr - 1] != '1')
		move_to_left(param);
	else if (keydata.key == MLX_KEY_DOWN && keydata.action
		&& mlx->map[mlx->y_plyr + 1][mlx->x_plyr] != '1')
		move_down(param);
	else if (keydata.key == MLX_KEY_UP && keydata.action
		&& mlx->map[mlx->y_plyr - 1][mlx->x_plyr] != '1')
		move_up(param);
}
