#include "minishell.h"

int	start_of_qword(char *str, int i)
{
	while (str[i])
	{
		if (open_quote(str, i) == 1)
		{
			if (open_quote(str, i + 1) == 1)
				return (i + 1);
		}
		else if (str[i] != '\'' || str[i] != '\"')
			break ;
		i++;
	}
	return (i);
}