/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 15:19:43 by jukim             #+#    #+#             */
/*   Updated: 2018/03/31 20:31:18 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	solve(t_yeee list[LIST_SIZE], int piece)
{
	char			**b;
	int				size;

	size = 0;
	while (size * size < piece * 4)
		size++;
	size += 3;
	while (1)
	{
		b = board(size);
		fill_in(list, b, 0);
		size++;
		free(b);
	}
}

void	print_tet(char **tet)
{
	int x;
	int y;

	y = -1;
	while (tet[++y][0] != '+')
	{
		x = -1;
		while (tet[y][++x] != '+')
			write(1, &tet[y][x], 1);
		write(1, "\n", 1);
	}
}
