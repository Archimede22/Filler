/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 14:09:49 by jucapik           #+#    #+#             */
/*   Updated: 2019/02/13 14:49:03 by jucapik          ###   ########.fr       */
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
