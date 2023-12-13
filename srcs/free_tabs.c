#include "minishell.h"

void	free_tabs(char **tab1, char **tab2)
{
	if (tab1)
		free_tab(tab1);
	if (tab2)
		free_tab(tab2);
}