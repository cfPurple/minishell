/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_to_env_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:45:33 by cfelix            #+#    #+#             */
/*   Updated: 2023/12/15 17:50:16 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*var_to_env_value(char *word)
{
    char	*new_str;
	t_env	*env;

	env = *get_env(0, 0, 0);
    while (env)
    {
		if (ft_strcmp(word + 1, env->key) == 0)
        {
	    	new_str = ft_strdup(env->value);
            return (new_str);
        }
	    env = env->next;
	}
	new_str = ft_strdup("");
	return (new_str);
}