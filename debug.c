/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 11:00:31 by jucapik           #+#    #+#             */
/*   Updated: 2019/02/04 11:02:43 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft/libft.h"

void		debug(char *s)
{
	write(2, "DEBUG: ", 7);
	write(2, s, ft_strlen(s));
	write(2, "\n", 1);
}
