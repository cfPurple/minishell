/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 02:15:38 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/12/14 16:03:21 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	**get_env(char **env, char *to_add, char *to_del)
{
	static t_env	*list = NULL;

	if (env)
		list = create_env_list(env);
	else if (to_add)
		env_init_var(&list, to_add);
	else if (to_del)
		list = del_node(list, to_del);
	return (&list);
}
