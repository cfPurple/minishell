#include "minishell.h"

int	count_dollar_word(char *str)
{
	int			i;
	int			nbr;
	int			in_dollarw;

	i = 0;
	nbr = 0;
    in_dollarw = 0;
	if (str[i] != '$')
		nbr = 1;
	while (str[i])
	{
		if (str[i] == '$')
		{
			in_dollarw = 1;
			nbr++;
		}
		else if (in_dollarw == 1 && (ft_isalnum(str[i]) == 0 &&
            str[i] != '$' && str[i] != '_' && str[i] != '?'))
		{
			in_dollarw = 0;
			nbr++;
		}
		i++;
	}
	return (nbr);
}