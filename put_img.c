/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 13:55:32 by jucapik           #+#    #+#             */
/*   Updated: 2019/04/21 11:26:56 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "filler.h"
#include "libft/libft.h"

static void		get_hm_color(t_coord p, t_img *img, t_board *b, int **hm)
{
	t_coord			t;
	unsigned int	res;

	t.x = (int)((double)p.x / (double)img->block_size) - b->width;
	t.y = (int)((double)p.y / (double)img->block_size);
	if (b->val[t.y][t.x] == 'X')
		SDL_SetRenderDrawColor(img->renderer, 100, 100, 150, 255);
	else if (b->val[t.y][t.x] == 'O')
		SDL_SetRenderDrawColor(img->renderer, 100, 150, 100, 255);
	else
	{
		if (hm[t.y][t.x] < 0)
			SDL_SetRenderDrawColor(img->renderer, 20, 0, 0, 255);
		else
		{
			res = ft_abs((hm[t.y][t.x] * 5) % 255);
			SDL_SetRenderDrawColor(img->renderer, res, res, res, 255);
		}
	}
}

static void		get_board_color(t_coord p, t_img *img, t_board *b)
{
	int		x;
	int		y;

	x = p.x / img->block_size;
	y = p.y / img->block_size;
	if (b->val[y][x] == '.')
		SDL_SetRenderDrawColor(img->renderer, 0, 0, 0, 255);
	else if (b->val[y][x] == 'X')
		SDL_SetRenderDrawColor(img->renderer, 0, 0, 100, 255);
	else if (b->val[y][x] == 'O')
		SDL_SetRenderDrawColor(img->renderer, 0, 100, 0, 255);
	else if (b->val[y][x] == 'x')
		SDL_SetRenderDrawColor(img->renderer, 100, 0, 0, 255);
	else if (b->val[y][x] == 'o')
		SDL_SetRenderDrawColor(img->renderer, 100, 0, 0, 255);
	else
		SDL_SetRenderDrawColor(img->renderer, 255, 255, 255, 255);
}

static void		fill_img(t_img *img, t_board *b, int **hm)
{
	t_coord	p;

	p.y = 0;
	while (p.y < img->height)
	{
		p.x = 0;
		while (p.x < img->width)
		{
			if (p.x / (double)img->block_size < b->width)
				get_board_color(p, img, b);
			else if (p.x / (double)img->block_size == b->width)
				SDL_SetRenderDrawColor(img->renderer, 255, 255, 255, 255);
			else
				get_hm_color(p, img, b, hm);
			SDL_RenderDrawPoint(img->renderer, p.x, p.y);
			++p.x;
		}
		++p.y;
	}
}

void			put_img(t_img *img, t_board *b, int **hm)
{
	SDL_RenderClear(img->renderer);
	fill_img(img, b, hm);
	SDL_RenderPresent(img->renderer);
	SDL_UpdateWindowSurface(img->win);
}
