#include "minishell.h"

int	quote_word_expander(t_token *token)
{
	char	**word_tab;

	word_tab = sep_quote_word(token->word);

}