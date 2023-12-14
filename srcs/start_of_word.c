#include "minishell.h"

int start_of_word(char *str ,int i)
{
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	return (i);
}