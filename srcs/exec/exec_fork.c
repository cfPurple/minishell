/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 00:31:05 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/12/15 17:45:28 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_all(char *path, char **env_tab, char **cmd_tab)
{
	if (ft_strcmp(cmd_tab[0], "./") == 0)
		print_error_msg(ERROR_POINT_SLASH);
	else
		print_error_msg(ERROR_CMD);
	free_tabs(env_tab, cmd_tab);
	free(path);
	del_env();
	g_error = 127;
}

int	exec_child(t_cmd *cmd, t_cmd *start)
{
	char	**env_tab;
	char	**cmd_tab;
	char	*path;

	cmd_tab = convert_args_to_tab(cmd->args);
	env_tab = convert_env_to_tab(*get_env(0, 0, 0));
	path = init_path(cmd_tab[0]);
	if (cmd->fd[IN] != STDIN_FILENO)
	{
		dup2(cmd->fd[IN], STDIN_FILENO);
		close(cmd->fd[IN]);
	}
	if (cmd->fd[OUT] != STDOUT_FILENO)
	{
		dup2(cmd->fd[OUT], STDOUT_FILENO);
		close(cmd->fd[OUT]);
	}
	del_t_cmd(start);
	if (path)
	{
		init_signal(true);
		execve(path, cmd_tab, env_tab);
		free_all(path, env_tab, cmd_tab);
	}
	return (exit(g_error), ERROR);
}

void	exec_fork(t_cmd *cmd, t_cmd *start)
{
	pid_t	pid;

	g_error = 0;
	if (!cmd)
		return ;
	pid = fork();
	if (pid == -1)
		print_error_msg(ERROR_FORK);
	else if (pid == 0)
		exec_child(cmd, start);
	else
		cmd->pid = pid;
}
