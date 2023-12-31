/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tabs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelix <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:56:28 by cfelix            #+#    #+#             */
/*   Updated: 2023/12/15 10:56:30 by cfelix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_tabs(char **tab1, char **tab2)
{
	if (tab1)
		free_tab(tab1);
	if (tab2)
		free_tab(tab2);
}
