/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_shape.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 14:26:23 by jukim             #+#    #+#             */
/*   Updated: 2018/03/27 19:05:46 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_mr(char *str, int i)
{
	int count;

	count = 0;
	if (str[i - 5] == '#')
		count++;
	if (str[i + 5] == '#')
		count++;
	if (str[i + 1] == '#')
		count++;
	if (str[i - 1] == '#')
		count++;
	return (count);
}

int		check_fr(char *str, int i)
{
	int count;

	count = 0;
	if (str[i + 5] == '#')
		count++;
	if (str[i + 1] == '#')
		count++;
	if (str[i - 1] == '#')
		count++;
	return (count);
}

int		check_lr(char *str, int i)
{
	int count;

	count = 0;
	if (str[i - 5] == '#')
		count++;
	if (str[i + 1] == '#')
		count++;
	if (str[i - 1] == '#')
		count++;
	return (count);
}

int		check_shape(char *str, int fd)
{
	int i;
	int c;
	int line;
	int piece;

	i = -1;
	c = 0;
	line = 0;
	piece = 1;
	while (str[++i] != '\0')
	{
		CK_SQ1(str[i] == '\n', str[i + 1] != '\n', line++);
		CK_SQ1(str[i] == '#', line == 0, c = check_fr(str, i) + c);
		CK_SQ2(str[i] == '#', line > 0, line < 3, c = check_mr(str, i) + c);
		CK_SQ1(str[i] == '#', line == 3, c = check_lr(str, i) + c);
		if (c >= 6 && str[i] == '\n' && str[i - 1] == '\n')
		{
			c = 0;
			line = 0;
			piece++;
		}
	}
	if (c < 6)
		CLOSE_EXIT("error", fd);
	return (piece);
}
