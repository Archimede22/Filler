/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 13:55:32 by jucapik           #+#    #+#             */
/*   Updated: 2019/02/10 18:38:04 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <mlx.h>
#include <stdio.h>
#include "filler.h"
#include "libft/libft.h"

static int		*get_c_img(void *img_ptr)
{
	char	*c_img;
	int		bpp;
	int		sl;
	int		endian;

	c_img = mlx_get_data_addr(img_ptr, &bpp, &sl, &endian);
	return ((int *)c_img);
}

static int		get_hm_color(t_coord p, t_img *img, t_board *b, int **hm)
{
	double		mult;
	int			ret;
	int			i;
	t_coord		t;
	int			max;

	max = (b->width > b->height) ? b->width : b->height;
	t.x = p.x / img->block_size;
	t.y = p.y / img->block_size;
	if (hm[t.y][t.x - b->width] == -1)
		return (0x777777);
	mult = max / 16.0;
	ret = 0;
	i = 0;
//	while (i < 6)
//	{
		ret += (int)(hm[t.y][t.x - b->width] * 10);
//		++i;
//	}
	ret += 0x0000f0;
	return (ret);
}

static int		get_board_color(t_coord p, t_img *img, t_board *b)
{
	int		x;
	int		y;

	x = p.x / img->block_size;
	y = p.y / img->block_size;
	if (b->val[y][x] == '.')
		return (0X000000);
	else if (b->val[y][x] == 'X')
		return (0x0000a0);
	else if (b->val[y][x] == 'O')
		return (0x00a050);
	else if (b->val[y][x] == 'x')
		return (0x550000);
	else if (b->val[y][x] == 'o')
		return (0x005500);
	return (0xffffff);
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
			if (p.x / img->block_size < b->width)
				img->val[p.y * img->width + p.x] = get_board_color(p, img, b);
			else
				img->val[p.y * img->width + p.x] = get_hm_color(p, img, b, hm);	
			++p.x;
		}
		++p.y;
	}
}

void            put_img(t_img *img, t_board *b, int **hm)
{
	mlx_clear_window(img->mlx_ptr, img->win_ptr);
	img->ptr = mlx_new_image(img->mlx_ptr, img->width, img->height);
	img->val = get_c_img(img->ptr);
	fill_img(img, b, hm);
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->ptr, 0, 0);
	mlx_destroy_image(img->mlx_ptr, img->ptr);
}
