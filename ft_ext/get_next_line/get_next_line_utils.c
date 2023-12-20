/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:56:40 by jcuzin            #+#    #+#             */
/*   Updated: 2023/02/27 15:05:00 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_check_nl(char *to_check)
{
	size_t	index;

	index = 0;
	while (to_check[index])
	{
		if (to_check[index] == '\n' && to_check[index + 1])
			return (2);
		if (to_check[index] == '\n')
			return (1);
		index++;
	}
	return (0);
}

void	ft_bzero(void *str0)
{
	int		cursor;
	char	*str;
	int		n;

	cursor = 0;
	str = str0;
	n = BUFFER_SIZE;
	while (n > 0)
	{
		str[cursor] = '\0';
		cursor++;
		n--;
	}
}

char	*ft_alloc(char *buffer, int *rvalue, int fd)
{
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	buffer[BUFFER_SIZE] = 0;
	*rvalue = read(fd, buffer, BUFFER_SIZE);
	buffer[*rvalue] = 0;
	if (*rvalue < 1)
	{
		ft_bzero(buffer);
		free(buffer);
		buffer = NULL;
	}
	return (buffer);
}

char	*ft_strjoin(char *s1, char *s2, int boolean)
{
	char	*s_joined;
	int		index;
	int		len_s1;
	int		len_s2;

	index = -1;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	s_joined = NULL;
	s_joined = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!s_joined)
		return (NULL);
	while (++index < len_s1)
		s_joined[index] = s1[index];
	index = -1;
	while (++index < len_s2)
		s_joined[index + len_s1] = s2[index];
	s_joined[index + len_s1] = '\0';
	if (boolean == 2)
		return (free(s1), free(s2), s_joined);
	if (boolean == 1)
		return (free(s1), s_joined);
	if (boolean == 0)
		return (free(s2), s_joined);
	return (s_joined);
}
