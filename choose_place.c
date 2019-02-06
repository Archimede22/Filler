/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_place.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 09:31:10 by jucapik           #+#    #+#             */
/*   Updated: 2019/02/06 13:46:26 by jucapik          ###   ########.fr       */
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
		if (tp.y == 7)
			dprintf(2, ", %d = %c", i, b->val[tc.y][tc.x]);
		if (tc.x < 0 || tc.x > b->width || tc.y < 0 || tc.y > b->height)
		{
			dprintf(2, ", case 1\n");
			return (FALSE);
		}
		if (b->player == 'O' && (b->val[tc.y][tc.x] == 'X' ||
					b->val[tc.y][tc.x] == 'x'))
		{
			dprintf(2, ", case 2\n");
			return (FALSE);
		}
		if (b->player == 'X' && (b->val[tc.y][tc.x] == 'O' ||
					b->val[tc.y][tc.x] == 'o'))
		{
			dprintf(2, ", case 3\n");
			return (FALSE);
		}
		if (b->val[tc.y][tc.x] == b->player)
		{
			if (one_same == TRUE)
			{
				dprintf(2, ", case 4\n");
				return (FALSE);
			}
			else
				one_same = TRUE;
		}
		++i;
	}
	if (one_same == FALSE)
	{
		dprintf(2, ", case 5\n");
		return (FALSE);
	}
	dprintf(2, ", found ! :D\n");
	return (TRUE);
}

t_coord			dumb_choose(t_board *board, t_piece *piece)
{
	t_coord toplace;

	toplace.y = 0;
	while (toplace.y < board->height - 1)
	{
		dprintf(2, "y = %d, height = %d\n", toplace.y, board->height);
		toplace.x = 0;
		while (toplace.x < board->width - 1)
		{
			dprintf(2, "\tx = %d, width = %d", toplace.x, board->width);
			if (check_place(board, piece, toplace) == TRUE)
				return (toplace);
			++toplace.x;
		}
		++toplace.y;
	}
	dprintf(2, "something is very wrong\n");
	int i = 0;
	while (i < board->height)
	{
		int j = 0;
		while (j < board->width)
			dprintf(2, "%c", board->val[i][j++]);
		dprintf(2, "\n");
		++i;
	}
	i = 0;
	while (i < piece->nb_s)
	{
		dprintf(2, "x = %d, y = %d\n", piece->pos[i].x, piece->pos[i].y);
		++i;
	}
	dprintf(2, "player = %c\n", board->player);

	return (toplace);
}
