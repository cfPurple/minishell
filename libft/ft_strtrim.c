/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:03:57 by cfelix            #+#    #+#             */
/*   Updated: 2023/12/15 18:26:52 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	isaset(char const s1, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == s1)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*tab;
	int		len;

	if (!s1)
		return (NULL);
	while (isaset(*s1, set))
		s1++;
	len = ft_strlen(s1);
	while (len > 0 && isaset(s1[len - 1], set))
		len--;
	tab = malloc(sizeof(char) * (len + 1));
	if (!tab)
		return (NULL);
	return (ft_strlcpy(tab, s1, len + 1), tab);
}
