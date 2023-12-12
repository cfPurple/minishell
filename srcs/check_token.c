#include "minishell.h"

int	check_token(t_type token, t_type last_token)
{
	if (last_token == HEREDOC && token != LIMITOR)
		return (FAILURE);
	else if ((last_token == R_OUT || last_token == APPEND) && token != FD)
		return (FAILURE);
	else if (token == PIPE && (last_token == PIPE || last_token == R_IN
			|| last_token == APPEND || last_token == HEREDOC))
		return (FAILURE);
	return (SUCCESS);
}