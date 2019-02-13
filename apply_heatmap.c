/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_heatmap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 13:26:39 by jucapik           #+#    #+#             */
/*   Updated: 2019/02/13 14:01:41 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "filler.h"

static int		check_place(t_board *b, t_piece *p, t_coord tp, int **hm)
{
	int		i;
	t_bln	one_same;
	t_coord	tc;
	int		val;

	one_same = FALSE;
	i = 0;
	val = 0;
	while (i < p->nb_s)
	{
		tc.x = p->pos[i].x + tp.x;
		tc.y = p->pos[i].y + tp.y;
		if (tc.x < 0 || tc.x >= b->width || tc.y < 0 || tc.y >= b->height
				|| b->val[tc.y][tc.x] == b->op ||
				(b->val[tc.y][tc.x] == b->pl && one_same == TRUE))
			return (-1);
		if (b->val[tc.y][tc.x] == b->pl && one_same == FALSE)
			one_same = TRUE;
		if (hm[tc.y][tc.x] != -1)
			val += hm[tc.y][tc.x];
		++i;
	}
	if (one_same == FALSE)
		return (-1);
	return (val);
}

t_coord			apply_heatmap(int **hm, t_piece *p, t_board *b)
{
	t_coord	toplace;
	t_coord	checking;
	int		max;
	int		tmp;

	toplace.y = -1;
	toplace.x = -1;
	max = -1;
	checking.y = -10;
	while (checking.y < b->height)
	{
		checking.x = -10;
		while (checking.x < b->width)
		{
			if ((tmp = check_place(b, p, checking, hm)) > max)
			{
				toplace.x = checking.x;
				toplace.y = checking.y;
				max = tmp;
			}
			++checking.x;
		}
		++checking.y;
	}
	return (toplace);
}
