/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   So_long_Main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:13:01 by jcuzin            #+#    #+#             */
/*   Updated: 2023/05/12 04:43:10 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	ft_to_bzero(&game, sizeof(t_game));
	if (argc != 2)
		return (ft_printf("\nError - Invalid ARGC\n"), 0);
	game.map.path = argv[1];
	if (ft_parse_map(argv[1]) == 0)
		return (0);
	game.map.y = 0;
	game.map.y_max = ft_count_l(argv[1]);
	if (ft_save_map(&game.map, game.map.y_max) == 0)
		return (0);
	game.map.x_max = ft_strlen(game.map.id[0]) - 1;
	if (ft_build_map(game.map, &game.mlx, &game.sprites) == 0)
		return (ft_printf("\nError map generation\n"), ft_close_game_p(&game));
	if (ft_find_entity(&game.map, 'P') == 0)
		return (0);
	game.map.move = 0;
	game.map.gate = 0;
	game.map.entities = ft_count_coin(game.map);
	game.sprites.rtx = 0;
	mlx_hook(game.mlx.win, 17, 0, ft_close_game_p, &game);
	mlx_key_hook(game.mlx.win, ft_play, &game);
	mlx_loop(game.mlx.init);
	return (1);
}
