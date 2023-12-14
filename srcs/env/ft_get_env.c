/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 02:15:38 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/12/14 02:23:40 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	**ft_get_env(char **env, char *to_add, char *to_del)
{
	static t_env	*list = NULL;

	if (env)
		list = ft_create_env_list(env);
	else if (to_add)
		ft_add_var_to_env(&list, to_add);
	else if (to_del)
		list = ft_del_node(list, to_del);
	return (&list);
}

