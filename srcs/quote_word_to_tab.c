#include "minishell.h"

char	**quote_word_to_tab(char *str)
{
    char	**sep_str;

	if (str[0] == '$' && (str[1] == '\'' || str[1] == '\"'))
		str ++;

	return (sep_str);
}