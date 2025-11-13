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

char	*ft_rev_strchr(const char *s, int c)

{
	int	i;
	
	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		i++;
	}
	while (i > 0 && s[i] != (unsigned char)c)
		i--;
	if (s[i] == (unsigned char)c)
		return ((char *)s + i);
	return (NULL);
}

char	*ft_strchr(const char *string, int searchedChar)
{
	char	c;
	char	*s;
	int		i;
	
	if (!string)
		return (NULL);
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
