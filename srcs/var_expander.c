#include "minishell.h"

char	*var_expander(char *str)
{
	char	**word_tab;
	char	**new_word_tab;
	char	*new_word;
	int		i;

	if (ft_strchr(str, '$') == 0)
		return (ft_strdup(str));
	word_tab = dollar_word_to_tab(str);
	if (!word_tab)
		return (NULL);
	new_word_tab = ft_calloc(ft_tablen(word_tab) + 1, sizeof(char *));
	if (!new_word_tab)
		return (NULL);
	i = 0;
	while (word_tab[i++])
	{
		if (ft_strlen(word_tab[i]) > 1 && word_tab[i][0] == '$')
			new_word_tab[i] = var_to_value(word_tab[i]);
		else
			new_word_tab[i] = ft_strdup(word_tab[i]);
		if (!new_word_tab[i])
			return (free_tabs(new_word_tab, word_tab), NULL);
	}
	new_word = join_str(new_word_tab);
	return (free_tabs(new_word_tab, word_tab), new_word);
}