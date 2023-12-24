/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:12:09 by rdias-ba          #+#    #+#             */
/*   Updated: 2023/12/15 17:20:55 by rdias-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	create_directory(void)
{
	static const char	pwd[5] = "PWD=\0";
	char				*wd;
	char				*tmp;

	wd = getcwd(NULL, 0);
	tmp = wd;
	wd = ft_strjoin(pwd, wd);
	free(tmp);
	add_to_env(wd);
	free(wd);
}

static void	replace_directory(void)
{
	static const char	old_pwd[9] = "OLDPWD=\0";
	static const char	cur_pwd[5] = "PWD=\0";
	char				*wd;
	char				*old_wd;
	char				*tmp;

	old_wd = find_value("PWD");
	wd = getcwd(NULL, 0);
	if (!wd)
		return (g_error = 127, (void)print_error_msg("getcwd fail\n"));
	tmp = wd;
	wd = ft_strjoin(cur_pwd, wd);
	free(tmp);
	old_wd = ft_strjoin(old_pwd, old_wd);
	del_from_env("OLDPWD");
	add_to_env(old_wd);
	free(old_wd);
	del_from_env("PWD");
	add_to_env(wd);
	free(wd);
}

static void	change_directory(void)
{
	char	*wd;

	wd = find_value("OLDPWD");
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
		replace_directory();
	}
}

static void	get_cd_path(char	**path)
{
	char	*cdpath;
	int		fd;

	cdpath = find_value("CDPATH");
	if (!cdpath)
		return ;
	if (cdpath[ft_strlen(cdpath)] == '/' || *cdpath == '/')
		cdpath = ft_strjoin(cdpath, *path);
	else
		cdpath = join_slash(cdpath, *path);
	free(*path);
	*path = cdpath;
	fd = open(*path, O_DIRECTORY);
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

/*
 * Check si le PWD existe dans l'env ou le créé
 * si le token - existe change le répertoir pour l'ancien et maj l'env
 * Sinon change de répertoir et maj l'env 
 */
int	exec_cd(t_token *token, int in, int out)
{
	char	wd;

	wd = '\0';
	g_error = 0;
	if (in != STDIN_FILENO || out != STDOUT_FILENO)
		return (true);
	if (!token || get_token_len(token) > 1)
		return (g_error = 1, print_error_msg(ERROR_ARG_CD), true);
	if (!find_value("PWD"))
		create_directory();
	if (ft_strcmp("-", token->word) == 0)
		change_directory();
	else
	{
		get_cd_path(&token->word);
		if (chdir(token->word) == -1)
		{
			g_error = 1;
			perror(&wd);
		}
		replace_directory();
	}
	return (true);
}
