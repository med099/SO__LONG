/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouali <moouali@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 22:31:03 by moouali           #+#    #+#             */
/*   Updated: 2024/05/10 23:17:35 by moouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_nline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return (1);
	return (0);
}

char	*ft_read(int fd, char *line)
{
	char	*buf;
	ssize_t	i;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (free(line), line = NULL, NULL);
	while (!check_nline(line))
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1)
			return (free(buf), buf = NULL, NULL);
		if (!i)
		{
			free(buf);
			buf = NULL;
			break ;
		}
		buf[i] = 0;
		line = ft_strjoin(line, buf);
		if (!line)
			return (free(buf), buf = NULL, NULL);
	}
	free(buf);
	buf = NULL;
	return (line);
}

char	*one_line(char *str, int *isfreed)
{
	char	*line;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	line = ft_substr(str, 0, i);
	if (!line)
	{
		free(str);
		str = NULL;
		*isfreed = 0;
		return (NULL);
	}
	if (!str[i])
	{
		*isfreed = 0;
		free(str);
		str = NULL;
	}
	return (line);
}

char	*ft_clean(char *str)
{
	char	*line;
	size_t	i;
	size_t	len;

	i = 0;
	if (!str || !(*str))
		return (NULL);
	len = ft_strlen(str);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	if (len == i)
		return (NULL);
	line = ft_substr(str, i, len - i);
	free(str);
	str = NULL;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*static_str;
	char		*str;
	int			isfreed;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) == -1)
	{
		free(static_str);
		static_str = NULL;
		return (NULL);
	}
	static_str = ft_read(fd, static_str);
	if (!static_str)
		return (NULL);
	isfreed = 1;
	str = one_line(static_str, &isfreed);
	if (isfreed)
		static_str = ft_clean(static_str);
	else
		static_str = NULL;
	return (str);
}
