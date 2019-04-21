/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 13:03:29 by jucapik           #+#    #+#             */
/*   Updated: 2019/04/21 11:26:48 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <stdio.h>

#include "libft/libft.h"
#include "filler.h"

int			check_line(char *truel)
{
	char	*line;

	get_next_line(0, &line);
	if (ft_strcmp(line, truel) != 0)
		return (-1);
	free(line);
	return (1);
}

int			get_start(void)
{
	if (check_line("# -------------- VM  version 1.1 ------------- #") == -1)
		return (-1);
	if (check_line("#                                              #") == -1)
		return (-1);
	if (check_line("# 42 / filler VM Developped by: Hcao - Abanlin #") == -1)
		return (-1);
	if (check_line("#                                              #") == -1)
		return (-1);
	if (check_line("# -------------------------------------------- #") == -1)
		return (-1);
	return (1);
}

int			get_players(t_img *img)
{
	int			i;
	int			j;
	char		*line;
	static int	player = 1;

	if ((i = get_players_helper(&line)) == -1)
		return (-1);
	j = i;
	while (line[j] != '\0' && line[j] != '.')
		++j;
	if (player == 1)
	{
		img->p1 = ft_strsub(line, i, j);
		player = 2;
	}
	else
		img->p2 = ft_strsub(line, i, j);
	free(line);
	get_next_line(0, &line);
	free(line);
	return (1);
}

int			parse_once_with_start(t_img *img, t_board *b)
{
	t_piece *p;

	if (b != NULL)
	{
		img->hm = init_heatmap(img->board);
		even_heatmap(img->hm, img->board);
		put_img(img, img->board, img->hm);
		p = get_piece();
		free_piece(&p);
		free_heatmap(img->hm, img->board);
		free_board(&(img->board));
		return (1);
	}
	else
		return (-1);
}

t_img		*init_img(void)
{
	t_img	*img;

	img = (t_img *)malloc(sizeof(t_img));
	img->win = NULL;
	img->renderer = NULL;
	if (get_start() == -1)
		return (NULL);
	if (get_players(img) == -1)
		return (NULL);
	if (get_players(img) == -1)
		return (NULL);
	img->board = get_board();
	img->block_size = 10;
	img->width = img->board->width * 2 * img->block_size;
	img->height = img->board->height * img->block_size;
	if ((img->win = SDL_CreateWindow("Filler", 700,
					500, img->width, img->height,
					SDL_WINDOW_SHOWN)) == NULL)
		return (NULL);
	if ((img->renderer = SDL_CreateRenderer(img->win, -1,
					SDL_RENDERER_ACCELERATED)) == NULL)
		return (NULL);
	if (parse_once_with_start(img, img->board) == -1)
		return (NULL);
	return (img);
}
