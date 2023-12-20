/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 23:42:49 by jcuzin            #+#    #+#             */
/*   Updated: 2023/05/12 09:05:43 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	ft_init_sprites(t_mlx *mlx, t_img *sprites)
{
	if (sprites->p_way == 'R')
		sprites->player = mlx_xpm_file_to_image(mlx->init, \
		"./assets/player/Goose_R.xpm", &sprites->width, &sprites->height);
	else
		sprites->player = mlx_xpm_file_to_image(mlx->init, \
		"./assets/player/Goose_L.xpm", &sprites->width, &sprites->height);
	sprites->wall = mlx_xpm_file_to_image(mlx->init, \
	"./assets/world_map/wall.xpm", &sprites->width, &sprites->height);
	sprites->floor = mlx_xpm_file_to_image(mlx->init, \
	"./assets/world_map/floor.xpm", &sprites->width, &sprites->height);
	sprites->coin = mlx_xpm_file_to_image(mlx->init, \
	"./assets/coin/coin.xpm", &sprites->width, &sprites->height);
	sprites->gate_c = mlx_xpm_file_to_image(mlx->init, \
	"./assets/exit/gate.xpm", &sprites->width, &sprites->height);
	sprites->gate_o = mlx_xpm_file_to_image(mlx->init, \
	"./assets/exit/gate_open.xpm", &sprites->width, &sprites->height);
	sprites->rtx = 0;
	ft_rtx_vignette(mlx, sprites);
	if (!sprites->player || !sprites->wall || !sprites->floor \
	|| !sprites->coin || !sprites->gate_c || !sprites->gate_o)
		return (ft_printf("Sprites initialization failed"), 0);
	return (1);
}

void	ft_place_sprites(t_mlx *mlx, t_map map, t_img *sprites)
{
	if (map.id[map.y][map.x] == '0')
	{
		mlx_put_image_to_window(mlx->init, mlx->win, \
		sprites->floor, ((map.x * 100)), ((map.y * 100)));
	}
	if (map.id[map.y][map.x] == '1')
	{
		mlx_put_image_to_window(mlx->init, mlx->win, \
		sprites->wall, ((map.x * 100)), ((map.y * 100)));
	}
	if (map.id[map.y][map.x] == 'P')
	{
		mlx_put_image_to_window(mlx->init, mlx->win, \
		sprites->player, ((map.x * 100)), ((map.y * 100)));
	}
	if (map.id[map.y][map.x] == 'C')
	{
		mlx_put_image_to_window(mlx->init, mlx->win, \
		sprites->coin, ((map.x * 100)), ((map.y * 100)));
	}
	if (map.id[map.y][map.x] == 'E')
	{
		mlx_put_image_to_window(mlx->init, mlx->win, \
		sprites->gate_c, ((map.x * 100)), ((map.y * 100)));
	}
}

int	ft_init_map(t_mlx *mlx, t_map map, t_img *sprites)
{
	map.x = 0;
	map.y = 0;
	if (ft_init_sprites(mlx, sprites) == 0)
		return (0);
	while (map.y < map.y_max && map.x <= map.x_max)
	{
		ft_gate_state(mlx, map, sprites);
		ft_place_sprites(mlx, map, sprites);
		mlx_put_image_to_window(mlx->init, mlx->win, \
		sprites->vignette, ((0 * 100)), (((map.y_max - 1) * 100)));
		map.x++;
		if (map.x >= map.x_max && map.y <= map.y_max)
		{
			map.x = 0;
			map.y++;
		}
	}
	return (1);
}

int	ft_window_size(t_mlx *mlx, t_map map)
{
	if (map.x_max == 0 || map.y_max == 0)
		return (0);
	mlx->win_h = (map.y_max * 100);
	mlx->win_h_center = (mlx->win_h / 2);
	mlx->win_w = (map.x_max * 100);
	mlx->win_w_center = (mlx->win_w / 2);
	return (1);
}

int	ft_build_map(t_map map, t_mlx *mlx, t_img *img)
{
	if (ft_window_size(mlx, map) == 0)
		return (0);
	ft_printf("\033[K\rGenerating map.\n\n");
	mlx->init = mlx_init();
	if (!mlx->init)
		return (0);
	mlx->win = mlx_new_window(mlx->init, mlx->win_w, mlx->win_h, "Honk");
	if (!mlx->win)
		return (mlx_destroy_display(mlx->init), free(mlx->init), 0);
	img->p_way = 'R';
	if (ft_init_map(mlx, map, img) == 0)
		return (0);
	return (1);
}
