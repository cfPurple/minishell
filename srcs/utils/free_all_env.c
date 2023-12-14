/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 03:57:00 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/12/14 16:35:00 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_all_env(t_env *env)
{
	t_env	*tmp;

	while (env)
	{
		tmp = env;
		free(tmp->var);
		tmp->var = NULL;
		free(tmp->key);
		tmp->key = NULL;
		free(tmp->value);
		tmp->value = NULL;
		env = env->next;
		free(tmp);
		tmp = NULL;
	}
}

