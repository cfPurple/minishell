/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_launch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 13:56:45 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/12/14 16:17:39 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	close_fdtab(t_cmd *cmd)
{
	if (cmd->fd[IN] != STDIN_FILENO)
		close(cmd->fd[IN]);
	if (cmd->fd[OUT] != STDOUT_FILENO)
		close(cmd->fd[OUT]);
}

static void	pipe_init(t_cmd **cmd)
{
	int	fd[2];

	if (pipe(fd) < 0)
		return ;
	(*cmd)->fd[OUT] = fd[OUT];
	(*cmd)->next->fd[IN] = fd[IN];
}

static void	do_child_wait(int pid)
{
	int	wait;

	waitpid(pid, &wait, 0);
	if (WIFEXITED(wait))
		g_error = WEXITSTATUS(wait);
	else if (WIFSIGNALED(wait))
	{
		g_error = 128 + WTERMSIG(wait);
		print_sig_error();
	}
}

static void	process_init(t_cmd *cmd)
{
	t_cmd	*ptr;

	ptr = cmd;
	while (cmd != 0)
	{
		signal(SIGINT, SIG_IGN);
		if (cmd->pid > 0)
			do_child_wait(cmd->pid);
		init_signal(false);
		ptr = cmd;
		cmd = cmd->next;
		if (!ptr->args)
			close_fdtab(ptr);
		del_tokens(ptr->args);
		del_tokens(ptr->rdir);
		free(ptr);
	}
}

/* 1.piping in/out
 * 2. if rdir runing them
 * 3. if builtins runing them
 * 4. try running cmds
 * 5. waiting for child processes 
 */
void	exec_launch(t_cmd *cmd)
{
	t_cmd	*ptr;
	bool	error_found;
	int		ret;

	ptr = cmd;
	while (ptr)
	{
		error_found = false;
		if (ptr->next)
			pipe_init(&ptr);
		if (ptr->rdir != 0)
		{
			ret = exec_rdir(ptr);
			if (ret == -1)
				break ;
			if (ret == ERROR)
				error_found = true;
		}
		if (!error_found && ptr->args && !builtins(ptr->args->word, cmd))
			exec_fork(ptr, cmd);
		close_fdtab(ptr);
		ptr = ptr->next;
	}
	process_init(cmd);
}
