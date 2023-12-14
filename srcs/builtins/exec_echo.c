/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 20:06:26 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/12/14 15:13:34 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//check "-n" flag

static int	check_n_flag(char *str)
{
	if (!*str)
		return (true);
	while (*str)
	{
		if (*str != '-' && *str != 'n' && *str != ' ')
			return (false);
		str++;
	}
	return (true);
}

// Parcour les tokens et affiche les variables sur la console

int	exec_echo(t_token *token, int fd)
{
	int	end;

	end = true;
	if (!token)
		return (write(fd, "\n", 1), true);
	while (token && token->word && check_n_flag(token->word))
	{
		end = false;
		token = token->next;
	}
	while (token)
	{
		if (token->word)
			ft_putstr_fd(token->word, fd);
		token = token->next;
		if (token)
			write(fd, " ", 1);
	}
	if (end)
		write(fd, "\n", 1);
	return (g_error = 0, true);
}
