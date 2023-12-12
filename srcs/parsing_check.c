#include "minishell.h"

int	parsing_check(t_token *token)
{
	t_token	*last_token;
	t_type	last_token_t;

	last_token_t = -1;
	while (token)
	{
		if (check_token(token->type, last_token_t) == ERROR)
			return (print_pars_err(token->word), ERROR);
        last_token = token;
		last_token_t = token->type;
		token = token->next;
	}
	if (last_token_t == R_IN || last_token_t == R_OUT || last_token_t == APPEND
        || last_token_t == HEREDOC || last_token_t == PIPE)
		return (print_pars_err(token->word), ERROR);
	return (SUCCESS);
}