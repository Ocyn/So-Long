/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:23:55 by jcuzin            #+#    #+#             */
/*   Updated: 2023/05/12 08:58:33 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>
# include "../ft_ext/ft_ext.h"
# include "../mlx_linux/mlx.h"

# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define Z_KEY 122
# define Q_KEY 113
# define UP_ARROW_KEY 65362
# define RIGHT_ARROW_KEY 65363
# define LEFT_ARROW_KEY 65361
# define DOWN_ARROW_KEY 65364
# define TAB_KEY 65289
# define ESC_KEY 65307

typedef struct s_mlx
{
	void	*init;
	void	*win;
	void	*extra;
	int		win_w;
	int		win_h;
	int		win_w_center;
	int		win_h_center;
}	t_mlx;

typedef struct s_img
{
	int		rtx;
	char	p_way;
	void	*wall;
	void	*floor;
	void	*player;
	void	*vignette;
	void	*coin;
	void	*gate_o;
	void	*gate_c;
	int		width;
	int		height;
	int		p_x;
	int		p_y;
	void	*ptr;
}	t_img;

typedef struct s_line
{
	void	*id;
	int		len;
	int		wall;
	int		floor;
	int		collec;
}	t_line;

typedef struct s_map
{
	char	**id;
	char	*path;
	int		x;
	int		x_max;
	int		y_max;
	int		y;
	int		entities;
	int		move;
	int		gate;
}	t_map;

typedef struct s_game
{
	t_mlx	mlx;
	t_map	map;
	t_img	sprites;
}	t_game;

int		ft_parse_map(char *path);
int		ft_find_entity(t_map *map, char entity);
int		ft_build_map(t_map map, t_mlx *mlx, t_img *img);
int		ft_init_map(t_mlx *mlx, t_map map, t_img *sprites);
int		ft_init_sprites(t_mlx *mlx, t_img *sprites);
int		ft_play(int keycode, t_game *game);
int		ft_count_l(char *path);
int		ft_count_coin(t_map map);
int		ft_check_rep(int fd, int i);
int		ft_check_path(t_map *map, char *path);
int		ft_check_lines(int fd, int end_line, int line_len, int line_index);
int		ft_check_entity(int fd, int end_line, int line_count, int i);
int		ft_check_borders(t_map map, int end_l);
int		ft_is_finishable(char *path, int end_l);
int		ft_save_map(t_map *map, int lines_count);
int		ft_close_game(t_map *map, t_mlx *mlx, t_img *sprites);
int		ft_close_game_p(t_game *game);
int		ft_init_rtx(t_mlx *mlx, t_img *sprites);
int		ft_rtx(t_game *game);;
int		ft_rtx_vignette(t_mlx *mlx, t_img *sprites);

void	ft_place_sprites(t_mlx *mlx, t_map map, t_img *sprites);
void	ft_gate_state(t_mlx *mlx, t_map map, t_img *sprites);
void	ft_place_new_sprites(t_game *game);
void	ft_reset_textures(t_game *game);
void	ft_player_way(int keycode, t_game *game);
void	ft_display(t_game game);
void	ft_free_map(t_map *map);
void	ft_mv_player(t_mlx mlx, t_img goose, t_img gnd);
void	ft_interact_u(t_map *map, t_mlx *mlx, t_img *sp);
void	ft_interact_d(t_map *map, t_mlx *mlx, t_img *sp);
void	ft_interact_l(t_map *map, t_mlx *mlx, t_img *sp);
void	ft_interact_r(t_map *map, t_mlx *mlx, t_img *sp);

#endif