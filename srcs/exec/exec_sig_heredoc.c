/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_sig_heredoc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:47:03 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/11/20 20:40:30 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_sig_heredoc(int sig)
{
	(void)sig;
	close(STDIN_FILENO);
	g_error = 128;
	return ;
}

static void	ft_handle_signal(int sig)
{
	if (sig == SIGQUIT)
		return ;
	if (sig == SIGINT)
	{
		g_error = 130;
		write(STDOUT_FILENO, "\n", 1);
		rl_replace_line("", 1);
		rl_on_new_line();
		rl_redisplay();
	}
}

void	ft_init_signal(int type)
{
	if (!type)
	{
		signal(SIGINT, &ft_handle_signal);
		signal(SIGQUIT, SIG_IGN);
	}
	else if (type)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
	}
}
