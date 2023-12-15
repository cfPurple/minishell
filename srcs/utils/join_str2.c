/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_str2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelix <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:57:29 by cfelix            #+#    #+#             */
/*   Updated: 2023/12/15 10:57:30 by cfelix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*join_str2(char *s1, char *s2, char *old_str)
{
	char	*new_str;

	new_str = ft_strjoin(s1, s2);
	if (!new_str)
		return (NULL);
	free(old_str);
	old_str = NULL;
	return (new_str);
}
