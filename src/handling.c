/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 11:26:55 by mkass             #+#    #+#             */
/*   Updated: 2018/03/27 19:12:09 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	usage1(void)
{
	ft_putendl("usage: ./fillit need a file");
}

void	usage2(void)
{
	ft_putendl("error");
}

void	usage3(void)
{
	ft_putendl("usage: ./fillit has too many file inputs");
}

void	openerror(void)
{
	ft_putendl("File failed to open");
}

void	closeerror(void)
{
	ft_putendl("File failed to close");
}
