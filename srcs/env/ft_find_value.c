/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 03:52:18 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/12/14 03:52:32 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_find_value(char *var)
{
	t_env	*env;
	char	*tmp;

	if (!var)
		return (NULL);
	env = *ft_get_all_env();
	while (env)
	{
		if (ft_compare_keys(env->var, var))
		{
			tmp = env->var;
			while (*tmp != '=')
				tmp++;
			tmp++;
			return (tmp);
		}
		env = env->next;
	}
	return (NULL);
}

