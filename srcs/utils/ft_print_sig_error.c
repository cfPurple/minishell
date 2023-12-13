/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_sig_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:02:47 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/11/27 18:03:04 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_print_sig_error(void)
{
	if (g_error == 128 + SIGTERM)
		ft_putstr_fd("Hello : Terminated\n", STDERR_FILENO);
	else if (g_error == 128 + SIGSEGV)
		ft_putstr_fd("Hello : Segfault!\n", STDERR_FILENO);
	else if (g_error == 128 + SIGQUIT)
		ft_putstr_fd("Hello : Quit (core dumped)\n", STDERR_FILENO);
	else if (g_error == 128 + SIGABRT)
		ft_putstr_fd("Hello : Aborted (core dumped)\n", STDERR_FILENO);
}
