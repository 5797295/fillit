/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 01:42:04 by jukim             #+#    #+#             */
/*   Updated: 2018/03/27 19:11:36 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	t_yeee	list[LIST_SIZE];
	int		piece;
	int		i;

	i = -1;
	CHK2(ac == 1, usage1(), 0);
	CHK2(ac > 2, usage3(), 0);
	ft_bzero(&list, LIST_SIZE);
	piece = read_file(av[1], list);
	CHK2(piece == 0, usage2(), 0);
	solve(list, piece);
	return (0);
}

int		read_file(char *av, t_yeee list[LIST_SIZE])
{
	int		piece;
	int		i;
	int		fd;
	char	buf[BUF_SIZE + 1];
	int		ret;

	i = -1;
	piece = checks(av);
	CHK1(piece == 0, 0);
	fd = open(av, O_RDONLY);
	CHK2(fd == -1, openerror(), 0);
	ret = read(fd, buf, BUF_SIZE);
	while (ret && ++i < LIST_SIZE)
	{
		buf[ret] = '\0';
		list[i].num = 'A' + i;
		store(&list[i], buf);
		ret = read(fd, buf, BUF_SIZE);
	}
	CHK2(close(fd) == -1, closeerror(), 0);
	return (piece);
}
