/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relhadi <relhadi@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 09:28:53 by relhadi           #+#    #+#             */
/*   Updated: 2025/11/19 12:32:15 by relhadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char	*str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *str)
{
	int		i;
	char	*dup;

	dup = malloc(sizeof(char) * (ft_strlen((char *)str) + 1));
	i = 0;
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin_free(char *dest, char *src)
{
	int		i;
	int		j;
	char	*dest_src;

	if (!dest)
	{
		dest_src = ft_strdup(src);
		return (dest_src);
	}
	dest_src = malloc(sizeof(char) * (ft_strlen(dest) + ft_strlen(src) + 1));
	i = 0;
	while (dest[i])
	{
		dest_src[i] = dest[i];
		i++;
	}
	j = 0;
	while (src[j])
	{
		dest_src[i + j] = src[j];
		j++;
	}
	dest_src[i + j] = '\0';
	free(dest);
	return (dest_src);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	j;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		sub = malloc(1);
		if (!sub)
			return (NULL);
		sub[0] = '\0';
		return (sub);
	}
	if (len > s_len - start)
		len = s_len - start;
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	i = start;
	j = 0;
	while (j < len && s[i])
		sub[j++] = s[i++];
	sub[j] = '\0';
	return (sub);
}

int	ft_find_n(char	*str)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
