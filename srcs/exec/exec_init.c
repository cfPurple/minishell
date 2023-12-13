/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:51:05 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/12/01 13:29:59 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	exec_list_args_append(t_cmd **cmd, t_token *token)
{
	token->next = NULL;
	if (token->type == WORD)
	{
		if ((*cmd)->args)
			goto_last_node((*cmd)->args)->next = token;
		else
			(*cmd)->args = token;
	}
	else
	{
		if ((*cmd)->rdir)
			goto_last_node((*cmd)->rdir)->next = token;
		else
			(*cmd)->rdir = token;
	}
	return ;
}

// init cmd

int	exec_new(t_cmd **cmd)
{
	*cmd = ft_calloc(1, sizeof(t_cmd));
	if (!cmd)
		return (ERROR);
	(*cmd)->args = NULL;
	(*cmd)->rdir = NULL;
	(*cmd)->next = NULL;
	(*cmd)->fd[IN] = STDIN_FILENO;
	(*cmd)->fd[OUT] = STDOUT_FILENO;
	(*cmd)->pid = 0;
	(*cmd)->next = NULL;
	return (SUCCESS);
}

// sorting tokens into args and rdir 

int	exec_list_create(t_cmd **cmd, t_token *token)
{
	t_token	*ptr;
	t_cmd	*head;
	t_token	*tmp;

	ptr = token;
	head = *cmd;
	while (ptr != NULL)
	{
		if (ptr->type == PIPE)
		{
			if (exec_new(&(*cmd)->next) == ERROR)
				return (ERROR);
			*cmd = (*cmd)->next;
			ptr = ptr->next;
		}
		else
		{
			tmp = ptr;
			ptr = ptr->next;
			exec_list_args_append(cmd, tmp);
		}
	}
	*cmd = head;
	return (SUCCESS);
}
