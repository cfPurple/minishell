/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_keys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 03:28:08 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/12/14 15:58:00 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	compare_keys(char *key, char *to_find)
{
	if (!to_find)
		return (false);
	while (*to_find && *key && *key != '='
		&& *to_find != '=' && *key == *to_find)
	{
		++key;
		++to_find;
	}
	if (*key == '=' && (!*to_find || *to_find == '='))
		return (true);
	return (false);
}
