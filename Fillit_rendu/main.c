/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jodoming <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/20 12:48:56 by jodoming     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 12:48:58 by jodoming    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_tetri	*tetriminos;
	int		nb_pcs;

	if (argc != 2)
		ft_putendl("usage: fillit input_file");
	else if (argc == 2)
	{
		nb_pcs = 0;
		if (!(tetriminos = read_input(open(argv[1], O_RDONLY), &nb_pcs)))
			ft_putendl("error");
		else
			solve(tetriminos, nb_pcs);
	}
	return (0);
}
