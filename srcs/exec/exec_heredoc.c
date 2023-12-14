/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:19:52 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/12/14 16:14:25 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	create_heredoc(int type)
{
	int	ret;

	if (type)
	{
		ret = open("/tmp/.heredoc", O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (ret < 0)
			ret = open(".heredoc", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	}
	else
	{
		ret = open("/tmp/.heredoc", O_RDONLY | O_CREAT, 0644);
		if (ret < 0)
			ret = open(".heredoc", O_RDONLY | O_CREAT, 0644);
	}
	return (ret);
}

static int	heredoc_expand(t_token *rdir)
{
	char	*limit;
	char	*line;
	int		fd;

	limit = NULL;
	fd = create_heredoc(1);
	if (fd < 0)
		return (perror(limit), fd);
	if (rdir->next->type == LIMITOR)
		limit = ft_strdup(rdir->next->word);
	while (1)
	{
		line = readline(">>");
		if (line == 0)
			break ;
		if (ft_strcmp(line, limit) == 0)
			break ;
		if (ft_strchr(line, '$') != 0)
			line = expand_heredoc_var(line);
		if (line)
			ft_putstr_fd(line, fd);
		write(fd, "\n", 1);
		free(line);
	}
	return (free(limit), fd);
}

static int	heredoc_no_expand(t_token *rdir)
{
	char	*limit;
	char	*line;
	int		fd;

	limit = NULL;
	fd = create_heredoc(1);
	if (fd < 0)
		return (perror(limit), fd);
	if (rdir->next->type == LIMITOR)
		limit = ft_strtrim(rdir->next->word, "\'\"");
	while (1)
	{
		line = readline(">>");
		if (line == NULL || !limit)
			break ;
		if (ft_strcmp(line, limit) == 0)
			break ;
		ft_putstr_fd(line, fd);
		ft_putstr_fd("\n", fd);
		free(line);
	}
	return (free(limit), fd);
}

// Affichage heredoc avec gestion des signaux (ctrl-c) + quotes handler

int	exec_rdir_heredoc(t_cmd *cmd)
{
	int	ret;
	int	fd;

	ret = dup(STDIN_FILENO);
	signal(SIGINT, &sig_heredoc);
	if (is_quote_heredoc(cmd->rdir) == true)
		fd = heredoc_no_expand(cmd->rdir);
	else
		fd = heredoc_expand(cmd->rdir);
	if (fd < 0)
		return (ERROR);
	close(fd);
	if (g_error == 128)
	{
		dup2(ret, 0);
		init_signal(false);
		return ((close(ret), write(STDOUT_FILENO, "\n", 1), g_error = 130, -1));
	}
	fd = ((close(ret), init_signal(false), create_heredoc(0)));
	if (cmd->fd[IN] != STDOUT_FILENO)
	{
		dup2(fd, cmd->fd[IN]);
		close(cmd->fd[IN]);
	}
	return (cmd->fd[IN] = fd, SUCCESS);
}
