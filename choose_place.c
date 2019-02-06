/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_place.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 09:31:10 by jucapik           #+#    #+#             */
/*   Updated: 2019/02/05 17:29:51 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "filler.h"

#include <stdio.h>

/*static bln	check_place(t_board *b, t_piece *p, t_coord tp)
{
	int		i;
	bln		one_same; //true if there has already been a X/O placed on

	one_same = FALSE;
	i = 0;
	while (i < nb_s)
	{
		if (p->pos[i].x + tp.x < 0 || p->pos[i].x + tp.x > b->width
				|| p->pos[i].y + tp.y < 0 || p->pos[i].y + tp.y > b->height)
			return (FALSE);
		if (b->val[p->pos[i].y + tp.y][p->pos[i].x + tp.x] == b->player)
		{
			if (one_same == TRUE)
				return (FALSE);
			else
				one_same = TRUE;
		}
	}
	if (one_same == FALSE)
		return (FALSE);
	return (TRUE);
}

t_coord		dumb_choose(t_board *board)
{
	t_coord toplace;

	toplace.y = 0;
	while (toplace.y < board->height)
	{
		toplace.x = 0;
		while (toplace.x < board->width)
		{
			if (board->val[toplace.y][toplace.x] == 'X')
			{
				dprintf(2, "DEBUG: ");
				dprintf(2, "x = %d, y = %d\n", toplace.x, toplace.y);
				return (toplace);
			}
			++toplace.x;
		}
		++toplace.y;
	}
	write(2, "NOPE\n", 5);
	return (toplace);
}
