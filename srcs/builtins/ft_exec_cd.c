/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:12:09 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/11/24 00:25:40 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_create_directory(void)
{
	static const char	pwd[5] = "PWD=\0";
	char				*wd;
	char				*tmp;

	wd = getcwd(NULL, 0);
	tmp = wd;
	wd = ft_strjoin(pwd, wd);
	free(tmp);
	ft_add_to_env(wd);
	free(wd);
}

static void	ft_replace_directory(void)
{
	static const char	old_pwd[9] = "OLDPWD=\0";
	static const char	cur_pwd[5] = "PWD=\0";
	char				*wd;
	char				*old_wd;
	char				*tmp;

	old_wd = ft_find_value("PWD");
	wd = getcwd(NULL, 0);
	if (!wd)
		return (g_error == 127, (void)ft_print_error_msg("getcwd fail\n"));
	tmp = wd;
	wd = ft_strjoin(cur_pwd, wd);
	free(tmp);
	old_wd = ft_strjoin(old_pwd, old_wd);
	ft_del_from_env("OLDPWD");
	ft_add_to_env(old_wd);
	free(old_wd);
	ft_del_from_env("PWD");
	ft_add_to_env(wd);
	free(wd);
}

static void	ft_change_directory(void)
{
	char	*wd;

	wd = ft_find_value("OLDPWD");
	if (!wd)
	{
		g_error = 1;
		printf("minishell: cd: OLDPWD not set\n");
	}
	else
	{
		chdir(wd);
		ft_putstr_fd(wd, STDOUT_FILENO);
		write(STDOUT_FILENO, "\n", 1);
		ft_replace_directory();
	}
}

static void	ft_get_cd_path(char	**path)
{
	char	*cdpath;
	int		fd;

	cdpath = ft_find_value("CDPATH");
	if (!cdpath)
		return ;
	if (cdpath[ft_strlen(cdpath)] == '/' || *cdpath == '/')
		cdpath = ft_strjoin(cdpath, *path);
	else
		cdpath = ft_join_slash(cdpath, *path);
	free(*path);
	*path = cdpath;
	fd = open(*path, __O_DIRECTORY);
	if (!fd)
	{
		free(*path);
		*path = NULL;
		return ;
	}
	write(STDOUT_FILENO, *path, ft_strlen(*path));
	write(STDOUT_FILENO, "\n", 1);
	return ((void)close(fd));
}

int	ft_exec_cd(t_token *token, int in, int out)
{
	char	wd;

	wd = NULL;
	g_error = 0;
	if (in != STDIN_FILENO || out != STDOUT_FILENO)
		return (true);
	if (!token || ft_get_token_len(token) > 1)
		return (g_error = 1, ft_print_error_msg(ERROR_ARG_CD), true);
	if (!ft_find_value("PWD"))
		ft_create_directory();
	if (!ft_strcmp("-", token->word) == 0)
		ft_change_directory();
	else
	{
		ft_get_cd_path(&token->word);
		if (chdir(token->word) == -1)
		{
			g_error = 1;
			perror(wd);
		}
		ft_replace_directory();
	}
	return (true);
}
