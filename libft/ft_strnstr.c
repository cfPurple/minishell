/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelix <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:26:10 by cfelix            #+#    #+#             */
/*   Updated: 2022/12/06 18:01:51 by cfelix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	n;

	i = 0;
	if (*little == '\0' || little == NULL)
		return ((char *)big);
	if (len == 0)
		return (NULL);
	while (big[i] != '\0' && i < len)
	{
		n = 0;
		while ((big[n + i] == little[n] && big[n + i])
			&& (little[n] && n + i < len))
		{
			if (little[n + 1] == '\0')
				return ((char *)big + i);
			n++;
		}
		i++;
	}
	return (0);
}
