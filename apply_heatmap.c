/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_heatmap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 13:26:39 by jucapik           #+#    #+#             */
/*   Updated: 2019/02/08 14:43:50 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "filler.h"

static int    check_place(t_board *b, t_piece *p, t_coord tp, int **hm)
{
	int     i;
	t_bln   one_same; //true if there has already been a X/O placed on
	t_coord tc; // to check
	int		val;

	one_same = FALSE;
	i = 0;
	val = 0;
	while (i < p->nb_s)
	{
		tc.x = p->pos[i].x + tp.x;
		tc.y = p->pos[i].y + tp.y;
		if (tc.x < 0 || tc.x >= b->width || tc.y < 0 || tc.y >= b->height
				|| b->val[tc.y][tc.x] == b->op)
		{
	//		dprintf(2, "%3c", 'A');
			return (-1);
		}
		if (b->val[tc.y][tc.x] == b->pl && one_same == TRUE)
		{
	//		dprintf(2, "%3c", 'B');
				return (-1);
		}
		if (b->val[tc.y][tc.x] == b->pl && one_same == FALSE)
			one_same = TRUE;
		if (hm[tc.y][tc.x] != -1)
			val += hm[tc.y][tc.x];
		++i;
	}
	if (one_same == FALSE)
	{
	//	dprintf(2, "%3c", 'C');
		return (-1);
	}
	//dprintf(2, "%3c", 'Z');
	return (val);
}

t_coord         apply_heatmap(int **hm, t_piece *p, t_board *b)
{
	t_coord toplace;
	t_coord	checking;
	int		max;

	toplace.y = -1;
	toplace.x = -1;
	max = -1;
	checking.y = -10;
	while (checking.y < b->height)
	{
		checking.x = -10;
		while (checking.x < b->width)
		{
			int tmp = check_place(b, p, checking, hm);
//			dprintf(2, "%2d ", tmp);
			if (tmp > max)
			{
				toplace.x = checking.x;	
				toplace.y = checking.y;	
				max = tmp;
			}
			++checking.x;
		}
//		dprintf(2, "\n\n");
		++checking.y;
	}
//	dprintf(2, "\n\n");
	return (toplace);
}
