/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cmd_fullpath.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 00:07:36 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/19 02:36:19 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static char	*get_executable(const char **paths, const char *cmd_name);
static char	*connect_path_and_cmd(const char *dir, const char *cmd);

char	*find_cmd_fullpath(const char *pathenv, const char *cmd_name)
{
	char	**paths;
	char	*path;

	if (cmd_name[0] == ' ' || cmd_name[0] == '\0')
		exit_cmd_not_found(cmd_name);
	paths = wrapper_split(pathenv, ':');
	path = get_executable(paths, cmd_name);
	free(cmd_name);
	free_split(paths);
	return (path);
}

static char	*get_executable(const char **paths, const char *cmd_name)
{
	char	*path;
	char	*res;
	size_t	i;

	res = NULL;
	i = 0;
	while (paths[i] != NULL)
	{
		path = join_path_and_cmd(paths[i], cmd_name);
		if (access(path, X_OK) == 0)
			return (path);
		if (res == NULL && access(path, F_OK) == 0)
			res = path;
		else
			free(path);
		i++;
	}
	if (res == NULL)
		exit_command_not_found(cmd_name);
	return (res);
}

static char	*connect_path_and_cmd(const char *dir, const char *cmd)
{
	char	*path;

	if (dir[ft_strlen(dir) - 1] != '/')
	{
		dir = wrapper_strjoin(dir, "/");
		path = wrapper_strjoin(dir, cmd);
		free(dir);
	}
	else
		path = wrapper_strjoin(dir, cmd);
	return (path);
}
