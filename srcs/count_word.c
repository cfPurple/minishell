#include "minishell.h"

int	count_word(char *str)
{
    int		i;
	int		j;
	int     state;

    i = 0;
	j = 1;
	state = open_quote(str, i);
	while (str[i])
	{
		if (open_quote(str, i) != state)
		{
			state = !state;
			j++;
		}
		i++;
	}
	return (j);
}