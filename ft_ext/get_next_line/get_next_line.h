/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 18:50:56 by jcuzin            #+#    #+#             */
/*   Updated: 2023/02/27 15:13:47 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h> 
# include "../Libft/libft.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*ft_alloc(char *buffer, int *rvalue, int fd);
char	*ft_strjoin(char *s1, char *s2, int boolean);
size_t	ft_strlen(const char *s);
int		ft_check_nl(char *to_check);
void	ft_bzero(void *str0);

#endif
