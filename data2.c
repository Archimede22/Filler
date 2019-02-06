/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucapik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 14:16:11 by jucapik           #+#    #+#             */
/*   Updated: 2019/02/05 17:29:52 by jucapik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "filler.h"

int		get_player(void)
{
	char	*line;
	int		ret;

	get_next_line(0, &line);
	if (ft_strncmp(line, "$$$ exec p", 10) != 0)
	{
		error();
		return (-1);
	}
	ret = ft_atoi(line + 10);
	if (ret != 1 && ret != 2)
	{
		error();
		return (-1);
	}
	if (ft_strncmp(line + 11 , " : [./jucapik.filler]", 21) != 0)
	{
		error();
		return (-1);
	}
	return (ret);
}
