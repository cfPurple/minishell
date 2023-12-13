/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:03:19 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/12/01 13:03:42 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exec_env(int fd)
{
	t_env	*env;

	env = *ft_get_all_env();
	while (env)
	{
		ft_putstr_fd(env->var, fd);
		write(fd, "\n", 1);
		env = env->next;
	}
	return (g_error = 0, true);
}
