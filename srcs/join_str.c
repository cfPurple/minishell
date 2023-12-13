#include "minishell.h"

char	*join_str(char **str)
{
	int		i;
	char	*final_str;

	i = -1;
	final_str = ft_calloc(1, sizeof(char));
	if (!final_str)
		return (NULL);
	while (str[++i])
	{
		final_str = join_str2(final_str, str[i], final_str);
		if (!final_str)
			return (NULL);
	}
	return (final_str);
}
