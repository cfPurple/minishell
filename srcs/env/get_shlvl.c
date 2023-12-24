/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_shlvl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 03:45:10 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/12/14 16:09:20 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// permet de connaitre le niveau d'imbrication 
//des shell en incrémentant la val SHLVL dans l'env

void	get_shlvl(void)
{
	static const char	str[7] = "SHLVL=\0";
	char				*shlvl;
	char				*tmp;
	int					lvl;

	shlvl = find_value("SHLVL");
	if (!shlvl)
		return ;
	lvl = ft_atoi(shlvl);
	del_from_env("SHLVL");
	++lvl;
	tmp = ft_itoa(lvl);
	shlvl = ft_strjoin(str, tmp);
	free(tmp);
	add_to_env(shlvl);
	free(shlvl);
}
