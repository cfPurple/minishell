/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr_bool.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:58:23 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/12/14 16:37:26 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	strchr_bool(const char *s, int c)
{
	if ((char)c == '\0')
		return (false);
	while (*s)
	{
		if (*s == (char)c)
			return (true);
		s++;
	}
	return (false);
}
