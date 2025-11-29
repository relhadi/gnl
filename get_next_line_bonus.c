/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relhadi <relhadi@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:25:32 by relhadi           #+#    #+#             */
/*   Updated: 2025/11/19 15:29:29 by relhadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_cleanup(char *buff, char **line, char **storage)
{
	if (buff)
	{
		free(buff);
		buff = NULL;
	}
	if (line && *line)
	{
		free(*line);
		*line = NULL;
	}
	if (storage && *storage)
	{
		free(*storage);
		*storage = NULL;
	}
	return (NULL);
}

static char	*ft_handle_line(char **line, char **storage)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!*line || !**line)
	{
		if (*line)
			free(*line);
		*line = NULL;
		return (NULL);
	}
	while ((*line)[i] && (*line)[i] != '\n')
		i++;
	if ((*line)[i] == '\n')
	{
		tmp = ft_substr(*line, 0, i + 1);
		*storage = ft_substr(*line, i + 1, ft_strlen(*line) - i - 1);
		free(*line);
		*line = NULL;
		return (tmp);
	}
	*storage = NULL;
	return (*line);
}

static char	*ft_verify_storage(char	**buff, char **storage, char **line)
{
	char	*re_buff;

	re_buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!re_buff)
		return (NULL);
	if (!storage || !line)
	{
		free(re_buff);
		return (NULL);
	}
	if (*storage)
	{
		*line = ft_strdup(*storage);
		free(*storage);
		*storage = NULL;
	}
	else
		*line = NULL;
	*buff = re_buff;
	return (*buff);
}

char	*get_next_line(int fd)
{
	char		*buff;
	char		*line;
	static char	*storage[1024];
	ssize_t		read_bytes;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1023)
		return (NULL);
	line = NULL;
	if (!ft_verify_storage(&buff, &storage[fd], &line))
		return (NULL);
	while (1)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes <= 0)
			break ;
		buff[read_bytes] = '\0';
		line = ft_strjoin_free(line, buff);
		if (ft_find_n(line))
			break ;
	}
	if (read_bytes < 0 && !ft_cleanup(buff, &line, &storage[fd]))
		return (NULL);
	free(buff);
	return (ft_handle_line(&line, &storage[fd]));
}
