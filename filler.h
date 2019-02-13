/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 16:58:03 by jucapik           #+#    #+#             */
/*   Updated: 2019/02/13 17:10:26 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libui/SDL2/SDL.h"

typedef struct		s_coordinates
{
	int				x;
	int				y;
}					t_coord;

typedef struct		s_board
{
	char			**val;
	int				height;
	int				width;
	char			pl;
	char			op;
}					t_board;

typedef struct		s_piece
{
	t_coord			*pos;
	int				height;
	int				width;
	int				nb_s;
}					t_piece;

typedef enum		e_boolean
{
	TRUE = 0,
	FALSE = 1,
	ERROR = -1,
}					t_bln;

typedef struct		s_img
{
	SDL_Window		*win;
	SDL_Renderer	*renderer;
	t_board			*board;
	int				**hm;
	int				block_size;
	int				height;
	int				width;
	char			*p1;
	char			*p2;
}					t_img;

int					get_player(void);
t_board				*get_board_graph(void);
t_piece				*get_piece_graph(char *line);
t_board				*get_board(void);
t_piece				*get_piece(void);
t_coord				heater(t_board *board, t_piece *piece);
int					**init_heatmap(t_board *b);
void				even_heatmap(int **hm, t_board *b);
t_coord				apply_heatmap(int **hm, t_piece *p, t_board *b);
void				debug(char *s);
void				error(void);
int					check_piece(char **tab, t_piece *p);
void				free_board(t_board **b);
int					free_line_board(t_board *board, char *line, int lim);
int					free_and_error(char *line);
void				free_piece(t_piece **p);
char				**free_piece_and_line(char **tab, int lim);
void				free_heatmap(int **hm, t_board *b);
t_img				*init_img(void);
void				close_img(t_img *img);
void				put_img(t_img *img, t_board *b, int **hm);
int					key_press(SDL_Event *event, t_img *img);
int					get_tab_helper(t_board *board, char *line, int i);
int					get_width_height_graph_helper(int *width, int *heigth,
		char *line);
int					get_players_helper(char **line);

#endif
