#include "minishell.h"

void	token_add_back(t_token **lst, t_token *new)
{
	t_token	*token;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	token = ft_lstlast_token(*lst);
	token->next = new;
}
