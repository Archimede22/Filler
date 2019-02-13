/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   even_heatmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 11:22:16 by jucapik           #+#    #+#             */
/*   Updated: 2019/02/13 15:30:33 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	cp(t_board *b, int y, int x)
{
	if (y < 0 || x < 0 || y >= b->height || x >= b->width)
		return (FALSE);
	return (TRUE);
}

static int	get_max(t_board *b, int **hm, int y, int x)
{
	int		max;

	max = 0;
	if (cp(b, y, x + 1) == TRUE && max < hm[y][x + 1])
		max = hm[y][x + 1];
	if (cp(b, y, x - 1) == TRUE && max < hm[y][x - 1])
		max = hm[y][x - 1];
	if (cp(b, y + 1, x) == TRUE && max < hm[y + 1][x])
		max = hm[y + 1][x];
	if (cp(b, y - 1, x) == TRUE && max < hm[y - 1][x])
		max = hm[y - 1][x];
	if (max == 0)
		return (1);
	return (max);
}

static void	run_through(int **hm, t_coord start, t_coord dir, t_board *b)
{
	int		startx_og;

	startx_og = start.x;
	while (start.y >= 0 && start.y < b->height)
	{
		start.x = startx_og;
		while (start.x >= 0 && start.x < b->width)
		{
			if (hm[start.y][start.x] != -1)
				hm[start.y][start.x] = get_max(b, hm, start.y, start.x) - 1;
			start.x += dir.x;
		}
		start.y += dir.y;
	}
}

void		even_heatmap(int **hm, t_board *b)
{
	t_coord start;
	t_coord dir;

	start.x = 0;
	start.y = 0;
	dir.x = 1;
	dir.y = 1;
	run_through(hm, start, dir, b);
	start.x = b->width - 1;
	start.y = b->height - 1;
	dir.x = -1;
	dir.y = -1;
	run_through(hm, start, dir, b);
}
