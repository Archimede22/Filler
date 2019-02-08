/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 16:58:03 by jucapik           #+#    #+#             */
/*   Updated: 2019/02/08 13:46:02 by jucapik          ###   ########.fr       */
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
	char		pl;
	char		op;
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
t_coord			heater(t_board *board, t_piece *piece);
void			even_heatmap(int **hm, t_board *b);
t_coord			apply_heatmap(int **hm, t_piece *p, t_board *b);
void			debug(char *s);
void			error(void);
void			free_board(t_board *board);
void			free_piece(t_piece *piece);

#endif
