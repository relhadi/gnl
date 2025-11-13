/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relhadi <relhadi@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 16:21:27 by relhadi           #+#    #+#             */
/*   Updated: 2025/11/13 17:52:33 by relhadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

static char	*ft_strdup(const char *src)
{
	char	*dst;
	size_t	i;

	i = 0;
	dst = malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!dst)
		return (NULL);
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

static void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char				*p1;
	const unsigned char			*p2;
	size_t						i;

	if (!dest && !src)
		return (NULL);
	if (n == 0)
		return (dest);
	i = 0;
	p1 = (unsigned char *) dest;
	p2 = (unsigned char *) src;
	while (i < n)
	{
		p1[i] = p2[i];
		i++;
	}
	return (dest);
}

static char	*ft_strjoin(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*conc_strings;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return(ft_strdup(s2));
	if (!s2)
		return(s1);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	conc_strings = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!conc_strings)
		return (NULL);
	ft_memcpy(conc_strings, s1, s1_len);
	ft_memcpy(conc_strings + s1_len, s2, s2_len);
	conc_strings[s1_len + s2_len] = '\0';
	free(s1);
	return (conc_strings);
}

char	*get_next_line(int fd)
{
	char	*buff;
	char	*line;
	static char	*stash;

	buff = NULL;
	if (!stash)
		stash = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!stash)
		return (NULL);
	if (!buff)
		buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));	
	if (!buff)
		return (NULL);
	if (stash[0])
		line = ft_strdup(stash);
	if (stash[0])
		stash[0] = 0;
	while (read(fd, buff, BUFFER_SIZE) && !ft_strchr(buff, '\n'))
		line = ft_strjoin(line, buff);
	stash = ft_strdup(ft_strchr(buff, '\n'));
	line = ft_strjoin(line, ft_rev_strchr(buff, '\n'));
	return (line);
}

int main(void)
{
    int fd;
    char *line;

    fd = open("text.txt", O_RDONLY);  // fichier
    if (fd < 0)
    {
        perror("open");
        return 1;
    }

	int	i = 0;
	while (i < 1)
	{
		line = get_next_line(fd);
		if (!line)
			return(0);
		printf("%s\n", line);
		i++;
		free(line);
	}
    close(fd);              // ferme le fichier
    return 0;
}
