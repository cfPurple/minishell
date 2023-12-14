#include "minishell.h"

char	*qvar_expander(char *str)
{
	char	*expanded_var;
    char	*no_q_exp_var;

	if (quote_type(str[0]) == SQUOTE)
    {
		return (ft_strtrim(str, "\'"));
    }
	expanded_var = var_expander(str);
	if (!expanded_var)
	    return (NULL);
	if (quote_type(str[0]) == DQUOTE)
	{
		no_q_exp_var = ft_strtrim(expanded_var, "\"");
        free(expanded_var);
		return (no_q_exp_var);
	}
	else
		return (expanded_var);
}