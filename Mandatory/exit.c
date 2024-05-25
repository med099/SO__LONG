/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouali <moouali@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:58:48 by moouali           #+#    #+#             */
/*   Updated: 2024/05/25 22:03:10 by moouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	ft_exit_fmap(char **map, char *msg, int ret)
{
	if (ret == 1)
		ft_printf("Error : ");
	ft_free_map(map);
	ft_printf(msg);
	exit(ret);
}

void	ft_exit(t_mlx *mlx, char *msg, int ret)
{
	int	i;

	i = 0;
	while (i < 6 && mlx)
	{
		mlx_delete_texture(mlx->texture[i]);
		i++;
	}
	if (mlx)
		mlx_terminate(mlx->mlx);
	ft_printf(msg);
	exit(ret);
}
