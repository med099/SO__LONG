/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouali <moouali@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:46:19 by moouali           #+#    #+#             */
/*   Updated: 2024/05/26 10:41:38 by moouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "../MLX42/include/MLX42/MLX42.h"
# include "../utils/gnl/get_next_line.h"
# include "../utils/printf/ft_printf.h"
# define WIDTH 64
# define HEIGHT 64

typedef struct s_mlx
{
	mlx_t			*mlx;
	mlx_image_t		*img[17];
	mlx_texture_t	*texture[17];
	mlx_image_t		palyer;
	char			**map;
	char			*fname;
	int				n_line;
	int				x;
	int				y;
	int				x_plyr;
	int				y_plyr;
	int				x_drag;
	int				y_drag;
	int				x_exit;
	int				y_exit;
	int				fd;
	int				col;
	int				i;
	int				j;
	int				p;
}	t_mlx;

typedef struct s_map
{
	char	**map;
	char	*line;
	int		fd;
	int		p;
	int		e;
	int		c;
	int		d;
	int		i;
	int		j;
}	t_map;

void	my_keyhook(mlx_key_data_t keydata, void *param);
void	ft_exit(t_mlx *mlx, char *msg, int ret);
int		check_map(int ac, char **av);
void	ft_exit_fmap(char **map, char *msg, int ret);
void	ft_free_map(char **map);
void	check_valid_path(char **map);
void	check_elements(char **map);
void	check_len_col(char **map);
int		check_perimeter(char **map);
void	load_img(t_mlx *mlx);
void	load_img_to_windows(t_mlx *mlx);
void	print_moves(t_mlx *mlx);
void	load_the_right_img(t_mlx *mlx, char c, int x, int y);
void	player_above_exit(t_mlx *mlx, int x, int y);
void	move_enemy(void *par);

#endif