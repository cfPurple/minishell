#include "minishell.h"

t_token	*tab_to_token( char **tab)
{
	t_token	*token_list;
	int		i;

	i = 0;
	while (tab[i])
	{
		if (i == 0)
		{
			token_list = create_new_node(tab[0]);
			if (!token_list)
				return (NULL);
		}
		else
			if (add_new_node(token_list, tab[i]) == ERROR)
				return (NULL);
		if (!token_list)
			return (NULL);
		i++;
	}
	return (token_list);
}