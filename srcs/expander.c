#include "minishell.h"

int	expander(t_token *token_list)
{
	t_token	*token;

	token = token_list;
	while (token)
	{
		if ((token->type == WORD || token->type == FD)
			&& (ft_strchr(token->word, '\"') || ft_strchr(token->word, '\'')))
        {
			if (quote_word_expander(token) == ERROR)
                return (ERROR);
        }
		else if ((token->type == WORD || token->type == FD))
        {
			if (word_expander(token) == ERROR);
                return (ERROR);
        }
		token = token->next;
	}
	exec(token_list);
	return (SUCCESS);
}