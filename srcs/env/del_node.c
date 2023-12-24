/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 03:23:54 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/12/15 17:43:37 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_env_elem(t_env *env)
{
	free(env->var);
	free(env->key);
	free(env->value);
	free(env);
}

static void	run_second_if(t_env *env, t_env *prev, t_env *next)
{
	next = env->next;
	free_env_elem(env);
	prev->next = next;
}

t_env	*del_node(t_env *env, char *to_del)
{
	t_env	*prev;
	t_env	*start;
	t_env	*next;
	int		pos;

	pos = 0;
	start = ((prev = env, next = NULL, env));
	while (env)
	{
		if (compare_keys(env->var, to_del) && pos == 0)
		{
			start = env->next;
			free_env_elem(env);
			return (start);
		}
		if (compare_keys(env->var, to_del))
		{
			run_second_if(env, prev, next);
			break ;
		}
		++pos;
		prev = env;
		env = env->next;
	}
	return (start);
}
