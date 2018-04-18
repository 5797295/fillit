/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_square.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 14:43:24 by jukim             #+#    #+#             */
/*   Updated: 2018/03/27 19:08:38 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	check_row(char *str, int row, int fd)
{
	if (*str != '\0' && row < 5)
	{
		if (row == 4 && *str != '\n')
			CLOSE_EXIT("error", fd);
	}
}

void	check_column(char *str, int column, int fd)
{
	if (*str != '\0' && column < 5)
	{
		if (column == 4 && *str != '\n')
			CLOSE_EXIT("error", fd);
	}
}

void	check_square(char *str, int fd)
{
	int column;
	int row;
	int i;

	column = -1;
	row = -1;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && ++column < 5)
		{
			CHECK_SQ3(str[i - 1], '\n', str[i], i);
			check_column(&str[i], column, fd);
			i++;
		}
		row++;
		CHECK_SQ(str[i], '\0', column, 5, -1);
		if (row < 5)
		{
			CHECK_SQ2(row, 4, 0);
			check_row(&str[i], row, fd);
		}
	}
	if (!(str[i] == '\0' && row == 3 && column == 4))
		CLOSE_EXIT("error", fd);
}
