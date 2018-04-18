/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_char_number.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 14:02:27 by jukim             #+#    #+#             */
/*   Updated: 2018/03/27 19:07:31 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	hash_check(int hash_count, int fd)
{
	if (hash_count > 4)
		CLOSE_EXIT("error", fd);
}

void	dot_check(int dot_count, int fd)
{
	if (dot_count > 12)
		CLOSE_EXIT("error", fd);
}

void	check_char_number(char *str, int fd)
{
	int i;
	int hash_count;
	int dot_count;

	i = 0;
	hash_count = 0;
	dot_count = 0;
	while (str[i] != '\0' && hash_count <= 4 && dot_count <= 12)
	{
		if (str[i] == '#')
			hash_count++;
		else if (str[i] == '.')
			dot_count++;
		else if (str[i] == '\n' && str[i - 1] == '\n')
		{
			hash_count = 0;
			dot_count = 0;
		}
		i++;
	}
	hash_check(hash_count, fd);
	dot_check(dot_count, fd);
}
