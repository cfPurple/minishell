/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_var_to_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 02:27:11 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/12/14 16:02:01 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*env_init_var(t_env **env, char *to_add)
{
	t_env	*new;

	if (!(*env))
	{
		(*env) = malloc(sizeof(t_env));
		if (!(env))
			return (NULL);
		(*env)->var = ft_strdup(to_add);
		(*env)->key = get_key_section((*env)->var, (*env)->key);
		(*env)->value = get_value_section((*env)->var, (*env)->value);
		(*env)->next = NULL;
		return ((*env)->var);
	}
	else
	{
		new = malloc(sizeof(t_env));
		if (!new)
			return (NULL);
	}
	get_last_env(*env)->next = new;
	new->var = ft_strdup(to_add);
	new->key = get_key_section(new->var, new->key);
	new->value = get_value_section(new->var, new->value);
	new->next = NULL;
	return (new->var);
}
