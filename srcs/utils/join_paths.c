/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:11:31 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/11/27 17:24:05 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**join_paths(char **split_path, char *c)
{
	t_list	*dump;
	char	**joined_path;
	int		i;

	i = 0;
	joined_path = ft_calloc(get_tab_len(split_path) + 1, sizeof(char *));
	dump = ft_calloc(1, sizeof(t_list));
	dump_add(split_path, dump);
	while (split_path[i] != 0)
	{
		joined_path[i] = ft_strjoin(split_path[i], c);
		dump_add(split_path[i], dump);
		i++;
	}
	joined_path[i] = NULL;
	dump_add(split_path[i], dump);
	dump_del(dump);
	return (joined_path);
}
