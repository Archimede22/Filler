/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 11:11:27 by jucapik           #+#    #+#             */
/*   Updated: 2019/02/08 11:05:12 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "filler.h"

#include <stdio.h>

static void	get_width_height(t_piece *piece)
{
	char	*line;
	int		i;

	line = NULL;
	if (get_next_line(0, &line) <= 0)
		error();
	i = 6;
	if (ft_strncmp(line, "Piece ", 6) != 0)
		error();
	piece->height = ft_atoi(line + i);
	if (line[i] > '9' || line[i] < '0')
		error();
	while (line[i] >= '0' && line[i] <= '9')
		++i;
	if (line[i] != ' ')
		error();
	++i;
	piece->width = ft_atoi(line + i);
	while (line[i] >= '0' && line[i] <= '9')
		++i;
	if (line[i] != ':' || line[i + 1] != '\0')
		error();
}

static char	**get_tab(t_piece *piece)
{
	char	**tab;
	int		i;

	if ((tab = (char **)malloc(sizeof(char*) * (piece->height + 1))) == NULL)
		error();
	i = 0;
	while (i < piece->height)
	{
		tab[i] = NULL;
		if (get_next_line(0, &(tab[i])) == 0)
		{
			error();
			return (NULL);
		}
		if ((int)ft_strlen(tab[i]) != piece->width)
			error();
		++i;
	}
	tab[i] = NULL;
	return (tab);
}

static void	get_nb_s_and_check(char **tab, t_piece *p)
{
	int		i;
	int		j;

	p->nb_s = 0;
	i = 0;
	while (tab[i] != NULL)
	{
		j = 0;
		while (tab[i][j] != '\0')
		{
			if (tab[i][j] == '*')
				++p->nb_s;
			else if (tab[i][j] != 'X' && tab[i][j] != 'O' && tab[i][j] != 'x'
					&& tab[i][j] != 'o' && tab[i][j] != '.')
				error();
			++j;
		}
		++i;
	}
}

static void	get_pos(char **tab, t_piece *p)
{
	int		i;
	int		j;
	int		pi;

	p->pos = (t_coord *)malloc(sizeof(t_coord) * (p->nb_s * 1));
	pi = 0;
	i = 0;
	while (tab[i] != NULL)
	{
		j = 0;
		while (tab[i][j] != '\0')
		{
			if (tab[i][j] == '*')
			{
				p->pos[pi].x = j;
				p->pos[pi].y = i;
				++pi;
			}
			++j;
		}
		free(tab[i]);
		++i;
	}
	free(tab);
}

/*
** We assume that we're starting with the line "piece X Y"
*/

#include <stdio.h>

t_piece		*get_piece(void)
{
	t_piece *piece;	
	char	**tab;

	piece = (t_piece *)malloc(sizeof(t_piece));
	get_width_height(piece);
	tab = get_tab(piece);
	get_nb_s_and_check(tab, piece);
	get_pos(tab, piece);
/*	int	i = 0;
	while (i < piece->nb_s)
	{
		dprintf(2, "x = %d, y = %d\n", piece->pos[i].x, piece->pos[i].y);
		++i;
	}*/
	return (piece);
}
