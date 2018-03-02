/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jodoming <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/20 12:48:37 by jodoming     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 12:48:40 by jodoming    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./libft/libft.h"
# include <stdio.h>

typedef struct	s_map
{
	int			size;
	char		**map;
}				t_map;

typedef	struct	s_tetri
{
	char		**shape;
	int			width;
	int			height;
	char		letter;
}				t_tetri;

t_map			new_map(int size);
t_tetri			*read_input(int fd, int *nb_pcs);
int				check_hashes(char *pcs);
int				check_pcs(char *pcs);
t_tetri			*parse_pcs(char *pcs);
t_tetri			new_tetri(char *pcs, int index);
t_tetri			empty_tetri(void);
int				test_tetri(t_map map, t_tetri tetri, int i, int j);
void			print_map(t_map map);
int				solve(t_tetri *tetriminos, int nb_pcs);
int				offset_y(char **tetri);
void			move_left(char **tetri);
int				offset_x(char **tetri);
void			move_up(char **tetri);

#endif
