/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 22:11:56 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/11/20 22:12:52 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_join_all_str(char **split)
{
	int		i;
	char	*str;

	i = -1;
	str = ft_calloc(1, sizeof(char));
	if (!str)
		return (NULL);
	while (split[++i])
	{
		str = join_free(str, split[i], str);
		if (!str)
			return (NULL);
	}
	return (str);
}
