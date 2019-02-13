/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 16:50:14 by jucapik           #+#    #+#             */
/*   Updated: 2019/02/13 15:37:34 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include "filler.h"

#include <stdio.h>

void	key_o(t_img *img)
{
	char	*line;
	t_piece	*p;

	if ((img->board = get_board_graph()) != NULL)
	{
		p = get_piece();
		free_piece(&p);
		img->hm = init_heatmap(img->board);
		even_heatmap(img->hm, img->board);
		put_img(img, img->board, img->hm);
		free_heatmap(img->hm, img->board);
		line = NULL;
		get_next_line(0, &line);
		free(line);
	}
	free_board(&(img->board));
}

void	key_p(t_img *img)
{
	char	*line;
	t_piece	*p;

	if ((img->board = get_board_graph()) != NULL)
	{
		free_board(&(img->board));
		p = get_piece();
		free_piece(&p);
		line = NULL;
		get_next_line(0, &line);
		free(line);
	}
	if ((img->board = get_board_graph()) != NULL)
	{
		free_board(&(img->board));
		p = get_piece();
		free_piece(&p);
		line = NULL;
		get_next_line(0, &line);
		free(line);
	}
	else
		return ;
	key_o(img);
}

void	key_esc(t_img *img)
{
	free(img->p1);
	free(img->p2);
	free(img);
	close_img(img);
	exit(0);
}

int		key_press(SDL_Event *event, t_img *img)
{
	if (event->key.keysym.sym == SDLK_o)
		key_o(img);
	else if (event->key.keysym.sym == SDLK_ESCAPE)
		key_esc(img);
	else if (event->key.keysym.sym == SDLK_p)
		key_p(img);
	return (0);
}
