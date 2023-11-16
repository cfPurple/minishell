/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelix <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:51:35 by cfelix            #+#    #+#             */
/*   Updated: 2022/12/06 17:54:12 by cfelix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tab;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	tab = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!tab || !s1 || !s2)
		return (NULL);
	while (*s1)
		tab[i++] = *s1++;
	while (*s2)
		tab[i++] = *s2++;
	tab[i] = '\0';
	return (tab);
}
