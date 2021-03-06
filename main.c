/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 16:42:06 by jucapik           #+#    #+#             */
/*   Updated: 2019/02/13 16:07:37 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "libft/libft.h"
#include "filler.h"

#include <stdio.h>

void	play_turn(t_board *b, t_piece *p, int player_nb)
{
	t_coord		toplace;

	b->pl = (player_nb == 1) ? 'O' : 'X';
	b->op = (player_nb == 1) ? 'X' : 'O';
	toplace = heater(b, p);
	ft_putnbr(toplace.y);
	ft_putchar(' ');
	ft_putnbr(toplace.x);
	ft_putchar('\n');
}

int		main(void)
{
	t_board		*board;
	t_piece		*piece;
	int			player_nb;
	int			check;

	check = 0;
	player_nb = get_player();
	while (check == 0)
	{
		if ((board = get_board()) != NULL)
		{
			piece = get_piece();
			play_turn(board, piece, player_nb);
		}
		else
			check = 1;
		free_board(&board);
		free_piece(&piece);
	}
	return (0);
}
