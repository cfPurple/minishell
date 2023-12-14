#include "minishell.h"

int	check_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (i < (int)ft_strlen(str))
		return (0);
	return (1);
}
