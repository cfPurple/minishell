/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_t_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:35:54 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/11/27 18:05:34 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_del_tokens(t_token *tokens)
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

void	ft_del_t_cmd(t_cmd *cmd)
{
	t_cmd	*tmp;

	while (cmd)
	{
		tmp = cmd->next;
		ft_del_tokens(cmd->args);
		ft_del_tokens(cmd->rdir);
		if (cmd->fd[IN] != STDIN_FILENO)
			close(cmd->fd[IN]);
		if (cmd->fd[OUT] != STDOUT_FILENO)
			close(cmd->fd[OUT]);
		free(cmd);
		cmd = tmp;
	}
}
