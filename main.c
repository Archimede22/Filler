/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 16:42:06 by jucapik           #+#    #+#             */
/*   Updated: 2019/02/08 16:40:23 by jucapik          ###   ########.fr       */
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
			board->pl = (player_nb == 1) ? 'O' : 'X';
			board->op = (player_nb == 1) ? 'X' : 'O';
			piece = get_piece();
			toplace = heater(board, piece);
			ft_putnbr(toplace.y);
			ft_putchar(' ');
			ft_putnbr(toplace.x);
			ft_putchar('\n');
			free_board(board);
			free_piece(piece);
		}
		else
			check = 1;
	}
	return (0);
}
