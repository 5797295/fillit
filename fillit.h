/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkass <michaelkass13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 13:44:30 by mkass             #+#    #+#             */
/*   Updated: 2018/03/27 19:10:13 by mkass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "./libft/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>

# define BUF 546
# define LIST_SIZE 26
# define BUF_SIZE 21
# define CLOSE_EXIT(a, b) if(1){ft_putendl(a); close(b); exit(0);}
# define CHECK_SQ(a, b, c, d, e) if(1){if (a != b && c == d) c = e;}
# define CHECK_SQ2(a, b, c) if(1){if (a == b) a = c;}
# define CHECK_SQ3(a, b, c, d) if(1){if (a == b && c == b) d++;}
# define CK_SQ1(a, b, c) if(1){if (a && b) c;}
# define CK_SQ2(a, b, c, d) if(1){if (a && b && c) d;}

typedef struct	s_yeee
{
	char	t[4][5];
	int		x;
	int		y;
	int		num;
}				t_yeee;

/*
**		check input functions
*/

void			check_row(char *str, int row, int fd);
void			check_column(char *str, int column, int fd);
void			check_square(char *str, int fd);

int				check_middle_row(char *str, int i);
int				check_first_row(char *str, int i);
int				check_last_row(char *str, int i);
int				check_shape(char *str, int fd);

void			check_char(char *str, int fd);
void			check_char_number(char *str, int fd);
void			hash_check(int hash_count, int fd);

/*
**		solve tetriminos functions
*/

int				checks(const char *av);
void			print_tet(char **tet);
char			**board(int size);
void			format_board(char **b, int size);

/*
**		Error handling
*/

void			usage1(void);
void			usage2(void);
void			usage3(void);
void			openerror(void);
void			closeerror(void);

/*
**		others
*/

void			fill_in(t_yeee list[26], char **b, int n);
int				fill_check(t_yeee list, char **b, int b_y, int b_x);
void			fill(t_yeee list, char **b, int b_y, int b_x);
void			delete_list(t_yeee list, char **b, int n);
void			store(t_yeee *list, char buf[BUF_SIZE + 1]);
void			y_position(t_yeee *list);
void			x_position(t_yeee *list);
void			solve(t_yeee list[26], int n);
int				read_file(char *av, t_yeee list[26]);

#endif
