/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_rdir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:21:46 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/12/01 13:51:28 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// change [IN] infile for "name" file 

static int	exec_rdir_rin(t_cmd *cmd)
{
	int		fd;
	char	*name;

	if (!cmd->rdir->next)
		ft_print_error_msg(ERROR_RED);
	name = cmd->rdir->next->word;
	fd = open(name, O_RDONLY);
	if (fd < 0)
	{
		perror(name);
		return (ERROR);
	}
	if (cmd->fd[IN] != 0)
	{
		dup2(fd, cmd->fd[IN]);
		close(cmd->fd[IN]);
	}
	cmd->fd[IN] = fd;
	return (SUCCESS);
}

// change [OUT] outfile for "name" file with a blank new file 

static int	exec_rdir_rout(t_cmd *cmd)
{
	int		fd;
	char	*name;

	if (!cmd->rdir->next)
		ft_print_error_msg(ERROR_RED);
	name = cmd->rdir->next->word;
	fd = open(name, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd < 0)
	{
		perror(name);
		return (ERROR);
	}
	if (cmd->fd[OUT] != 1)
	{
		dup2(fd, cmd->fd[OUT]);
		close(cmd->fd[OUT]);
	}
	cmd->fd[OUT] = fd;
	return (SUCCESS);
}

// change [OUT] outfile for "name" file adding content to existing file  

static int	exec_rdir_append(t_cmd *cmd)
{
	int		fd;
	char	*name;

	if (!cmd->rdir->next)
		ft_print_error_msg(ERROR_RED);
	name = cmd->rdir->next->word;
	fd = open(name, O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (fd < 0)
	{
		perror(name);
		return (ERROR);
	}
	if (cmd->fd[OUT] != 1)
	{
		dup2(fd, cmd->fd[OUT]);
		close(cmd->fd[OUT]);
	}
	cmd->fd[OUT] = fd;
	return (SUCCESS);
}

int	exec_rdir(t_cmd *cmd)
{
	t_token	*rdir_temp;
	int		ret;

	rdir_temp = cmd->rdir;
	while (cmd->rdir != 0)
	{
		if (cmd->rdir->type == R_IN)
			ret = exec_rdir_rin(cmd);
		else if (cmd->rdir->type == R_OUT)
			ret = exec_rdir_rout(cmd);
		else if (cmd->rdir->type == APPEND)
			ret = exec_rdir_append(cmd);
		else if (cmd->rdir->type == HEREDOC)
			return (exec_rdir_heredoc(cmd));
		if (ret == ERROR)
			return (g_error = 1, ERROR);
		cmd->rdir = cmd->rdir->next;
	}
	cmd->rdir = rdir_temp;
	return (SUCCESS);
}
