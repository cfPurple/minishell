/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 03:42:58 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/12/14 16:08:40 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_env(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	get_env(env, NULL, NULL);
	get_shlvl();
}

void	add_to_env(char *to_add)
{
	get_env(NULL, to_add, NULL);
}

void	del_from_env(char *to_del)
{
	get_env(NULL, NULL, to_del);
}

t_env	**get_all_env(void)
{
	return (get_env(NULL, NULL, NULL));
}

