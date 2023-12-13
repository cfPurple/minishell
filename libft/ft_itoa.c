/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelix <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:25:49 by cfelix            #+#    #+#             */
/*   Updated: 2022/12/06 17:27:57 by cfelix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	*malloctab(long long nb)
{
	int		i;
	char	*tab;

	i = 1;
	if (nb < 0)
	{
		i++;
		nb = -nb;
	}
	while (nb >= 10)
	{
		nb = nb / 10;
		i++;
	}
	tab = malloc(sizeof(char) * (i + 1));
	if (tab == NULL)
		return (NULL);
	return (tab);
}

static void	lil_itoa(long long ni, char **tab)
{
	long long	div;
	long long	i;

	i = 0;
	if (ni < 0)
	{
		ni = -ni;
		(*tab)[i++] = '-';
	}
	div = 1;
	while (div <= ni)
		div = div * 10;
	while (div >= 10)
	{
		div = div / 10;
		(*tab)[i++] = ((ni / div) + '0');
		ni = ni % div;
	}
	(*tab)[i] = '\0';
}

char	*ft_itoa(int nb)
{
	char		*tab;
	long long	ni;

	ni = nb;
	if (ni == 0)
	{
		tab = malloc(sizeof(char) * 2);
		tab[0] = '0';
		tab[1] = '\0';
		return (tab);
	}
	tab = malloctab(ni);
	if (tab == NULL)
		return (NULL);
	lil_itoa(ni, &tab);
	return (tab);
}
