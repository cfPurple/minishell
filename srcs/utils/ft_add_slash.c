/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_slash.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:54:41 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/11/22 18:02:50 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_join_slash(char	const *s1, char	const *s2)
{
	int		i[3];
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	i[1] = ft_strlen((char *)s1);
	i[2] = ft_strlen((char *)s2);
	str = (char *)malloc(sizeof(char) * (i[1] + i[2] + 2));
	if (!str)
		return (NULL);
	i[0] = -1;
	while (s1[++i[0]])
		str[i[0]] = s1[i[0]];
	i[0] = -1;
	str[i[1]++] = '/';
	while (s2[++i[0]])
	{
		str[i[1]] = s2[i[0]];
		i[1]++;
	}
	str[i[1]] = '\0';
	return (str);
}
