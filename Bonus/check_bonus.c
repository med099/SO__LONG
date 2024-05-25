/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouali <moouali@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:14:06 by moouali           #+#    #+#             */
/*   Updated: 2024/05/25 17:12:14 by moouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_ext(char *name, char *ext)
{
	int		i;
	int		j;

	i = 3;
	j = ft_strlen(name) - 1;
	if (j < 3)
		exit(1);
	while (i >= 0)
	{
		if (ext[i] != name[j])
			ft_exit_fmap(NULL, "bad extention\n", 1);
		i--;
		j--;
	}
}

char	**load_map_to_check(char *f_name)
{
	t_map	var;

	var.fd = open(f_name, O_RDONLY);
	if (var.fd < 0)
		ft_exit_fmap(NULL, "i can't read from this file\n", 1);
	var.i = 0;
	var.line = get_next_line(var.fd);
	while (var.line)
	{
		var.i++;
		free(var.line);
		var.line = get_next_line(var.fd);
	}
	if (var.i < 3)
		ft_exit_fmap(NULL, "add more lines\n", 1);
	var.map = malloc ((var.i + 1) * sizeof(char *));
	if (!var.map)
		ft_exit_fmap(NULL, "error allocation map\n", 1);
	var.j = 0;
	close(var.fd);
	var.fd = open(f_name, O_RDONLY);
	while (var.j <= var.i)
		var.map[var.j++] = get_next_line(var.fd);
	close(var.fd);
	return (var.map);
}

int	check_map(int ac, char **av)
{
	char	**map;
	int		n_line;

	if (ac != 2)
		ft_exit_fmap(NULL, "wrong arguts\n", 1);
	check_ext(av[1], ".ber");
	map = load_map_to_check(av[1]);
	check_len_col(map);
	n_line = check_perimeter(map);
	check_elements(map);
	check_valid_path(map);
	ft_free_map(map);
	return (n_line);
}
