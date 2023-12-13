#include "minishell.h"

char	*remove_quote(char *str)
{
	char	*new_str;
	int		i;
	int		j;

    i = 0;
	j = 0;
	new_str = ft_calloc(ft_strlen(str), sizeof(char));
	if (!new_str)
		return (NULL);
	while (str[i++] && i < (int)ft_strlen(str) - 1 
        && j < (int)ft_strlen(str) - 1)
	{
		if ((str[i] == '\'' || str[i] == '\"') 
            && quote_type(str[i]) == quote_type(str[0]))
			i++;
		new_str[j] = str[i];
		j++;
	}
	new_str[j] = '\0';
	return (new_str);
}