/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 10:55:17 by jucapik           #+#    #+#             */
/*   Updated: 2019/04/21 11:26:26 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "filler.h"

#include <unistd.h>
#include <stdio.h>

int			free_and_error(char *line)
{
	free(line);
	error();
	return (-1);
}

int			free_line_board(t_board *b, char *line, int lim)
{
	int		i;

	i = 0;
	free(line);
	while (i < lim)
		free(b->val[i++]);
	free(b->val);
	error();
	return (-1);
}

void		free_board(t_board **b)
{
	int		i;

	if (*b != NULL)
	{
		i = 0;
		while (i < (*b)->height)
			free((*b)->val[i++]);
		free((*b)->val);
		free((*b));
		*b = NULL;
	}
}

void		free_piece(t_piece **p)
{
	if (*p != NULL)
	{
		free((*p)->pos);
		free((*p));
		*p = NULL;
	}
}

void		close_img(t_img *img)
{
	SDL_DestroyWindow(img->win);
	SDL_Quit();
	exit(0);
}
