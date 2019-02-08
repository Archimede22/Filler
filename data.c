/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 17:57:32 by jucapik           #+#    #+#             */
/*   Updated: 2019/02/08 10:55:30 by jucapik          ###   ########.fr       */
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
		return (-1);
	if (ft_strncmp(line, "Plateau ", 8) != 0)
		error();
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
		error();
	ft_memdel((void**)&line);
	return (1);
}

int			get_line(t_board *b)
{
	char	*line;
	int		i;

	if (get_next_line(0, &line) <= 0)
		return (-1);
	i = 0;
	while (line[i] == ' ')
		++i;
	if (i != 4)
		error();
	while (line[i] != '\0')
	{
		if ((i - 4) % 10 + '0' != line[i] || i - 4 >= b->width)
			error();
		++i;
	}
	ft_memdel((void**)&line);
	return (1);
}

int			get_tab(t_board *board)
{
	char	*line;
	int		i;
	int		j;

	board->val = (char **)malloc(sizeof(char *) * (board->height + 1));
	i = 0;
	line = NULL;
	while (i < board->height)
	{
		if (get_next_line(0, &line) <= 0)
			return (-1);
		if (ft_atoi(line) != i)
			error();
		j = 0;
		while (line[j] >= '0' && line[j] <= '9')
			++j;
		++j;
		if (j != 4)
			error();
		board->val[i] = ft_strdup(line + j);
		while (line[j] == '.' || line[j] == 'O' || line[j] == 'X' ||
				line[j] == 'x' || line[j] == 'o')
			++j;
		ft_memdel((void**)&line);
		++i;
	}
	board->val[i] = NULL;	
	return (1);
}

t_board		*get_board(void)
{
	t_board	*board;

	board = (t_board *)malloc(sizeof(t_board));
	if (get_width_height(&(board->width), &(board->height)) == -1)
		return (NULL);
	if (get_line(board) == -1)
		return (NULL);
	if (get_tab(board) == -1)
		return (NULL);
	return (board);
} //TODO free appropiately with the error() calls
