/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:56:29 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/12/15 17:49:41 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*copy_path(void)
{
	t_env	*cur_env;
	t_env	*ptr;

	cur_env = *get_env(0, 0, 0);
	if (!cur_env)
		return (NULL);
	ptr = cur_env;
	while (ptr != 0)
	{
		if (ft_strncmp(ptr->key, "PATH", 4) == 0)
			return (ptr->value);
		ptr = ptr->next;
	}
	return (NULL);
}

static char	**create_path(void)
{
	char	*path_copy;
	char	**split_path;
	char	**comp_path;

	path_copy = copy_path();
	if (!path_copy)
	{
		ft_putstr_fd("Error occurred finding path!\n", 2);
		return (NULL);
	}
	split_path = ft_split(path_copy, ':');
	comp_path = join_paths(split_path, "/");
	return (comp_path);
}

char	*init_path(char *cmd)
{
	char	**paths;
	char	*individual_path;
	int		i;

	if (ft_strchr(cmd, '/') != 0)
		return (cmd);
	paths = create_path();
	individual_path = NULL;
	i = 0;
	while (paths[i] != 0)
	{
		if (individual_path != NULL)
		{
			free(individual_path);
			individual_path = NULL;
		}
		individual_path = ft_strjoin(paths[i], cmd);
		if (access(individual_path, X_OK) == 0)
			return (free_tab(paths), individual_path);
		i++;
	}
	return (free_tab(paths), individual_path);
}
