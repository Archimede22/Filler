/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heater.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 09:13:49 by jucapik           #+#    #+#             */
/*   Updated: 2019/02/08 15:52:48 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "filler.h"

static t_bln	cp(t_board *b, int i, int j, char c) // check place
{
	if (i < 0 || j < 0 || i >= b->height || j >= b->width || b->val[i][j] != c)
		return (FALSE);
	else
		return (TRUE);
}

static int		assign_place(t_board *b, int i, int j, int max)
{
	if (b->val[i][j] == 'o')
		b->val[i][j] = 'O';
	if (b->val[i][j] == 'x')
		b->val[i][j] = 'X';
	if (b->val[i][j] == 'O' || b->val[i][j] == 'X')
		return (-1);
	else if (cp(b, i, j + 1, b->op) == TRUE || cp(b, i, j - 1, b->op) == TRUE ||
			cp(b, i + 1, j, b->op) == TRUE || cp(b, i - 1, j, b->op) == TRUE) 
		return (max);
/*	else if ((i < 3 && j < 3) || (i < 3 && j >= b->width - 3) || (i >= b->height - 3
				&& j < 3) || (i >= b->height - 3 && j >= b->width - 3))
		return (max / 5);*/
	else if (cp(b, i, j + 1, b->pl) == TRUE || cp(b, i - 1, j, b->pl) == TRUE || 
			cp(b, i + 1, j, b->pl) == TRUE || cp(b, i, j - 1, b->pl) == TRUE)
		return (2);
	return (0);
}

static int		**init_heatmap(t_board *b)
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
			++j;
		}
		++i;
	}
	return (hm);
}

t_coord			heater(t_board *board, t_piece *piece)
{
	int		**heat_map;
	t_coord	toplace;

	heat_map = init_heatmap(board);
	//0 for nothing, -1 for not valide, max around ennemie and less_max around me
	even_heatmap(heat_map, board);
	//even out
	toplace = apply_heatmap(heat_map, piece, board);
	//declare one variable for the "value" of each placement, test each placement
	//and change value accordingly
	//	free_heatmap(heat_map);
/*	int i = 0, j;
	while (i < board->height)
	{
		j = 0;
		while (j < board->width)
			dprintf(2, "%2d ", heat_map[i][j++]);
		dprintf(2, "\n\n");
		++i;
	}*/
//	toplace.x = 1;
//	toplace.y = 1;
	return (toplace);
}
