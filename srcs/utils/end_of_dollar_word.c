#include "minishell.h"

int	end_of_dollar_word(char *str, int i)
{
	if (str[i] == '$')
	{
		i++;
		if (str[i] == '?')
			return (i + 1);
        else
        {
		    while (str[i] && (ft_isalpha(str[i]) || str[i] == '_'))
		    	i++;
        }
	}
	else
		while (str[i] && str[i] != '$')
			i++;
	return (i);
}