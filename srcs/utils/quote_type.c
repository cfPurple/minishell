#include "minishell.h"

int	quote_type(char c)
{
	if (c == '\'')
		return (SQUOTE);
	else if (c == '\"')
		return (DQUOTE);
	else
		return (NOQUOTE);
}
