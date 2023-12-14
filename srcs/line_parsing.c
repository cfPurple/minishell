#include "minishell.h"

int line_parsing(char *str)
{
    if (*str == '\0')
        return (ERROR);
    if (check_spaces(str) == 1)
		return (ERROR);
    if (check_quotes(str) == 0)
        return (ERROR);
    if (str_to_token(str))
        return (ERROR);
    return (SUCCESS);
}