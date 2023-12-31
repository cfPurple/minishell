/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 03:41:55 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/12/14 15:58:57 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	del_env(void)
{
	t_env	*env;
	t_env	*tmp;

	tmp = NULL;
	env = *get_all_env();
	while (env)
	{
		tmp = env;
		env = env->next;
		free(tmp->var);
		tmp->var = NULL;
		free(tmp->key);
		tmp->key = NULL;
		free(tmp->value);
		tmp->value = NULL;
		free(tmp);
		tmp = NULL;
	}
	free_all_env(env);
}
