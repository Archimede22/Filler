/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maingraph.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 12:59:31 by jucapik           #+#    #+#             */
/*   Updated: 2019/02/11 17:42:17 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui/SDL2/SDL.h"
#include <stdlib.h>

#include <stdio.h>

#include "libft/libft.h"
#include "filler.h"

int		main(void)
{
	t_img		*img;
	SDL_bool	quit;
	SDL_Event	event;
	char		*line;

	quit = SDL_FALSE;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		return (-1);
	if ((img = init_img()) == NULL)
		return (-1);
	line = NULL;
	get_next_line(0, &line);
	free(line);
	while (!quit)
	{
		SDL_WaitEvent(&event);
		if (event.type == SDL_KEYDOWN)
			key_press(&event, img);
		if (event.type == SDL_QUIT)
			quit = SDL_TRUE;
	}
	close_img(img);
	return (0);
}
