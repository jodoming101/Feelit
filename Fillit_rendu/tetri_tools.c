/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tetri_tools.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jodoming <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/20 12:56:26 by jodoming     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 12:56:28 by jodoming    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		offset_y(char **tetri)
{
	int y;
	int x;

	y = 0;
	x = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (tetri[x][y] == '#')
				return (y);
			x++;
		}
		y++;
	}
	return (0);
}

void	move_left(char **tetri)
{
	int	x;
	int	y;
	int	offset;

	offset = offset_y(tetri);
	if (offset == 0)
		return ;
	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (tetri[x][y] == '#')
			{
				tetri[x][y - offset] = '#';
				tetri[x][y] = '.';
			}
			x++;
		}
		y++;
	}
}

int		offset_x(char **tetri)
{
	int y;
	int x;

	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			if (tetri[x][y] == '#')
				return (x);
			y++;
		}
		x++;
	}
	return (0);
}

void	move_up(char **tetri)
{
	int	x;
	int	y;
	int	offset;

	offset = offset_x(tetri);
	if (offset == 0)
		return ;
	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			if (tetri[x][y] == '#')
			{
				tetri[x - offset][y] = '#';
				tetri[x][y] = '.';
			}
			y++;
		}
		x++;
	}
}
