/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heater.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 09:13:49 by jucapik           #+#    #+#             */
/*   Updated: 2019/02/10 17:41:55 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "filler.h"

void			free_heatmap(int **hm, t_board *b)
{
	int i;

	i = 0;
	while (i < b->height)
		free(hm[i++]);
	free(hm);
}

static t_bln	cp(t_board *b, int i, int j, char c)
{
	if (i < 0 || j < 0 || i >= b->height || j >= b->width || b->val[i][j] != c)
		return (FALSE);
	else
		return (TRUE);
}

static int		assign_place(t_board *b, int i, int j, int max)
{
	int		ret;

	ret = 0;
	if (b->val[i][j] == 'o')
		b->val[i][j] = 'O';
	if (b->val[i][j] == 'x')
		b->val[i][j] = 'X';
	if (b->val[i][j] == 'O' || b->val[i][j] == 'X')
		return (-1);
	if (cp(b, i, j + 1, b->op) == TRUE || cp(b, i, j - 1, b->op) == TRUE ||
			cp(b, i + 1, j, b->op) == TRUE || cp(b, i - 1, j, b->op) == TRUE ||
			cp(b, i + 1, j + 1, b->op) == TRUE || cp(b, i + 1, j - 1, b->op) == TRUE ||
			cp(b, i + 1, j - 1, b->op) == TRUE || cp(b, i - 1, j + 1, b->op) == TRUE)
		ret += max * 2;
	if (i == b->height / 4 || i == (b->height / 4) * 3 ||
			j == b->width / 4 || j == (b->width / 4) * 3)
		ret += max;
	if (cp(b, i, j + 1, b->pl) == TRUE || cp(b, i - 1, j, b->pl) == TRUE ||
			cp(b, i + 1, j, b->pl) == TRUE || cp(b, i, j - 1, b->pl) == TRUE)
		ret += 2;
	return (ret);
}

int				**init_heatmap(t_board *b)
{
	int		i;
	int		j;
	int		**hm;
	int		max;

	max = (b->height > b->width) ? b->height : b->width;
	hm = (int **)malloc(sizeof(int *) * (b->height));
	i = 0;
	while (i < b->height)
	{
		hm[i] = (int *)malloc(sizeof(int) * (b->width));
		j = 0;
		while (j < b->width)
		{
			hm[i][j] = assign_place(b, i, j, max);
//			dprintf(2, "%3d ", hm[i][j]);
			++j;
		}
//		dprintf(2, "\n");
		++i;
	}
//	dprintf(2, "\n");
	return (hm);
}

t_coord			heater(t_board *board, t_piece *piece)
{
	int		**heat_map;
	t_coord	toplace;

	heat_map = init_heatmap(board);
	even_heatmap(heat_map, board);
	toplace = apply_heatmap(heat_map, piece, board);
	free_heatmap(heat_map, board);
	return (toplace);
}
