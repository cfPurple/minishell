#include "minishell.h"

int	count_word(char *str)
{
	int		j;
	int		i;
	bool	quote_flag;

	j = 1;
	i = 0;
	quote_flag = open_quote(str, i);
	while (str[i])
	{
		if (open_quote(str, i) != quote_flag)
		{
			quote_flag = !quote_flag;
			j++;
		}
		i++;
	}
	return (j);
}