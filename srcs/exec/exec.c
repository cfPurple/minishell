/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:32:03 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/11/17 13:57:41 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec(t_token *token)
{
	t_cmd	*cmd;

	if (exec_new(&cmd) == ERROR)
		return ;
	if (exec_list_create(&cmd, token) == ERROR)
		return ;
	exec_launch(cmd);
}
