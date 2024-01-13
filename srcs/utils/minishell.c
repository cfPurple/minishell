/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelix <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:57:57 by cfelix            #+#    #+#             */
/*   Updated: 2023/12/24 14:47:19 by cfelix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	minishell(int ac, char **av, char **env)
{
	init_env(ac, av, env);
	init_signal(0);
	if (display_and_read() != SUCCESS)
		ft_putstr_fd(ERROR_STOP, 2);
	free_all_env(*get_env(0, 0, 0));
	rl_clear_history();
	printf("Minishell stopped normally\n");
	exit(1);
}
