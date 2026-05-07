/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   get_next_line.c                                   :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tireis <tireis@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/04 15:03:21 by tireis           #+#    #+#              */
/*   Updated: 2026/05/07 13:40:40 by tireis          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_and_stash(int fd, char *stash)
{
	char	*temp;
	char	buffer[BUFFER_SIZE + 1];
	int		bytes_read;

	while (!ft_strchr(stash, '\n') && (bytes_read = read(fd, buffer,
				BUFFER_SIZE) > 0))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(stash);
			return (NULL);
		}
		else if (bytes_read > 0)
		{
			buffer[bytes_read] = '\0';
			temp = ft_strjoin(stash, buffer);
			free(stash);
			stash = temp;
		}
	}
	return (stash);
}

char	*extract_line(char *stash)
{
	size_t	i;

	i = 0;
}

char	*clean_stash(char *stash)
{
	size_t	i;

	i = 0;
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_and_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	stash = clean_stash(stash);
	return (line);
}
