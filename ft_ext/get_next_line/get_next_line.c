/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 18:50:06 by jcuzin            #+#    #+#             */
/*   Updated: 2023/03/20 14:23:39 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

static char	*ft_pre_join(char *s1, char *s2, int boolean)
{
	char	*result;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
	{
		s1 = malloc(sizeof(char));
		if (!s1)
			return (NULL);
		s1[0] = 0;
	}
	if (!s2)
	{
		s2 = malloc(sizeof(char));
		if (!s2)
			return (NULL);
		s2[0] = 0;
	}
	result = ft_strjoin(s1, s2, boolean);
	return (result);
}

static char	*ft_add(int fd, char *s_buffer, int *rvalue)
{
	char	temp[BUFFER_SIZE + 1];

	temp[BUFFER_SIZE] = 0;
	if (!s_buffer)
	{
		s_buffer = malloc(sizeof(char));
		s_buffer[0] = 0;
	}
	if (*rvalue == BUFFER_SIZE)
	{
		*rvalue = read(fd, temp, BUFFER_SIZE);
		if (*rvalue < 1)
			return (ft_bzero(temp), s_buffer);
		temp[*rvalue] = 0;
	}
	s_buffer = ft_strjoin(s_buffer, temp, 1);
	ft_bzero(temp);
	return (s_buffer);
}

static char	*ft_sort(char *buffer, char *over, int *is_over)
{
	int	i_b;
	int	i_o;

	i_b = 0;
	while (buffer[i_b] && buffer[i_b] != '\n')
		i_b++;
	if (buffer[i_b] == '\n')
		i_b++;
	i_o = 0;
	while (buffer[i_b])
	{
		over[i_o] = buffer[i_b];
		i_o++;
		i_b++;
	}
	over[i_o] = 0;
	while (i_o + 1 > 0)
	{
		buffer[i_b] = 0;
		i_b--;
		i_o--;
	}
	*is_over = 1;
	return (buffer);
}

static char	*ft_over(char *buffer, char **over, int *is_over)
{
	int	i_b;

	i_b = 0;
	while (buffer[i_b] && buffer[i_b] != '\n')
		i_b++;
	if (buffer[i_b] == '\n')
		i_b++;
	if (*is_over == 1)
		free(*over);
	*over = malloc(sizeof(char) * ((ft_strlen(buffer) - i_b) + 1));
	if (!over)
		return (NULL);
	buffer = ft_sort(buffer, *over, is_over);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*over;
	char		*buffer;
	int			rvalue;
	static int	is_over;

	if (fd < 0 || read(fd, NULL, 0) < 0)
		return (over = NULL, NULL);
	buffer = NULL;
	buffer = ft_alloc(buffer, &rvalue, fd);
	if ((buffer == NULL && is_over == 0) || (!buffer && is_over == 0))
		return (over = NULL, NULL);
	if (is_over == 1)
	{
		buffer = ft_pre_join(over, buffer, 2);
		if (!buffer)
			return (over = NULL, NULL);
		is_over = 0;
	}
	while (ft_check_nl(buffer) == 0 && rvalue == BUFFER_SIZE)
		buffer = ft_add(fd, buffer, &rvalue);
	if (ft_check_nl(buffer) == 2)
		buffer = ft_over(buffer, &over, &is_over);
	return (buffer);
}
