/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouali <moouali@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 22:31:07 by moouali           #+#    #+#             */
/*   Updated: 2024/05/10 23:20:00 by moouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len;
	int		i;
	int		j;
	char	*concat_str;

	if (!s1)
		return (ft_substr(s2, 0, ft_strlen(s2)));
	len = ft_strlen(s1) + ft_strlen(s2);
	concat_str = (char *)malloc(len + 1);
	if (!concat_str)
		return (free(s1), s1 = NULL, NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		concat_str[i] = s1[i];
		i++;
	}
	while (s2[j])
		concat_str[i++] = s2[j++];
	concat_str[i] = 0;
	free(s1);
	s1 = NULL;
	return (concat_str);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char			*sub_s;
	unsigned int	i;

	if (!s)
		return (NULL);
	sub_s = (char *)malloc(len + 1);
	if (!sub_s)
		return (NULL);
	i = 0;
	while (s[start] && i < len)
		sub_s[i++] = s[start++];
	sub_s[i] = 0;
	return (sub_s);
}
