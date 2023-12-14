#include "minishell.h"

void	replace_word(t_token *token, char *new_word)
{
	free(token->word);
	token->word = NULL;
	token->word = ft_strdup(new_word);
	free(new_word);
}