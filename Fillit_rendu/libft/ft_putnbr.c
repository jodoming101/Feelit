/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jodoming <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 12:19:58 by jodoming     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 12:29:11 by jodoming    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	if (n >= 10 || n <= -10)
		ft_putnbr(n / 10);
	else if (n < 0)
		ft_putchar('-');
	ft_putchar(n % 10 * ((n < 0) ? -1 : 1) + '0');
}