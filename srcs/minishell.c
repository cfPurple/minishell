#include "minishell.h"

void minishell(int ac, char **av, char **env)
{
    (void)ac;
    (void)av;
    (void)env;
    //init_env(ac, av, env);
    //init_signal(0);

    if (display_and_read() != SUCCESS)
    {
        ft_putstr_fd(ERROR_STOP, 2);
        //free_all_env(*get_env(0, 0, 0));
        clear_history();
        printf("Minishell stopped with an error\n");
        exit(1);
    }

    //free_all_env(*get_env(0, 0, 0));
    clear_history();
    printf("Minishell stopped normally\n");
    exit(0);
}