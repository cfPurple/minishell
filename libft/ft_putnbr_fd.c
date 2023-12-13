/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelix <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:45:02 by cfelix            #+#    #+#             */
/*   Updated: 2022/12/06 17:45:17 by cfelix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long	div;
	long long	ni;

	if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	ni = n;
	if (ni < 0)
	{
		ni = -ni;
		ft_putchar_fd('-', fd);
	}
	div = 1;
	while (div <= ni)
		div = div * 10;
	while (div >= 10)
	{
		div = div / 10;
		ft_putchar_fd((ni / div) + '0', fd);
		ni = ni % div;
	}
}
