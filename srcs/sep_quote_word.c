#include "minishell.h"

char	**sep_quote_word(char *str)
{
    char	**sep_str;

	if (str[0] == '$' && (str[1] == '\'' || str[1] == '\"'))
		str ++;

	return (sep_str);
}