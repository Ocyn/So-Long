/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_bzero.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:21:35 by jcuzin            #+#    #+#             */
/*   Updated: 2023/04/27 09:16:06 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_to_bzero(void *str0, size_t n)
{
	int		cursor;
	char	*str;

	cursor = 0;
	str = str0;
	while (n > 0)
	{
		str[cursor] = '\0';
		cursor++;
		n--;
	}
}
