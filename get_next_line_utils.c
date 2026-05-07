/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   get_next_line_utils.c                             :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tireis <tireis@student.42vienna.com>      #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/04 15:04:04 by tireis           #+#    #+#              */
/*   Updated: 2026/05/07 15:14:12 by tireis          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*ptr;
	const unsigned char	*ptr2;

	i = 0;
	ptr = (unsigned char *)dst;
	ptr2 = (const unsigned char *)src;
	while (i < n)
	{
		ptr[i] = ptr2[i];
		i++;
	}
	return (dst);
}
static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	while (*str)
	{
		if (*str == (unsigned char)c)
			return ((char *)str);
		str++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)str);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ptr = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, s1, s1_len);
	ft_memcpy(ptr + s1_len, s2, s2_len);
	ptr[s1_len + s2_len] = '\0';
	return (ptr);
}
char	*ft_strdup(const char *s1)
{
	char	*p1;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s1);
	p1 = malloc(sizeof(char) * (len + 1));
	if (!p1)
		return (NULL);
	while (i < len)
	{
		p1[i] = s1[i];
		i++;
	}
	p1[i] = '\0';
	return (p1);
}
