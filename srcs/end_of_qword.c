#include "minishell.h"

int	end_of_qword(char *str, int i)
{
    i++;
	while (str[i])
	{
		if (open_quote(str, i) == 1)
		{
			if (open_quote(str, i + 1) == 0)
				return (i + 1);
		}
		else if (str[i] == '\'' || str[i] == '\"')
			break ;
		i++;
	}
	return (i);
}