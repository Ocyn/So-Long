/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rtx_on.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 02:03:08 by jcuzin            #+#    #+#             */
/*   Updated: 2023/05/12 09:04:02 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	ft_place_new_sprites(t_game *game)
{
	if (game->map.id[game->map.y][game->map.x] == '0')
	{
		mlx_put_image_to_window(game->mlx.init, game->mlx.win, \
		game->sprites.floor, ((game->map.x * 100)), ((game->map.y * 100)));
	}
	if (game->map.id[game->map.y][game->map.x] == '1')
	{
		mlx_put_image_to_window(game->mlx.init, game->mlx.win, \
		game->sprites.wall, ((game->map.x * 100)), ((game->map.y * 100)));
	}
	if (game->map.id[game->map.y][game->map.x] == 'P')
	{
		mlx_put_image_to_window(game->mlx.init, game->mlx.win, \
		game->sprites.player, ((game->map.x * 100)), ((game->map.y * 100)));
	}
	if (game->map.id[game->map.y][game->map.x] == 'C')
	{
		mlx_put_image_to_window(game->mlx.init, game->mlx.win, \
		game->sprites.coin, ((game->map.x * 100)), ((game->map.y * 100)));
	}
	if (game->map.id[game->map.y][game->map.x] == 'E')
	{
		mlx_put_image_to_window(game->mlx.init, game->mlx.win, \
		game->sprites.gate_c, ((game->map.x * 100)), ((game->map.y * 100)));
	}
}

int	ft_rebuild_map(t_game *game)
{
	game->map.x = 0;
	game->map.y = 0;
	while (game->map.y != game->map.y_max)
	{
		game->map.x = 0;
		while (game->map.x != game->map.x_max)
		{
			ft_place_new_sprites(game);
			ft_gate_state(&game->mlx, game->map, &game->sprites);
			game->map.x++;
		}
		game->map.y++;
	}
	return (1);
}

int	ft_init_rtx(t_mlx *mlx, t_img *sprites)
{
	if (sprites->p_way == 'R')
		sprites->player = mlx_xpm_file_to_image(mlx->init, \
		"./assets/RTX/goose_r.xpm", &sprites->width, &sprites->height);
	else
		sprites->player = mlx_xpm_file_to_image(mlx->init, \
		"./assets/RTX/goose_l.xpm", &sprites->width, &sprites->height);
	sprites->wall = mlx_xpm_file_to_image(mlx->init, \
	"./assets/RTX/wall.xpm", &sprites->width, &sprites->height);
	sprites->floor = mlx_xpm_file_to_image(mlx->init, \
	"./assets/RTX/floor.xpm", &sprites->width, &sprites->height);
	sprites->coin = mlx_xpm_file_to_image(mlx->init, \
	"./assets/RTX/coin.xpm", &sprites->width, &sprites->height);
	sprites->gate_c = mlx_xpm_file_to_image(mlx->init, \
	"./assets/RTX/gate_c.xpm", &sprites->width, &sprites->height);
	sprites->gate_o = mlx_xpm_file_to_image(mlx->init, \
	"./assets/RTX/gate_o.xpm", &sprites->width, &sprites->height);
	sprites->rtx = 1;
	ft_rtx_vignette(mlx, sprites);
	if (!sprites->player || !sprites->wall || !sprites->floor \
	|| !sprites->coin || !sprites->gate_c || !sprites->gate_o)
		return (ft_printf("Sprites initialization failed"), 0);
	return (1);
}

void	ft_reset_textures(t_game *game)
{
	if (game->sprites.wall)
		mlx_destroy_image(game->mlx.init, game->sprites.wall);
	if (game->sprites.player)
		mlx_destroy_image(game->mlx.init, game->sprites.player);
	if (game->sprites.floor)
		mlx_destroy_image(game->mlx.init, game->sprites.floor);
	if (game->sprites.coin)
		mlx_destroy_image(game->mlx.init, game->sprites.coin);
	if (game->sprites.gate_c)
		mlx_destroy_image(game->mlx.init, game->sprites.gate_c);
	if (game->sprites.gate_o)
		mlx_destroy_image(game->mlx.init, game->sprites.gate_o);
	if (game->sprites.vignette)
		mlx_destroy_image(game->mlx.init, game->sprites.vignette);
}

int	ft_rtx(t_game *game)
{
	if (game->sprites.rtx == 0)
	{
		ft_reset_textures(game);
		if (ft_init_rtx(&game->mlx, &game->sprites) == 0)
			return (ft_close_game_p(game), 0);
		if (ft_rebuild_map(game) == 0)
			return (ft_close_game_p(game), 0);
		mlx_put_image_to_window(game->mlx.init, game->mlx.win, \
		game->sprites.vignette, ((0 * 100)), \
		(((game->map.y_max - 1) * 100)));
		game->sprites.rtx = 1;
		if (ft_find_entity(&game->map, 'P') == 0)
			return (ft_close_game_p(game), 0);
	}
	else
	{
		ft_reset_textures(game);
		if (ft_init_map(&game->mlx, game->map, &game->sprites) == 0)
			return (ft_close_game_p(game), 0);
		game->sprites.rtx = 0;
		if (ft_find_entity(&game->map, 'P') == 0)
			return (ft_close_game_p(game), 0);
	}
	return (1);
}
