/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_t_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:35:54 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/12/14 16:34:20 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	del_tokens(t_token *tokens)
{
	t_token	*tmp;

	while (tokens)
	{
		tmp = tokens;
		tokens = tokens->next;
		free(tmp->word);
		free(tmp);
	}
}

void	del_t_cmd(t_cmd *cmd)
{
	t_cmd	*tmp;

	while (cmd)
	{
		tmp = cmd->next;
		del_tokens(cmd->args);
		del_tokens(cmd->rdir);
		if (cmd->fd[IN] != STDIN_FILENO)
			close(cmd->fd[IN]);
		if (cmd->fd[OUT] != STDOUT_FILENO)
			close(cmd->fd[OUT]);
		free(cmd);
		cmd = tmp;
	}
}
