/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_matricealloc.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jodoming <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/20 13:11:24 by jodoming     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 13:11:27 by jodoming    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	**ft_matricealloc(size_t d1, size_t d2)
{
	char	**mem;
	size_t	i;

	mem = (char **)malloc(d1);
	if (!mem)
		return (NULL);
	i = 0;
	while (i < d1)
		mem[i++] = ft_memalloc(d2);
	return ((void **)mem);
}
