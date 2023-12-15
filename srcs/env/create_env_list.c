/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_env_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 02:24:37 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/12/14 15:58:41 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*create_env_list(char **env)
{
	t_env	*lst;
	t_env	*tmp;

	lst = NULL;
	tmp = NULL;
	while (*env)
	{
		if (!add_var_to_env(&lst, *env))
		{
			while (lst)
			{
				tmp = lst;
				lst = lst->next;
				free(tmp->var);
				free(tmp->key);
				free(tmp->value);
				free(tmp);
			}
			return (NULL);
		}
		env++;
	}
	return (lst);
}

