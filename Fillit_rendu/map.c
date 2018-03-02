/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jodoming <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/20 12:49:36 by jodoming     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 12:49:38 by jodoming    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void	print_map(t_map map)
{
	int i;

	i = 0;
	while (map.map[i])
		ft_putendl(map.map[i++]);
}

t_map	new_map(int size)
{
	t_map	new_map;
	int		i;
	int		j;

	new_map.size = size;
	new_map.map = (char **)malloc(sizeof(char *) * size + 1);
	new_map.map[size] = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		new_map.map[i] = ft_strnew(size);
		while (j < size)
			new_map.map[i][j++] = '.';
		new_map.map[i++][j] = '\0';
	}
	return (new_map);
}
