#include "minishell.h"

char **str_to_tab(char *str)
{
    char    **tab;
    int     i;
    int     j;
    int     start;
    int     end;

    tab = ft_calloc(nbr_of_token(str) + 1, sizeof(char *));
	if (!tab)
		return (0);
	j = 0;
    i = 0; 
	while (str[i] && j < nbr_of_token(str))
	{
		start = start_of_word(str, i);
		end = end_of_word(str, start);
		tab[j] = ft_substr(str, start, end - start);
		if (!tab[j])
			return (NULL);
		while (str[i] && i < end)
			i++;
		j++;
	}
	tab[j] = NULL;
	return (tab);
}