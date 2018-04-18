/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 17:38:49 by jukim             #+#    #+#             */
/*   Updated: 2018/03/26 17:52:04 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	store(t_yeee *list, char buf[BUF_SIZE + 1])
{
	ft_strncpy(list->t[0], buf, 4);
	ft_strncpy(list->t[1], buf + 5, 4);
	ft_strncpy(list->t[2], buf + 10, 4);
	ft_strncpy(list->t[3], buf + 15, 4);
	y_position(list);
	x_position(list);
}

void	y_position(t_yeee *list)
{
	int y;
	int x;

	while (list->num)
	{
		y = -1;
		while (++y < 4)
		{
			x = -1;
			while (++x < 4)
			{
				if (list->t[y][x] == '#')
				{
					list->y = y;
					return ;
				}
			}
		}
	}
}

void	x_position(t_yeee *list)
{
	int y;
	int x;

	while (list->num)
	{
		x = -1;
		while (++x < 4)
		{
			y = -1;
			while (++y < 4)
			{
				if (list->t[y][x] == '#')
				{
					list->x = x;
					return ;
				}
			}
		}
	}
}
