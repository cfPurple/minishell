#include "minishell.h"

int end_of_word(char *str ,int i)
{
    if (str[i] == 0)
		return (i);
	if (ft_strchr("<|>&", str[i]) != 0)
	{
		i++;
		if ((str[i - 1] != '|' && str[i - 1] != '&')
			&& (str[i] == '<' || str[i] == '>'))
			i ++;
		return (i);
	}
    while (str[start])
	{
		if (open_quote(str, i) == 0
			&& (str[i] == ' ' || ft_strchr("<|>&", str[i] != 0)))
			break ;
		i++;
	}
	return (i);
}