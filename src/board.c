/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 15:15:17 by jukim             #+#    #+#             */
/*   Updated: 2018/03/29 13:58:14 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**board(int size)
{
	char	**b;
	int		i;

	i = 0;
	if (!(b = (char**)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	b[size] = NULL;
	while (i < size)
	{
		if (!(b[i] = (char*)malloc(sizeof(char*) * (size + 1))))
			return (NULL);
		b[i][size] = '\0';
		i++;
	}
	format_board(b, size);
	return (b);
}

void	format_board(char **b, int size)
{
	int x;
	int y;

	y = -1;
	while (++y < size)
	{
		x = 0;
		while (x < size)
		{
			if (y > size - 4 || x > size - 4)
				b[y][x++] = '+';
			else
				b[y][x++] = '.';
		}
	}
}
/*
** making it:
**
** ++++++++
** ++++++++
** ++++++++
** +++..+++
** +++..+++
** ++++++++
** ++++++++
** ++++++++
*/
