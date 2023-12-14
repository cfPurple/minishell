#include "minishell.h"

t_token	*free_all_token(t_token **token)
{
	t_token	*tmp;

	while ((*token))
	{
		tmp = (*token);
		free((*token)->word);
		(*token) = (*token)->next;
		free(tmp);
	}
	token = NULL;
	return (NULL);
}