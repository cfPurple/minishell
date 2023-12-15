/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 22:13:24 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/11/20 22:14:01 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*join_free(char *s1, char *s2, char *ptr)
{
	char	*join;

	join = ft_strjoin(s1, s2);
	if (!join)
		return (NULL);
	free(ptr);
	ptr = NULL;
	return (join);
}
