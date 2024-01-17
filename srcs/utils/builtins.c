/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_builtins.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:49:47 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/11/22 19:42:05 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtins(char *path, t_cmd *cmd)
{
	int	exec;

	exec = false;
	if (ft_strcmp(path, "echo") == 0)
		exec = exec_echo(cmd->args->next, cmd->fd[1]);
	else if (ft_strcmp(path, "cd") == 0)
		exec = exec_cd(cmd->args->next, cmd->fd[0], cmd->fd[1]);
	else if (ft_strcmp(path, "pwd") == 0)
		exec = exec_pwd(cmd->fd[1]);
	else if (ft_strcmp(path, "export") == 0)
	{
		if(!cmd->args->next)
			exec = exec_env(cmd->fd[1]);
		else
			exec = exec_export(cmd->args->next);
	}
	else if (ft_strcmp(path, "unset") == 0)
		exec = exec_unset(cmd->args->next);
	else if (ft_strcmp(path, "env") == 0)
		exec = exec_env(cmd->fd[1]);
	else if (ft_strcmp(path, "exit") == 0)
		exec = exec_exit(cmd->args->next, cmd);
	return (exec);
}
