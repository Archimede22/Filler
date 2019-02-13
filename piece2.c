/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 09:15:29 by jucapik           #+#    #+#             */
/*   Updated: 2019/02/13 15:44:49 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include "filler.h"

#include <stdio.h>

static int	rec(char **tab, int x, int y)
{
	int		res;

	if (x >= 0 && y >= 0 && tab[y] != NULL && tab[y][x] != '\0'
			&& tab[y][x] != 'N' && tab[y][x] == '*')
	{
		res = 1;
		tab[y][x] = 'N';
		res += rec(tab, x, y + 1);
		res += rec(tab, x, y - 1);
		res += rec(tab, x - 1, y);
		res += rec(tab, x + 1, y);
		res += rec(tab, x + 1, y + 1);
		res += rec(tab, x - 1, y - 1);
		res += rec(tab, x + 1, y - 1);
		res += rec(tab, x - 1, y + 1);
		return (res);
	}
	return (0);
}

int			check_piece(char **tab, t_piece *p)
{
	int		x;
	int		y;
	int		res;

	x = p->pos[0].x;
	y = p->pos[0].y;
	res = rec(tab, x, y);
	y = 0;
	while (tab[y] != NULL)
		free(tab[y++]);
	free(tab);
	if (res != p->nb_s)
	{
		error();
		return (-1);
	}
	else
		return (1);
}
