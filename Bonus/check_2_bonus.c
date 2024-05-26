/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouali <moouali@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:10:26 by moouali           #+#    #+#             */
/*   Updated: 2024/05/26 00:44:28 by moouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	intial_var(t_map *elem)
{
	elem->i = 0;
	elem->c = 0;
	elem->p = 1;
	elem->e = 1;
	elem->d = 1;
}

void	check_elements(char **map)
{
	t_map	elem;

	intial_var(&elem);
	while (map[elem.i])
	{
		elem.j = -1;
		while (map[elem.i][++elem.j])
		{
			if (map[elem.i][elem.j] == 'E')
				elem.e--;
			else if (map[elem.i][elem.j] == 'P')
				(elem.p)--;
			else if (map[elem.i][elem.j] == 'C')
				elem.c++;
			else if (map[elem.i][elem.j] == 'D')
				elem.d--;
			else if (map[elem.i][elem.j] != '0' && map[elem.i][elem.j] != '1'
					&& map[elem.i][elem.j] != 'S')
				break ;
		}
		if (map[elem.i][elem.j] == '\n' || map[elem.i][elem.j] == '\0')
			elem.i++;
		else
			break ;
	}
	if (map[elem.i] || elem.p || elem.e || elem.c == 0 || elem.d)
		ft_exit_fmap(map, "error passing map element\n", 1);
}

void	check_len_col(char **map)
{
	int	i;
	int	len;
	int	dif;

	i = 0;
	dif = 1;
	len = ft_strlen(map[0]);
	while (map[i])
	{
		if (len != (int)ft_strlen(map[i]))
			dif--;
		i++;
	}
	if (dif == 0 && len == (int)ft_strlen(map[i - 1]) + 1)
		return ;
	else
		ft_exit_fmap(map, "defferent len \n", 1);
}

int	check_perimeter(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i][j] == '1')
		j++;
	if (map[i][j] != '\n')
		ft_exit_fmap(map, "check Top wall \n", 1);
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][j - 1] != '1')
			ft_exit_fmap(map, "check left or right wall\n", 1);
		i++;
	}
	j = 0;
	while (map[i - 1][j] == '1')
		j++;
	if (map[i - 1][j])
		ft_exit_fmap(map, "check bottom wall\n", 1);
	return (i);
}
