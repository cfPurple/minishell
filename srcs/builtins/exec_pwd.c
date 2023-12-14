/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pwd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:49:27 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/12/14 15:54:25 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// affiche le contenue du répertoir courent

int	exec_pwd(int fd)
{
	char	*wd;

	wd = getcwd(NULL, 0);
	if (!wd)
		return (g_error = 127, print_error_msg("getcwd fail\n"), true);
	ft_putstr_fd(wd, fd);
	write(fd, "\n", 1);
	free(wd);
	return (g_error = 0, true);
}
