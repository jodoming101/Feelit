/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tetri.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jodoming <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/20 13:51:48 by jodoming     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 13:51:50 by jodoming    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		width(char *pcs)
{
	int width_min;
	int width_max;
	int i;

	i = 0;
	width_min = 0;
	width_max = 4;
	while (i < 20)
	{
		if (pcs[i] == '#' && width_max >= (i % 5))
			width_max = (i % 5);
		if (pcs[i] == '#' && width_min <= (i % 5))
			width_min = (i % 5);
		i++;
	}
	return (width_min - width_max + 1);
}

int		height(char *pcs)
{
	int h_min;
	int h_max;
	int i;

	i = 0;
	h_min = 0;
	while (i < 20)
	{
		if (pcs[i] == '#')
		{
			h_min = i / 5;
			break ;
		}
		i++;
	}
	i = 0;
	while (i < 20)
	{
		if (pcs[i] == '#')
			h_max = i / 5;
		i++;
	}
	return ((h_max - h_min) + 1);
}

char	**shape_tetri(char *piece)
{
	char	**out;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	out = (char **)malloc(sizeof(char *) * 5);
	while (i < 4)
	{
		j = 0;
		out[i] = ft_strnew(4);
		while (piece[k] != '\n')
			out[i][j++] = piece[k++];
		out[i++][j] = '\0';
		k++;
	}
	out[4] = 0;
	return (out);
}

char	**simplify(char **raw, int height, int width, char letter)
{
	char	**simple;
	int		i;
	int		j;

	simple = (char**)ft_matricealloc(sizeof(char *) * (height + 1),
			sizeof(char) * width + 1);
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (raw[i][j] == '#')
				raw[i][j] = letter;
			simple[i][j] = raw[i][j];
			j++;
		}
		simple[i++][j] = '\0';
	}
	simple[i] = 0;
	return (simple);
}

t_tetri	new_tetri(char *pcs, int index)
{
	t_tetri	new;
	char	**raw_shape;

	new.letter = index + 'A';
	new.width = width(pcs);
	new.height = height(pcs);
	raw_shape = shape_tetri(pcs);
	move_left(raw_shape);
	move_up(raw_shape);
	new.shape = simplify(raw_shape, new.height, new.width, new.letter);
	free(raw_shape);
	return (new);
}
