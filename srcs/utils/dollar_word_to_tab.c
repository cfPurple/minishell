#include "minishell.h"

char	**dollar_word_to_tab(char *str)
{
	char	**word_tab;
	int		i;
	int		j;
	int		end;

	i = 0;
	j = 0;
	word_tab = ft_calloc(count_dollar_word(str) + 1, sizeof(char *));
	if (!word_tab)
		return (NULL);
	while (str[i] && j < count_dollar_word(str))
	{
		end = end_of_dollar_word(str, i);
		word_tab[j] = ft_substr(str, i, end - i);
		while (i < end && str[i])
			i++;
        j++;
	}
	return (word_tab);
}