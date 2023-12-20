/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pre_parse_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:28:41 by jcuzin            #+#    #+#             */
/*   Updated: 2023/05/10 01:14:57 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	ft_check_lines(int fd, int end_line, int line_len, int line_index)
{
	char	*line;
	int		less;

	if (fd == -1)
		return (0);
	less = 0;
	line = get_next_line(fd);
	line_len = ft_strlen(line);
	line_index++;
	while (line_index < end_line)
	{
		free(line);
		line = get_next_line(fd);
		if ((int)ft_strlen(line) != line_len && line_index != end_line)
			return (close(fd), free(line), 0);
		line_index++;
	}
	free(line);
	line = get_next_line(fd);
	if (line[ft_strlen(line) - 1] == '\n')
		less = 1;
	if ((int)ft_strlen(line) + (1 - less) != line_len)
		return (close(fd), free(line), 0);
	return (close(fd), free(line), 1);
}

int	ft_check_entity(int fd, int end_line, int line_count, int i)
{
	char	*line;

	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	while (line_count < end_line)
	{
		if (line[i] == 0 || (line[i] == '\n' && line_count == end_line))
			return (free(line), close(fd), 1);
		if (line[i] == '\n')
		{
			line_count++;
			i = 0;
			free(line);
			line = get_next_line(fd);
		}
		if (line[i] != '1' && line[i] != '0' && line[i] != 'P' \
		&& line[i] != 'C' && line[i] != 'E')
			return (free(line), 0);
		i++;
	}
	return (free(line), close(fd), 1);
}

int	ft_check_borders(t_map map, int end_l)
{
	map.x = 0;
	map.y = 0;
	map.x_max = ft_strlen(map.id[map.y]) - 2;
	map.y_max = end_l;
	if (map.id[map.y][map.x] == '\n')
		return (ft_free_map(&map), 0);
	while (map.y <= map.y_max)
	{
		if (map.id[map.y][0] != '1' || map.id[map.y][map.x_max] != '1')
			return (ft_free_map(&map), 0);
		map.y++;
	}
	map.y = 0;
	while (map.x < map.x_max)
	{
		if (map.id[0][map.x] != '1' || map.id[map.y_max][map.x] != '1')
			return (ft_free_map(&map), 0);
		map.x++;
	}
	ft_free_map(&map);
	return (1);
}

int	ft_check_rep(int fd, int i)
{
	int		obj[2];
	char	*line;

	obj[0] = 0;
	obj[1] = 0;
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		if (line[i] == '\n' || line[i] == 0)
		{
			i = 0;
			free(line);
			line = get_next_line(fd);
		}
		if (line && line[i] == 'P')
			obj[0]++;
		if (line && line[i] == 'E')
			obj[1]++;
		if ((obj[0] > 1 || obj[1] > 1 || (obj[0] < 1 || obj[1] < 1)) && !line)
			return (close(fd), free(line), 0);
		i++;
	}
	return (close(fd), free(line), 1);
}
