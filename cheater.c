/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheater.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 09:31:10 by jucapik           #+#    #+#             */
/*   Updated: 2019/02/10 12:45:03 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "filler.h"

#include <stdio.h>

static t_bln	check_place(t_board *b, t_piece *p, t_coord tp)
{
	int		i;
	t_bln	one_same; //true if there has already been a X/O placed on
	t_coord	tc; // to check

	one_same = FALSE;
	i = 0;
	while (i < p->nb_s)
	{
		tc.x = p->pos[i].x + tp.x;
		tc.y = p->pos[i].y + tp.y;
		if ((tc.x < 0 || tc.x > b->width || tc.y < 0 || tc.y >= b->height)
			|| (b->pl == 'O' && (b->val[tc.y][tc.x] == 'X'
			|| b->val[tc.y][tc.x] == 'x')) || (b->pl == 'X'
			&& (b->val[tc.y][tc.x] == 'O' || b->val[tc.y][tc.x] == 'o')))
			return (FALSE);
		if (b->val[tc.y][tc.x] == b->pl || ((b->pl == 'X'
				&& b->val[tc.y][tc.x] == 'x') || (b->pl == 'O'
				&& b->val[tc.y][tc.x] == 'o')))
		{
			if (one_same == TRUE)
				return (FALSE);
			else
				one_same = TRUE;
		}
		++i;
	}
	if (one_same == FALSE)
		return (FALSE);
	return (TRUE);
}

t_coord			cheater(t_board *board, t_piece *piece)
{
	t_coord toplace;

	toplace.y = 0;
	while (toplace.y < board->height)
	{
		toplace.x = 0;
		while (toplace.x < board->width)
		{
			if (check_place(board, piece, toplace) == TRUE)
				return (toplace);
			++toplace.x;
		}
		++toplace.y;
	}
	return (toplace);
}
