/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 16:42:06 by jucapik           #+#    #+#             */
/*   Updated: 2019/02/06 13:46:24 by jucapik          ###   ########.fr       */
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
	t_coord		toplace;
	int			player_nb;
	
	player_nb = get_player();
	//while (1)
	//{
		board = get_board();
		board->player = (player_nb == 1) ? 'O' : 'X';
		piece = get_piece();
		toplace = dumb_choose(board, piece);
		ft_putnbr(toplace.x);
		ft_putchar(' ');
		ft_putnbr(toplace.y);
		ft_putchar('\n');
		//free_board(board); TODO
		//free_peice(peice); TODO
		//write(1, "1 1\n", 4);
	//}
	(void)piece;
	(void)board;
	(void)toplace;
	return (0);
}
