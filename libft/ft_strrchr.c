/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelix <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:02:40 by cfelix            #+#    #+#             */
/*   Updated: 2022/12/06 18:03:13 by cfelix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	while (i >= 0)
	{
		if (((char *)s)[i] == (char)c)
			return (&((char *)s)[i]);
		i--;
	}
	return (NULL);
}
