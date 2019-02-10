/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 13:03:29 by jucapik           #+#    #+#             */
/*   Updated: 2019/02/10 17:05:59 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <mlx.h>
#include <stdlib.h>

#include <stdio.h>

#include "libft/libft.h"
#include "filler.h"

void		close_img(t_img *img)
{
	mlx_clear_window(img->mlx_ptr, img->win_ptr);
	mlx_destroy_window(img->mlx_ptr, img->win_ptr);
}

t_img		*init_img(void)
{
	t_img	*img;
	char	*line;
	int		i;

	img = (t_img *)malloc(sizeof(t_img));
	if ((img->mlx_ptr = mlx_init()) == NULL)
		return (NULL);
	i = 0;
	line = NULL;
	while (i++ < 9)
	{
		get_next_line(0, &line);
		free(line);
	}
	img->board = get_board();
	img->block_size = 10;
	img->width = img->board->width * 2 * img->block_size;
	img->height = img->board->height * img->block_size;
	if ((img->win_ptr = mlx_new_window(img->mlx_ptr, img->width,
					img->height, "Filler")) == NULL)
		return (NULL);
	img->hm = init_heatmap(img->board);
	even_heatmap(img->hm, img->board);
	put_img(img, img->board, img->hm);
	free_piece(get_piece());
	free_heatmap(img->hm, img->board);
	free_board(img->board);
	get_next_line(0, &line);
	free(line);
	return (img);
}
