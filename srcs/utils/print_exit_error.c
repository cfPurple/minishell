/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_exit_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 20:00:27 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/12/14 16:36:30 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	print_exit_error(t_cmd *cmd, char *var)
{
	del_env();
	rl_clear_history();
	ft_putstr_fd("Minishell: exit: ", STDERR_FILENO);
	ft_putstr_fd(var, STDERR_FILENO);
	free_cmd(cmd);
	ft_putstr_fd(" : numeric argument required\n", STDERR_FILENO);
	return (2);
}
