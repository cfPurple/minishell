#include "minishell.h"

int	word_expander(t_token *token)
{
	char	*new_word;

	if (ft_strchr(token->word, '$') != 0)
	{
		new_word = var_expander(token->word);
		if (!new_word)
			return (ERROR);
        replace_word(token, new_word);
	    return (SUCCESS);
	}
	else
		return (SUCCESS);
}