/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 14:09:49 by jucapik           #+#    #+#             */
/*   Updated: 2019/02/13 17:12:32 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft/libft.h"

int		get_tab_helper(t_board *board, char *line, int i)
{
	int		j;

	j = 0;
	while (line[j] >= '0' && line[j] <= '9')
		++j;
	if (++j != 4)
		return (free_line_board(board, line, i));
	board->val[i] = ft_strdup(line + j);
	while (line[j] == '.' || line[j] == 'O' || line[j] == 'X' ||
			line[j] == 'x' || line[j] == 'o')
		++j;
	if (j != board->width + 4 || line[j] != '\0')
		return (free_line_board(board, line, i));
	return (1);
}

int		get_width_height_graph_helper(int *width, int *height, char *line)
{
	int		i;

	i = 0;
	while (line[i] != ' ')
		++i;
	*height = ft_atoi(line + i++);
	while (line[i] >= '0' && line[i] <= '9')
		++i;
	*width = ft_atoi(line + i);
	++i;
	while (line[i] >= '0' && line[i] <= '9')
		++i;
	if (line[i] != ':' || line[i + 1] != '\0')
	{
		free(line);
		return (-1);
	}
	free(line);
	return (1);
}

int		get_players_helper(char **line)
{
	int		i;

	*line = NULL;
	if (get_next_line(0, line) <= 0)
		return (-1);
	if (ft_strncmp(*line, "launched ", 9) != 0)
		return (-1);
	i = ft_strlen(*line) - 1;
	while (i >= 0 && (*line)[i] != '/')
		--i;
	return (i);
}
