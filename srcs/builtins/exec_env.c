/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:03:19 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/12/14 15:15:03 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//affiche les variables env ligne par ligne

int	exec_env(int fd)
{
	t_env	*env;

	env = *get_all_env();
	while (env)
	{
		ft_putstr_fd(env->var, fd);
		write(fd, "\n", 1);
		env = env->next;
	}
	return (g_error = 0, true);
}
