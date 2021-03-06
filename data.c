/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 17:57:32 by jucapik           #+#    #+#             */
/*   Updated: 2019/02/13 14:48:35 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "filler.h"
#include "libft/libft.h"

#include <stdio.h>

static int	get_width_height(int *width, int *height)
{
	char	*line;
	int		i;

	line = NULL;
	if (get_next_line(0, &line) <= 0)
		return (free_and_error(line));
	if (ft_strncmp(line, "Plateau ", 8) != 0)
		return (free_and_error(line));
	i = 0;
	while (line[i] != ' ')
		++i;
	*height = ft_atoi(line + i);
	++i;
	while (line[i] >= '0' && line[i] <= '9')
		++i;
	*width = ft_atoi(line + i);
	++i;
	while (line[i] >= '0' && line[i] <= '9')
		++i;
	if (line[i] != ':' || line[i + 1] != '\0')
		return (free_and_error(line));
	free(line);
	return (1);
}

static int	get_line(t_board *b)
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

static int	get_tab(t_board *board)
{
	char	*line;
	int		i;

	board->val = (char **)malloc(sizeof(char *) * (board->height + 1));
	i = -1;
	line = NULL;
	while (++i < board->height)
	{
		if (get_next_line(0, &line) < 0)
			return (free_line_board(board, line, i));
		if (ft_atoi(line) != i)
			return (free_line_board(board, line, i));
		if (get_tab_helper(board, line, i) != 1)
			return (-1);
		ft_memdel((void**)&line);
	}
	board->val[i] = NULL;
	return (1);
}

t_board		*get_board(void)
{
	t_board	*board;

	board = (t_board *)malloc(sizeof(t_board));
	if (get_width_height(&(board->width), &(board->height)) == -1)
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
