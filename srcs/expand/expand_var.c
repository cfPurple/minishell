/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 20:30:40 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/12/14 16:22:05 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*replace_by_env(char *word)
{
	t_env	*current;
	char	*new_str;

	current = *get_env(0, 0, 0);
	while (current != NULL)
	{
		if (ft_strcmp(word + 1, current->key) == 0)
			break ;
		current = current->next;
	}
	if (current != NULL)
		new_str = ft_strdup(current->value);
	else
		new_str = ft_strdup("");
	return (new_str);

}

static char	*replace_var_by_value(char *ptr)
{
	char	*str;

	if (ptr[1] == '?' && ft_strlen(ptr) == 2)
		str = ft_itoa(g_error);
	else
		str = replace_by_env(ptr);
	return (str);
}

static int	set_dollar_end(char *str, int start)
{
	if (str[start] == '$')
	{
		start++;
		if (str[start] == '?')
			return (start + 1);
		while (str[start] && (ft_isalpha(str[start]) || str[start] == '_'))
			start++;
	}
	else
		while (str[start] && str[start] != '$')
			start++;
	return (start);
}

static char	**sep_dollar_word(char *str)
{
	char	**sep_str;
	int		start;
	int		end;
	int		i;
	int		j;

	i = 0;
	j = -1;
	sep_str = ft_calloc(dollar_word_count(str) + 1, sizeof(char *));
	if (!sep_str)
		return (NULL);
	while (str[i] && ++j < dollar_word_count(str))
	{
		start = i;
		end = set_dollar_end(str, start);
		sep_str[j] = ft_substr(str, start, end - start);
		while (i < end && str[i])
			i++;
	}
	return (sep_str);
}

char	*expand_var(char *word)
{
	char	**sep_word;
	char	**new_word;
	char	*joined_word;
	int		i;

	if (ft_strchr(word, '$') == 0)
		return (ft_strdup(word));
	sep_word = sep_dollar_word(word);
	if (!sep_word)
		return (NULL);
	new_word = ft_calloc(get_len_tab(sep_word) + 1, sizeof(char *));
	if (!new_word)
		return (NULL);
	i = -1;
	while (sep_word[++i])
	{
		if (ft_strlen(sep_word[i]) > 1 && sep_word[i][0] == '$')
			new_word[i] = replace_var_by_value(sep_word[i]);
		else
			new_word[i] = ft_strdup(sep_word[i]);
		if (!new_word[i])
			return (free_2_tabs(new_word, sep_word), NULL);
	}
	joined_word = ft_join_str(new_word);
	return (free_2_tabs(new_word, sep_word), joined_word);
}
