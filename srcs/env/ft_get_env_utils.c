/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_env_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 03:42:58 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/12/14 03:43:25 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_init_env(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	ft_get_env(env, NULL, NULL);
	ft_modif_shlvl();
}

void	ft_add_to_env(char *to_add)
{
	ft_get_env(NULL, to_add, NULL);
}

void	ft_del_from_env(char *to_del)
{
	ft_get_env(NULL, NULL, to_del);
}

t_env	**ft_get_all_env(void)
{
	return (ft_get_env(NULL, NULL, NULL));
}

