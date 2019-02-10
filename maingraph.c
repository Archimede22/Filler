/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maingraph.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 12:59:31 by jucapik           #+#    #+#             */
/*   Updated: 2019/02/10 16:57:08 by jucapik          ###   ########.fr       */
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

int		main(void)
{
	t_img	*img;

	if ((img = init_img()) == NULL)
		return (1);
	mlx_hook(img->win_ptr, 2, 0, &key_press, (void*)img);
	mlx_loop(img->mlx_ptr);
	close_img(img);
	return (0);
}
