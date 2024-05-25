/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouali <moouali@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:08:59 by moouali           #+#    #+#             */
/*   Updated: 2024/05/25 23:21:38 by moouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_map(t_mlx	*mlx)
{
	int		j;

	mlx->map = malloc(mlx->n_line * sizeof(char *)); 
	close(mlx->fd);
	mlx->fd = open(mlx->fname, O_RDONLY);
	j = 0;
	while (mlx->n_line > j)
	{
		mlx->map[j] = get_next_line(mlx->fd);
		j++;
	}
	close(mlx->fd);
	mlx->x = ft_strlen(mlx->map[0]) - 1;
	mlx->y = j;
}

static void	animation(t_mlx *mlx, int i)
{
	while (mlx->j < mlx->y)
	{
		mlx->i = 0;
		while (mlx->i < mlx->x)
		{
			if (mlx->map[mlx->j][mlx->i] == 'S')
				mlx_image_to_window(mlx->mlx, mlx->img[i],
					mlx->i * WIDTH, mlx->j * HEIGHT);
			mlx->i++;
		}
		mlx->j++;
	}
	if (i)
	{
		mlx_delete_image(mlx->mlx, mlx->img[i - 1]);
		mlx->img[i - 1] = mlx_texture_to_image(mlx->mlx, mlx->texture[i - 1]);
	}
	else 
	{
		mlx_delete_image(mlx->mlx, mlx->img[8]);
		mlx->img[8] = mlx_texture_to_image(mlx->mlx, mlx->texture[8]);
	}
}

void	load_img_to_win(void *par)
{
	t_mlx		*mlx;
	static int	i;
	static int	j;

	mlx = (t_mlx *)par;
	while (j++ < 6)
		return ;
	mlx->j = 0;
	i++;
	animation(mlx, i);
	if (i == 8)
		i = -1;
	if (j == 7)
		j = 0;
}

void	_init_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init(mlx->x * WIDTH, mlx->y * HEIGHT, "so_long", 0);
	load_img(mlx);
	load_img_to_windows(mlx);
	mlx_key_hook(mlx->mlx, &my_keyhook, mlx);
	mlx_loop_hook(mlx->mlx, &load_img_to_win, mlx);
	mlx_loop(mlx->mlx);
}

int	main(int ac, char **av)
{
	t_mlx	mlx;

	mlx.n_line = check_map(ac, av);
	mlx.fname = av[1];
	load_map(&mlx);
	_init_mlx(&mlx);
}
