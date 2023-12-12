#include "minishell.h"

int	quote_word_expander(t_token *cmd_line)
{
	char	**sep_word;

	sep_word = sep_quote_word(cmd_line->word);

}