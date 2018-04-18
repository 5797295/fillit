/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 14:26:53 by mkass             #+#    #+#             */
/*   Updated: 2018/03/27 15:50:59 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	checks(const char *av)
{
	int		piece;
	int		ret;
	int		fd;
	char	str[BUF + 1];

	ret = 1;
	ft_bzero(str, BUF + 1);
	fd = open(av, O_RDONLY);
	CHK2(fd == -1, openerror(), 0);
	while (ret)
	{
		str[ret] = 0;
		ret = read(fd, str, BUF);
		if (ret)
		{
			check_char(str, fd);
			check_char_number(str, fd);
			check_square(str, fd);
			piece = check_shape(str, fd);
		}
	}
	CHK2(close(fd) == -1, closeerror(), 0);
	return (piece);
}
