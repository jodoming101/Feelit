/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   solve.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jodoming <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/20 12:50:46 by jodoming     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 14:21:28 by jodoming    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void	place_tetri(t_map *map, t_tetri tetri, int i, int j)
{
	int h;
	int w;

	h = 0;
	while (h < tetri.height)
	{
		w = 0;
		while (w < tetri.width)
		{
			if (ft_isalpha(tetri.shape[h][w]))
				(*map).map[i + h][j + w] = tetri.letter;
			w++;
		}
		h++;
	}
}

void	remove_tetri(t_map *map, t_tetri tetri, int i, int j)
{
	int h;
	int w;

	h = 0;
	while (h < tetri.height)
	{
		w = 0;
		while (w < tetri.width)
		{
			if (ft_isalpha(tetri.shape[h][w]))
				map->map[i + h][j + w] = '.';
			w++;
		}
		h++;
	}
}

int		test_tetri(t_map map, t_tetri tetri, int i, int j)
{
	int h;
	int w;

	h = 0;
	while (h < tetri.height)
	{
		w = 0;
		while (w < tetri.width)
		{
			if (map.map[i + h][j + w] != '.' && tetri.shape[h][w] != '.')
				return (0);
			w++;
		}
		h++;
	}
	return (1);
}

int		solve_tetri(t_map map, t_tetri *tetriminos, int index, int nb_pcs)
{
	int		i;
	int		j;
	t_tetri	tetri;

	if (index == nb_pcs)
		return (1);
	tetri = tetriminos[index];
	i = 0;
	while (i < map.size - tetri.height + 1)
	{
		j = 0;
		while (j < map.size - tetri.width + 1)
		{
			if ((test_tetri(map, tetri, i, j)))
			{
				place_tetri(&map, tetri, i, j);
				if (solve_tetri(map, tetriminos, index + 1, nb_pcs))
					return (1);
				remove_tetri(&map, tetri, i, j);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int		solve(t_tetri *tetriminos, int nb_pcs)
{
	int		size;
	t_map	map;
	int		i;

	if (2 * ft_sqrt(nb_pcs) != 0)
		size = 2 * ft_sqrt(nb_pcs);
	else
		size = 2;
	i = 0;
	map = new_map(size);
	while (!(solve_tetri(map, tetriminos, i, nb_pcs)))
		map = new_map(++size);
	print_map(map);
	return (0);
}
