/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouali <moouali@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:08:59 by moouali           #+#    #+#             */
/*   Updated: 2024/05/24 14:44:54 by moouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	_init_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init(mlx->x * WIDTH, mlx->y * HEIGHT, "so_long", 0);
	load_img(mlx);
	load_img_to_windows(mlx);
	mlx_key_hook(mlx->mlx, &my_keyhook, mlx);
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
