/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:57:50 by jcuzin            #+#    #+#             */
/*   Updated: 2023/05/12 09:11:42 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	ft_count_coin(t_map map)
{
	map.x = 0;
	map.y = 0;
	map.entities = 0;
	while (map.y != map.y_max)
	{
		if (map.id[map.y][map.x] == 'C')
			map.entities++;
		map.x++;
		if (map.x == map.x_max)
		{
			map.y++;
			map.x = 0;
		}
	}
	return (map.entities);
}

int	ft_count_l(char *path)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	line = "empty";
	while (line)
	{
		line = get_next_line(fd);
		if (!line || !line[0])
			return (close(fd), free(line), i);
		if (!line || line[0] == '\n')
			return (close(fd), free(line), -1);
		free(line);
		i++;
	}
	free(line);
	line = NULL;
	close(fd);
	return (i - 1);
}

void	ft_free_map(t_map *map)
{
	if (!map->id)
		return ;
	while (map->y_max >= 0)
	{
		if (map->id[map->y_max])
			free(map->id[map->y_max]);
		map->y_max--;
	}
	free(map->id);
}

int	ft_close_game(t_map *map, t_mlx *mlx, t_img *sprites)
{
	ft_printf("Closing game...\n\n");
	ft_free_map(map);
	if (sprites->player)
		mlx_destroy_image(mlx->init, sprites->player);
	if (sprites->floor)
		mlx_destroy_image(mlx->init, sprites->floor);
	if (sprites->wall)
		mlx_destroy_image(mlx->init, sprites->wall);
	if (sprites->coin)
		mlx_destroy_image(mlx->init, sprites->coin);
	if (sprites->gate_c)
		mlx_destroy_image(mlx->init, sprites->gate_c);
	if (sprites->gate_o)
		mlx_destroy_image(mlx->init, sprites->gate_o);
	if (sprites->vignette)
		mlx_destroy_image(mlx->init, sprites->vignette);
	mlx_destroy_window(mlx->init, mlx->win);
	mlx_destroy_display(mlx->init);
	free(mlx->init);
	exit(1);
}

int	ft_close_game_p(t_game *game)
{
	ft_free_map(&game->map);
	if (game->sprites.player)
		mlx_destroy_image(game->mlx.init, game->sprites.player);
	if (game->sprites.floor)
		mlx_destroy_image(game->mlx.init, game->sprites.floor);
	if (game->sprites.wall)
		mlx_destroy_image(game->mlx.init, game->sprites.wall);
	if (game->sprites.coin)
		mlx_destroy_image(game->mlx.init, game->sprites.coin);
	if (game->sprites.gate_c)
		mlx_destroy_image(game->mlx.init, game->sprites.gate_c);
	if (game->sprites.gate_o)
		mlx_destroy_image(game->mlx.init, game->sprites.gate_o);
	if (game->sprites.vignette)
		mlx_destroy_image(game->mlx.init, game->sprites.vignette);
	if (game->mlx.win)
		mlx_destroy_window(game->mlx.init, game->mlx.win);
	if (game->mlx.init)
		mlx_destroy_display(game->mlx.init);
	free(game->mlx.init);
	exit(1);
}
