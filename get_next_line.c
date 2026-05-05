/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   get_next_line.c                                   :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tireis <tireis@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/04 15:03:21 by tireis           #+#    #+#              */
/*   Updated: 2026/05/04 17:50:42 by tireis          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_and_stash(int fd, static char *stash)
{
	char	*temp;

	temp = ft_strjoin(stash, buffer);
	free(stash);
}

char	*extract_line(static char *stash)
{
	size_t	i;

	i = 0;
}

char	*clean_stash(static char *stash)
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
