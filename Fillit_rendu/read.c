/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   read.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jodoming <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/20 12:49:55 by jodoming     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 12:50:36 by jodoming    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

t_tetri	*read_input(int fd, int *index)
{
	int		retread;
	char	buf[21];
	t_tetri	*tetriminos;
	int		tot_read;

	tot_read = 0;
	if (!(tetriminos = (t_tetri *)malloc(sizeof(t_tetri) * 26)))
		return (NULL);
	while ((retread = read(fd, buf, 20)) == 20)
	{
		if (!check_pcs(buf))
			return (NULL);
		tetriminos[*index] = new_tetri(buf, *index);
		(*index)++;
		tot_read += retread;
		retread = read(fd, buf, 1);
		tot_read += retread;
	}
	if (*buf == '\n' || retread != 0 || tot_read == 0)
		return (NULL);
	if (tot_read > 545)
		return (NULL);
	return (tetriminos);
}

int		check_hashes(char *pcs)
{
	int link;
	int i;

	link = 0;
	i = 0;
	while (i < 20)
	{
		if (pcs[i] == '#')
		{
			if (i - 1 >= 0 && pcs[i - 1] == '#')
				link++;
			if (i - 5 >= 0 && pcs[i - 5] == '#')
				link++;
			if (i + 1 <= 19 && pcs[i + 1] == '#')
				link++;
			if (i + 5 <= 19 && pcs[i + 5] == '#')
				link++;
		}
		i++;
	}
	return (link == 6 || link == 8);
}

int		check_pcs(char *pcs)
{
	int hash;
	int	newline;
	int dot;
	int i;

	hash = 0;
	newline = 0;
	dot = 0;
	i = 0;
	if (!(check_hashes(pcs)))
		return (0);
	if (pcs[i] && pcs[i] != '#' && pcs[i] != '.')
		return (0);
	while (i < 20)
	{
		if (pcs[i] == '#')
			hash++;
		if (pcs[i] == '\n')
			newline++;
		if (pcs[i++] == '.')
			dot++;
	}
	return (hash == 4 && newline == 4 && dot == 12);
}

int		max_side(t_tetri tetri)
{
	if (tetri.width > tetri.height)
		return (tetri.width);
	return (tetri.height);
}
