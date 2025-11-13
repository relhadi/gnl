/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relhadi <relhadi@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 17:23:19 by relhadi           #+#    #+#             */
/*   Updated: 2025/11/13 14:27:02 by relhadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_rev_strchr(char	*str, char c)
{
	int	i;

	i = 0;
	while (str[i] != c)
		i++;
	str[i + 1] = 0;
	return (str);
}

char	*ft_strchr(const char *string, int searchedChar)
{
	char	c;
	char	*s;
	int		i;

	c = (char) searchedChar;
	s = (char *)string;
	i = 0;
	while (1)
	{
		if (c == s[i])
			return (s + i);
		if (s[i] == '\0')
			return (NULL);
		i++;
	}
}

static void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;
	size_t			i;

	i = 0;
	p = (unsigned char *) s;
	while (i < n)
	{
		p[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	void	*p;

	if (elementCount == 0 || elementSize == 0)
	{
		p = malloc(0);
		if (!p)
			return (NULL);
		return (p);
	}
	if (elementCount > (size_t) - 1 / elementSize)
		return (NULL);
	p = malloc(elementSize * elementCount);
	if (!p)
		return (NULL);
	ft_bzero(p, (elementSize * elementCount));
	return (p);
}
