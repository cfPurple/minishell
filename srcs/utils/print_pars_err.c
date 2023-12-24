/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pars_err.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelix <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:41:10 by cfelix            #+#    #+#             */
/*   Updated: 2023/12/24 14:41:41 by cfelix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_pars_err(char *str)
{
	g_error = 2;
	ft_putstr_fd(ERROR_PARSING, STDERR_FILENO);
	write(STDERR_FILENO, " '", 2);
	ft_putstr_fd(str, STDERR_FILENO);
	write(STDERR_FILENO, "'\n", 2);
}
