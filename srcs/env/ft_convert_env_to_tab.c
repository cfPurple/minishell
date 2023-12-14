/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_env_to_tab.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 03:39:59 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/12/14 03:40:20 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_convert_env_to_tab(t_env *env)
{
	char	**start;
	char	**tab;
	int		len;

	len = ft_get_env_len(env);
	tab = (char **)malloc(sizeof(char *) * (len + 1));
	if (!tab)
		return (NULL);
	tab[len] = NULL;
	start = tab;
	while (env)
	{
		*tab = ft_strdup(env->var);
		tab++;
		env = env->next;
	}
	return (start);
}

