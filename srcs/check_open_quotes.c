#include "minishell.h"

int check_open_quotes(char *str)
{
    int i;
    int squote;
    int dquote;

    i = 0;
	squote = 0;
	dquote = 0;
    if (!str)
        return (0);
	while (str[i])
	{
		if (str[i] == '\'' && dquote == 0)
			squote = !squote;
		else if (str[i] == '\"' && squote == 0)
			dquote = !dquote;
        i++;
	}
    //printf("%d\n", squote);
    //printf("%d\n", dquote);
    if (squote || dquote)
        return (0);
    else
	    return (1);
}