/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 16:42:06 by jucapik           #+#    #+#             */
/*   Updated: 2019/02/07 17:36:49 by jucapik          ###   ########.fr       */
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
	int			check;

	check = 0;
	player_nb = get_player();
	while (check == 0)
	{
		if ((board = get_board()) != NULL)
		{
			board->player = (player_nb == 1) ? 'O' : 'X';
			piece = get_piece();
			toplace = cheater(board, piece);
			ft_putnbr(toplace.y);
			ft_putchar(' ');
			ft_putnbr(toplace.x);
			ft_putchar('\n');
			//free_board(board); TODO
			//free_peice(peice); TODO
			//write(1, "1 1\n", 4);
		}
		else
		{
			check = 1;
//			dprintf(2, "DONE\n");
		}
	}
	return (0);
}
