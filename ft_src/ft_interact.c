/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interact.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 05:51:05 by jcuzin            #+#    #+#             */
/*   Updated: 2023/05/12 03:57:09 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	ft_interact_u(t_map *map, t_mlx *mlx, t_img *sp)
{
	char	*temp;

	if (map->id[map->y - 1][map->x] != '1')
	{
		mlx_put_image_to_window(mlx->init, mlx->win, sp->wall, 0, 0);
		mlx_put_image_to_window(mlx->init, mlx->win, sp->wall, 100, 0);
		ft_printf("\033[K\rMove = %d", ++map->move);
		temp = ft_itoa(map->move);
		mlx_string_put(mlx->init, mlx->win, 50, 50, 0x00FFFFFF, temp);
		free(temp);
	}
	if (map->id[map->y - 1][map->x] == 'C')
		map->entities--;
	if (map->gate > 0 && map->id[map->y - 1][map->x] == 'G' \
	&& map->gate >= 1)
	{
		ft_printf("\033[K\rGame finished in %d moves !\n\n", map->move);
		ft_close_game(map, mlx, sp);
	}
}

void	ft_interact_d(t_map *map, t_mlx *mlx, t_img *sp)
{
	char	*temp;

	if (map->id[map->y + 1][map->x] != '1')
	{
		mlx_put_image_to_window(mlx->init, mlx->win, sp->wall, 0, 0);
		mlx_put_image_to_window(mlx->init, mlx->win, sp->wall, 100, 0);
		ft_printf("\033[K\rMove = %d", ++map->move);
		temp = ft_itoa(map->move);
		mlx_string_put(mlx->init, mlx->win, 50, 50, 0x00FFFFFF, temp);
		free(temp);
	}
	if (map->id[map->y + 1][map->x] == 'C')
		map->entities--;
	if (map->gate > 0 && map->id[map->y + 1][map->x] == 'G' \
	&& map->gate >= 1)
	{
		ft_printf("\033[K\rGame finished in %d moves !\n\n", map->move);
		ft_close_game(map, mlx, sp);
	}
}

void	ft_interact_r(t_map *map, t_mlx *mlx, t_img *sp)
{
	char	*temp;

	if (map->id[map->y][map->x + 1] != '1')
	{
		mlx_put_image_to_window(mlx->init, mlx->win, sp->wall, 0, 0);
		mlx_put_image_to_window(mlx->init, mlx->win, sp->wall, 100, 0);
		ft_printf("\033[K\rMove = %d", ++map->move);
		temp = ft_itoa(map->move);
		mlx_string_put(mlx->init, mlx->win, 50, 50, 0x00FFFFFF, temp);
		free(temp);
	}
	if (map->id[map->y][map->x + 1] == 'C')
		map->entities--;
	if (map->gate > 0 && map->id[map->y][map->x + 1] == 'G' \
	&& map->gate >= 1)
	{
		ft_printf("\033[K\rGame finished in %d moves !\n\n", map->move);
		ft_close_game(map, mlx, sp);
	}
}

void	ft_interact_l(t_map *map, t_mlx *mlx, t_img *sp)
{
	char	*temp;

	if (map->id[map->y][map->x - 1] != '1')
	{
		mlx_put_image_to_window(mlx->init, mlx->win, sp->wall, 0, 0);
		mlx_put_image_to_window(mlx->init, mlx->win, sp->wall, 100, 0);
		ft_printf("\033[K\rMove = %d", ++map->move);
		temp = ft_itoa(map->move);
		mlx_string_put(mlx->init, mlx->win, 50, 50, 0x00FFFFFF, temp);
		free(temp);
	}
	if (map->id[map->y][map->x - 1] == 'C')
		map->entities--;
	if (map->gate > 0 && map->id[map->y][map->x - 1] == 'G' \
	&& map->gate >= 1)
	{
		ft_printf("\033[K\rGame finished in %d moves !\n\n", map->move);
		ft_close_game(map, mlx, sp);
	}
}
