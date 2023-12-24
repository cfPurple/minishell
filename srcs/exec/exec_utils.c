/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:59:13 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/12/15 17:48:56 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_arg_len(t_token *arg)
{
	int		i;
	t_token	*ptr;

	ptr = arg;
	i = 0;
	while (ptr != 0)
	{
		i++;
		ptr = ptr->next;
	}
	return (i);
}

static int	get_cmd_tab_len(char ***tab)
{
	int	i;
	int	j;
	int	len;

	len = 0;
	i = -1;
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
			len++;
	}
	return (len);
}

static void	free_big_tab(char ***tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		if (tab[i])
		{
			free_tab(tab[i]);
			tab[i] = NULL;
		}
		i++;
	}
	free(tab[i]);
	tab[i] = NULL;
	free(tab);
}

static char	**join_all(char ***cmd_tab)
{
	char	**final_tab;
	int		tab_len;
	int		i;
	int		j;
	int		k;

	i = -1;
	tab_len = get_cmd_tab_len(cmd_tab);
	final_tab = ft_calloc(tab_len + 1, sizeof(char *));
	if (!final_tab)
		return (NULL);
	i = -1;
	k = 0;
	while (cmd_tab[++i] && k < tab_len)
	{
		j = -1;
		while (cmd_tab[i][++j])
		{
			final_tab[k] = ft_strdup(cmd_tab[i][j]);
			if (!final_tab[k])
				return (free_tab(final_tab), NULL);
			k++;
		}
	}
	return (final_tab);
}

char	**convert_args_to_tab(t_token *args)
{
	char	***cmd_tab;
	char	**new_tab;
	int		args_nb;
	t_token	*head;
	int		i;

	args_nb = get_arg_len(args);
	cmd_tab = ft_calloc(args_nb + 1, sizeof(char **));
	if (!cmd_tab)
		return (NULL);
	head = args;
	i = -1;
	while (head != NULL && ++i < args_nb)
	{
		cmd_tab[i] = ft_split(head->word, ' ');
		if (!cmd_tab[i])
			return (free_big_tab(cmd_tab), NULL);
		head = head->next;
	}
	new_tab = join_all(cmd_tab);
	return (free_big_tab(cmd_tab), new_tab);
}
