#include "minishell.h"

int end_of_word(char *str ,int start)
{
    if (str[start] == 0)
		return (start);
	if (ft_strchr("<|>&", str[start]) != 0)
	{
		start++;
		if ((str[start - 1] != '|' && str[start - 1] != '&')
			&& (str[start] == '<' || str[start] == '>'))
			start ++;
		return (start);
	}
    while (str[start])
	{
		if (open_quote(str, start) == 0
			&& (str[start] == ' ' || ft_strchr("<|>&", str[start] != 0)))
			break ;
		start++;
	}
	return (start);
}