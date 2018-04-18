/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_in.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 15:38:02 by jukim             #+#    #+#             */
/*   Updated: 2018/03/31 20:31:05 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fill_in(t_yeee list[LIST_SIZE], char **b, int n)
{
	int x;
	int y;

	y = -1;
	while (b[++y] != NULL)
	{
		x = -1;
		while (b[y][++x] != '\0')
		{
			if (fill_check(list[n], b, y, x))
			{
				fill(list[n], b, y, x);
				system("clear");
				print_tet(b);
				system("sleep 0.2");
				if (list[n + 1].num != '\0')
					fill_in(list, b, n + 1);
				else
					exit(0);
			}
		}
	}
	delete_list(list[n - 1], b, n - 1);
}

int		fill_check(t_yeee list, char **b, int b_y, int b_x)
{
	int y;
	int x;

	y = 0;
	while (list.t[list.y + y][0] != '\0')
	{
		x = 0;
		while (list.t[list.y + y][list.x + x] != '\0')
		{
			if (list.t[list.y + y][list.x + x] == '#' &&
					b[b_y + y][b_x + x] != '.')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

void	fill(t_yeee list, char **b, int b_y, int b_x)
{
	int y;
	int x;

	y = 0;
	while (list.t[list.y + y][0] != '\0')
	{
		x = 0;
		while (list.t[list.y + y][list.x + x] != '\0')
		{
			if (list.t[list.y + y][list.x + x] == '#')
				b[b_y + y][b_x + x] = list.num;
			x++;
		}
		y++;
	}
}

void	delete_list(t_yeee list, char **b, int n)
{
	int y;
	int x;

	if (n < 0)
		return ;
	y = 0;
	while (b[y] != NULL)
	{
		x = 0;
		while (b[y][x] != '\0')
		{
			if (b[y][x] == list.num)
				b[y][x] = '.';
			x++;
		}
		y++;
	}
}
