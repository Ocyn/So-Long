/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_way.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 03:48:14 by jcuzin            #+#    #+#             */
/*   Updated: 2023/05/12 06:21:50 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	ft_gate_state(t_mlx *mlx, t_map map, t_img *sprites)
{
	if (map.id[map.y][map.x] == 'G')
	{
		mlx_put_image_to_window(mlx->init, mlx->win, \
		sprites->gate_o, ((map.x * 100)), ((map.y * 100)));
	}
}

void	ft_is_rtx_on_l(t_mlx *mlx, t_img *sprites)
{
	if (sprites->rtx == 0)
	{
		sprites->player = mlx_xpm_file_to_image(mlx->init, \
		"./assets/player/Goose_L.xpm", &sprites->width, \
		&sprites->height);
	}
	else
	{
		sprites->player = mlx_xpm_file_to_image(mlx->init, \
		"./assets/RTX/goose_l.xpm", &sprites->width, \
		&sprites->height);
	}
}

void	ft_is_rtx_on_r(t_mlx *mlx, t_img *sprites)
{
	if (sprites->rtx == 0)
	{
		sprites->player = mlx_xpm_file_to_image(mlx->init, \
		"./assets/player/Goose_R.xpm", &sprites->width, \
		&sprites->height);
	}
	else
	{
		sprites->player = mlx_xpm_file_to_image(mlx->init, \
		"./assets/RTX/goose_r.xpm", &sprites->width, \
		&sprites->height);
	}
}

void	ft_player_way(int keycode, t_game *game)
{
	if (keycode == A_KEY || keycode == Q_KEY || keycode == LEFT_ARROW_KEY)
	{
		game->sprites.p_way = 'L';
		mlx_destroy_image(game->mlx.init, game->sprites.player);
		ft_is_rtx_on_l(&game->mlx, &game->sprites);
		if (!game->sprites.player)
			ft_close_game_p(game);
	}
	else if (keycode == D_KEY || keycode == RIGHT_ARROW_KEY)
	{
		game->sprites.p_way = 'R';
		mlx_destroy_image(game->mlx.init, game->sprites.player);
		ft_is_rtx_on_r(&game->mlx, &game->sprites);
		if (!game->sprites.player)
			ft_close_game_p(game);
	}
}
