/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 20:08:38 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/11/22 20:11:52 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_cmd(t_cmd *cmd)
{
	t_cmd *tmp;

	while (cmd)
	{
		if (cmd->args)
			ft_delete_all(&cmd->args);
		if (cmd->rdir)
			ft_delete_all(&cmd->rdir);
		if (cmd->fd[0] != 0)
			close(cmd->fd[0]);
		if (cmd->fd[1] != 1)
			close(cmd->fd[1]);
		tmp = cmd;
		cmd = tmp->next;
		free(tmp);
	}
}
