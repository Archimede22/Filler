/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 16:42:06 by jucapik           #+#    #+#             */
/*   Updated: 2019/02/05 17:02:17 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "libft/libft.h"
#include "filler.h"

#include <stdio.h>

int		main(void)
{
	t_board		*board;
	t_piece		*piece;
//	t_coord		toplace;
	int			player;
	
	player = get_player();
	//while (1)
	//{
		board = get_board();
		board->player = player;
		piece = get_piece();
		/*toplace = dumb_choose(board, piece);
		ft_putnbr(toplace.x);
		ft_putchar(' ');
		ft_putnbr(toplace.y);
		ft_putchar('\n');*/
		/*char *line = NULL;
		  while (get_next_line(0, &line) != 0)
		  {
		  write(2, "DEBUG: ", 7);
		  write(2, line, ft_strlen(line));
		  write(2, "\n", 1);
		  free(line);
		  }*/
		//free_board(board); TODO
		//free_peice(peice); TODO
		(void)piece;
		write(1, "1 1\n", 4);
	//}
	return (0);
}
