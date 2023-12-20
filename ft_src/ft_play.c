/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 01:01:27 by jcuzin            #+#    #+#             */
/*   Updated: 2023/05/12 04:05:38 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	ft_open_gate(t_game *game)
{
	ft_find_entity(&game->map, 'E');
	game->map.id[game->map.y][game->map.x] = 'G';
	mlx_put_image_to_window(game->mlx.init, game->mlx.win, \
	game->sprites.gate_o, ((game->map.x * 100)), ((game->map.y * 100)));
	ft_find_entity(&game->map, 'P');
}

void	ft_move_ver(int keycode, t_map *map, t_mlx *mlx, t_img *sprites)
{
	if (keycode == UP_ARROW_KEY && map->id[map->y - 1][map->x] != '1' \
	&& map->id[map->y - 1][map->x] != 'E')
	{
		ft_interact_u(map, mlx, sprites);
		map->id[map->y][map->x] = '0';
		mlx_put_image_to_window(mlx->init, mlx->win, sprites->player, \
		((map->x * 100)), (((map->y - 1) * 100)));
		mlx_put_image_to_window(mlx->init, mlx->win, sprites->floor, \
		((map->x * 100)), ((map->y * 100)));
		map->id[map->y - 1][map->x] = 'P';
		map->y--;
	}
	if (keycode == DOWN_ARROW_KEY && map->id[map->y + 1][map->x] != '1' \
	&& map->id[map->y + 1][map->x] != 'E')
	{
		ft_interact_d(map, mlx, sprites);
		map->id[map->y][map->x] = '0';
		mlx_put_image_to_window(mlx->init, mlx->win, sprites->player, \
		((map->x * 100)), (((map->y + 1) * 100)));
		mlx_put_image_to_window(mlx->init, mlx->win, sprites->floor, \
		((map->x * 100)), ((map->y * 100)));
		map->id[map->y + 1][map->x] = 'P';
		map->y++;
	}
}

void	ft_move_ho(int keycode, t_map *map, t_mlx *mlx, t_img *sprites)
{
	if (keycode == RIGHT_ARROW_KEY && map->id[map->y][map->x + 1] != '1' \
	&& map->id[map->y][map->x + 1] != 'E')
	{
		ft_interact_r(map, mlx, sprites);
		map->id[map->y][map->x] = '0';
		mlx_put_image_to_window(mlx->init, mlx->win, sprites->player, \
		(((map->x + 1) * 100)), ((map->y * 100)));
		mlx_put_image_to_window(mlx->init, mlx->win, sprites->floor, \
		((map->x * 100)), ((map->y * 100)));
		map->id[map->y][map->x + 1] = 'P';
		map->x++;
	}
	if (keycode == LEFT_ARROW_KEY && map->id[map->y][map->x - 1] != '1' \
	&& map->id[map->y][map->x - 1] != 'E')
	{
		ft_interact_l(map, mlx, sprites);
		map->id[map->y][map->x] = '0';
		mlx_put_image_to_window(mlx->init, mlx->win, sprites->player, \
		(((map->x - 1) * 100)), ((map->y * 100)));
		mlx_put_image_to_window(mlx->init, mlx->win, sprites->floor, \
		((map->x * 100)), ((map->y * 100)));
		map->id[map->y][map->x - 1] = 'P';
		map->x--;
	}
}

int	ft_play(int keycode, t_game *game)
{
	ft_find_entity(&game->map, 'P');
	if (keycode == ESC_KEY)
		ft_close_game_p(game);
	if (keycode == A_KEY || keycode == Q_KEY || keycode == LEFT_ARROW_KEY)
	{
		ft_player_way(keycode, game);
		ft_move_ho(LEFT_ARROW_KEY, &game->map, &game->mlx, &game->sprites);
	}
	if (keycode == D_KEY || keycode == RIGHT_ARROW_KEY)
	{
		ft_player_way(keycode, game);
		ft_move_ho(RIGHT_ARROW_KEY, &game->map, &game->mlx, &game->sprites);
	}
	if (keycode == Z_KEY || keycode == W_KEY || keycode == UP_ARROW_KEY)
		ft_move_ver(UP_ARROW_KEY, &game->map, &game->mlx, &game->sprites);
	if (keycode == S_KEY || keycode == DOWN_ARROW_KEY)
		ft_move_ver(DOWN_ARROW_KEY, &game->map, &game->mlx, &game->sprites);
	if (keycode == TAB_KEY)
		ft_rtx(game);
	if (game->map.entities == 0 && game->map.gate != 1)
	{
		game->map.gate = 1;
		ft_open_gate(game);
	}
	return (1);
}
