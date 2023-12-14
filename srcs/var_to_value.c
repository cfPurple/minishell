#include "minishell.h"

char	*var_to_value(char *str)
{
	char	*new_str;

	if (ft_strlen(str) == 2 && str[1] == '?')
    {
		new_str = ft_itoa(g_error);
        return (new_str);
    }
	else
		new_str = var_to_env_value(str);
	return (new_str);
}
