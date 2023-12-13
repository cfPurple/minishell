#include "minishell.h"

int parse_line(char *str)
{
    if (*str == '\0')
        return (ERROR);
    if (only_space(str) == 1)
		return (ERROR);
    if (check_open_quotes(str) == 0)
        return (ERROR);
    if (line_to_token(str))
        return (ERROR);
    return (SUCCESS);
}