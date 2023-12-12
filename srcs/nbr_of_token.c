#include "minishell.h"

int nbr_of_token(char *str)
{
    int i;
    int	nbr;
    int start;
	int	end;

	i = 0;
    nbr = 0;
	start = 0;
    end = 0;
	while (str[i])
	{
		start = start_of_word(str, i);
		end = end_of_word(str, start);
		i = end;
		nbr++;
	}
	return (nbr);
}