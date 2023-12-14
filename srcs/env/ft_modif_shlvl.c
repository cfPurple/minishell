/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modif_shlvl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 03:45:10 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/12/14 04:04:19 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_modif_shlvl(void)
{
	static const char	str[7] = "SHLVL=\0";
	char				*shlvl;
	char				*tmp;
	int					lvl;

	shlvl = ft_find_value("SHLVL");
	if (!shlvl)
		return ;
	lvl = ft_atoi(shlvl);
	ft_del_from_env("SHLVL");
	++lvl;
	tmp = ft_itoa(lvl);
	shlvl = ft_strjoin(str, tmp);
	free(tmp);
	ft_add_to_env(shlvl);
	free(shlvl);
}
