/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 16:58:03 by jucapik           #+#    #+#             */
/*   Updated: 2019/02/07 17:36:41 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H


typedef struct	s_coordinates
{
	int			x;
	int			y;
}				t_coord;

typedef struct	s_board
{
	char		**val;
	int			height;
	int			width;
	char		player;
}				t_board;

typedef struct	s_piece
{
	t_coord		*pos;
	int			height;
	int			width;
	int			nb_s; //nb of starts
}				t_piece;

typedef enum	e_boolean
{
	TRUE = 0,
	FALSE = 1,
	ERROR = -1,
}				t_bln;

int				get_player(void);
t_board			*get_board(void);
t_piece			*get_piece(void);
t_coord			cheater(t_board *board, t_piece *piece);
void			debug(char *s);
void			error(void);

#endif
