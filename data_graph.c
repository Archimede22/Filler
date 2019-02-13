/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_graph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 11:22:36 by jucapik           #+#    #+#             */
/*   Updated: 2019/02/13 15:29:31 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "filler.h"
#include "libft/libft.h"

static char	*check_loser(char *line)
{
	t_piece *p;

	if (ft_strncmp(line, "Piece ", 6) == 0)
	{
		p = get_piece_graph(line);
		free_piece(&p);
		line = NULL;
		get_next_line(0, &line);
		free(line);
		get_next_line(0, &line);
		return (line);
	}
	else
	{
		free(line);
		return (NULL);
	}
}

static int	get_width_height_graph(int *width, int *height)
{
	char	*line;

	line = NULL;
	if (get_next_line(0, &line) <= 0)
	{
		free(line);
		return (-1);
	}
	if (ft_strncmp(line, "Plateau ", 8) != 0)
	{
		if ((line = check_loser(line)) == NULL)
		{
			free(line);
			return (-1);
		}
	}
	return (get_width_height_graph_helper(width, height, line));
}

int			get_line(t_board *b)
{
	char	*line;
	int		i;

	if (get_next_line(0, &line) <= 0)
		return (free_and_error(line));
	i = 0;
	while (line[i] == ' ')
		++i;
	if (i != 4)
		return (free_and_error(line));
	while (line[i] != '\0')
	{
		if ((i - 4) % 10 + '0' != line[i] || i - 4 >= b->width)
			return (free_and_error(line));
		++i;
	}
	free(line);
	return (1);
}

int			get_tab(t_board *board)
{
	char	*line;
	int		i;
	int		j;

	board->val = (char **)malloc(sizeof(char *) * (board->height + 1));
	i = -1;
	line = NULL;
	while (++i < board->height)
	{
		get_next_line(0, &line);
		if (ft_atoi(line) != i)
			return (free_line_board(board, line, i));
		j = 0;
		while (line[j] >= '0' && line[j] <= '9')
			++j;
		if (++j != 4)
			return (free_line_board(board, line, i));
		board->val[i] = ft_strdup(line + j);
		while (line[j] == '.' || line[j] == 'O' || line[j] == 'X' ||
				line[j] == 'x' || line[j] == 'o')
			++j;
		free(line);
	}
	board->val[i] = NULL;
	return (1);
}

t_board		*get_board_graph(void)
{
	t_board *board;

	board = (t_board *)malloc(sizeof(t_board));
	if (get_width_height_graph(&(board->width), &(board->height)) == -1)
	{
		free(board);
		return (NULL);
	}
	if (get_line(board) == -1)
	{
		free(board);
		return (NULL);
	}
	if (get_tab(board) == -1)
	{
		free(board);
		return (NULL);
	}
	return (board);
}
