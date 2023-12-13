#include "minishell.h"

int	open_quote(char *str, int start)
{
	int	i;
	int simple_q;
	int double_q;

	i = 0;
	simple_q = 0;
	double_q = 0;
	while (i < start)
	{
		if (str[i] == '\'' && str[i + 1] != '\'' && double_q == 0)
			simple_q = !simple_q;
		else if (str[i] == '\'' && str[i + 1] == '\'' && simple_q == 0)
			double_q = !double_q;
		else if (str[i] == '\"' && simple_q == 0)
			double_q = !double_q;
		i++;
	}
	return (simple_q || double_q);
}