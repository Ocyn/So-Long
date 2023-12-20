/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rtx_on_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 08:28:30 by jcuzin            #+#    #+#             */
/*   Updated: 2023/05/12 09:12:15 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	ft_rtx_vignette(t_mlx *mlx, t_img *sprites)
{
	if (sprites->rtx == 1)
		sprites->vignette = mlx_xpm_file_to_image(mlx->init, \
		"./assets/RTX/RTX_ON.xpm", &sprites->width, &sprites->height);
	else
		sprites->vignette = mlx_xpm_file_to_image(mlx->init, \
		"./assets/RTX/RTX_OFF.xpm", &sprites->width, &sprites->height);
	if (!sprites->vignette)
		return (0);
	return (1);
}
