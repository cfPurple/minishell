/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_exit_error.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 20:00:27 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/11/22 20:00:41 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_print_exit_error(t_cmd *cmd, char *var)
{
	ft_del_env();
	rl_clear_history();
	ft_putstr_fd("Minishell: exit: ", STDERR_FILENO);
	ft_putstr_fd(var, STDERR_FILENO);
	ft_free_cmd(cmd);
	ft_putstr_fd(" : numeric argument required\n", STDERR_FILENO);
	return (2);
}
