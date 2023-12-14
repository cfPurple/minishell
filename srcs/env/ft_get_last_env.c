/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_last_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 03:13:42 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/12/14 03:14:03 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*ft_get_last_env(t_env *env)
{
	while (env)
	{
		if (!env->next)
			return (env);
		env = env->next;
	}
	return (env);
}

