/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 03:23:54 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/12/14 03:36:50 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_free_env_elem(t_env *env)
{
	free(env->var);
	free(env->key);
	free(env->value);
	free(env);
}

static void	ft_run_second_if(t_env *env, t_env *prev, t_env *next)
{
	next = env->next;
	ft_free_env_elem(env);
	prev->next = next;
}

t_env	*ft_del_node(t_env *env, char *to_del)
{
	t_env	*prev;
	t_env	*start;
	t_env	*next;
	int		pos;

	pos = 0;
	start = ((prev = env, next = NULL, env));
	while (env)
	{
		if (ft_compare_keys(env->var, to_del) && pos == 0)
		{
			start = env->next;
			ft_free_env_elem(env);
			return (start);
		}
		if (ft_compare_keys(env->var, to_del))
		{
			ft_run_second_keys(env, prev, next);
			break ;
		}
		++pos;
		prev = env;
		env = env->next;
	}
	return (start);
}

