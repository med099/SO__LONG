/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouali <moouali@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:06:34 by moouali           #+#    #+#             */
/*   Updated: 2024/05/24 17:51:20 by moouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	flood_fill(char **map, int i, int j)
{
	if (i <= 0 || j <= 0 || map[i][j] == '1')
		return ;
	else if (map[i][j] == 'p')
		return ;
	else
		map[i][j] = 'p';
	flood_fill(map, i, j + 1);
	flood_fill(map, i + 1, j);
	flood_fill(map, i - 1, j);
	flood_fill(map, i, j - 1);
}

static void	get_a_position(char **map, int *i, int *j)
{
	*i = 1;
	while (map[*i])
	{
		*j = 1;
		while (map[*i][*j] != '\n' && map[*i][*j])
		{
			if (map[*i][*j] == 'C' || map[*i][*j] == 'P'
				|| map[*i][*j] == 'E')
				return ;
			(*j)++;
		}
		(*i)++;
	}
	*i = 0;
	*j = 0;
}

void	check_valid_path(char **map)
{
	int	i;
	int	j;

	get_a_position(map, &i, &j);
	flood_fill(map, i, j);
	get_a_position(map, &i, &j);
	if (j || i)
		ft_exit_fmap(map, "Invalide path\n", 1);
	ft_printf("evrething good\n");
}
