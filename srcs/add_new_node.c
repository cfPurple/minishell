#include "minishell"

int	add_new_node(t_token *token, char *line)
{
	t_token	*new_node;

	new_node = create_new_node(line);
	if (!new_node)
		return (ERROR);
	token_add_back(&token, new_node);
	return (SUCCESS);
}
