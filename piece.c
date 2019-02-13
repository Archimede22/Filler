/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 11:11:27 by jucapik           #+#    #+#             */
/*   Updated: 2019/02/13 15:40:29 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "filler.h"

static int	get_width_height(t_piece *piece)
{
	char	*line;
	int		i;

	line = NULL;
	if (get_next_line(0, &line) <= 0)
		return (free_and_error(line));
	i = 6;
	if (ft_strncmp(line, "Piece ", 6) != 0)
		return (free_and_error(line));
	piece->height = ft_atoi(line + i);
	if (line[i] > '9' || line[i] < '0')
		return (free_and_error(line));
	while (line[i] >= '0' && line[i] <= '9')
		++i;
	if (line[i] != ' ')
		return (free_and_error(line));
	++i;
	piece->width = ft_atoi(line + i);
	while (line[i] >= '0' && line[i] <= '9')
		++i;
	if (line[i] != ':' || line[i + 1] != '\0')
		return (free_and_error(line));
	free(line);
	return (1);
}

static char	**get_tab(t_piece *piece)
{
	char	**tab;
	int		i;

	if ((tab = (char **)malloc(sizeof(char*) * (piece->height + 1))) == NULL)
		return (NULL);
	i = 0;
	while (i < piece->height)
	{
		tab[i] = NULL;
		if (get_next_line(0, &(tab[i])) == 0)
			return (free_piece_and_line(tab, i));
		if ((int)ft_strlen(tab[i]) != piece->width)
			return (free_piece_and_line(tab, i));
		++i;
	}
	tab[i] = NULL;
	return (tab);
}

static int	get_nb_s_and_check(char **tab, t_piece *p)
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
			{
				error();
				return (-1);
			}
			++j;
		}
		++i;
	}
	return (1);
}

static int	get_pos(char **tab, t_piece *p)
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
		++i;
	}
	return (1);
}

/*
** We assume that we're starting with the line "piece X Y"
*/

t_piece		*get_piece(void)
{
	t_piece	*piece;
	char	**tab;

	piece = (t_piece *)malloc(sizeof(t_piece));
	if (get_width_height(piece) == -1)
	{
		free(piece);
		return (NULL);
	}
	if ((tab = get_tab(piece)) == NULL)
	{
		free(piece);
		return (NULL);
	}
	if (get_nb_s_and_check(tab, piece) == -1)
	{
		free(piece);
		return (NULL);
	}
	if (get_pos(tab, piece) == 1 && check_piece(tab, piece) == -1)
	{
		free(piece);
		return (NULL);
	}
	return (piece);
}
