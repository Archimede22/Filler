/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 16:50:14 by jucapik           #+#    #+#             */
/*   Updated: 2019/02/10 18:17:52 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include "filler.h"

void	key_n(t_img *img)
{
	char *line;

	if ((img->board = get_board()) != NULL)
	{
		img->hm = init_heatmap(img->board);
		even_heatmap(img->hm, img->board);
		put_img(img, img->board, img->hm);
		free_heatmap(img->hm, img->board);
		free_board(img->board);
		free_piece(get_piece());
		line = NULL;
		get_next_line(0, &line);
		free(line);
	}
}

void	key_m(t_img *img)
{
	char *line;

	if ((img->board = get_board()) != NULL)
	{
		free_board(img->board);
		free_piece(get_piece());
		line = NULL;
		get_next_line(0, &line);
		free(line);
	}
	if ((img->board = get_board()) != NULL)
	{
		free_board(img->board);
		free_piece(get_piece());
		line = NULL;
		get_next_line(0, &line);
		free(line);
	}
	key_n(img);
}

void	key_esc(t_img *img)
{
	free(img);
	close_img(img);
	exit(0);
}

int		key_press(int keycode, void *param)
{
	t_img *img;

	img = (t_img *)param;
	if (keycode == 45)
		key_n(img);
	if (keycode == 53)
		key_esc(img);		
	if (keycode == 46)
		key_m(img);
	return (0);
}
