/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 01:58:25 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/24 12:49:49 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*get_cmdname(const char *cmd);
static char	*get_pathenv(void);

char	*search_path(const char *cmd)
{
	char	*path;
	char	*pathenv;

	path = get_cmdname(cmd);
	if (ft_strchr(path, '/') == NULL)
	{
		pathenv = get_pathenv();
		if (pathenv != NULL)
			path = find_cmd_fullpath(pathenv, path);
	}
	return (path);
}

static char	*get_cmdname(const char *cmd)
{
	char	*cmd_name;
	char	**split_cmd;

	split_cmd = wrapper_split(cmd, ' ');
	if (split_cmd[0] == NULL)
		cmd_name = wrapper_strdup(cmd);
	else
		cmd_name = wrapper_strdup(split_cmd[0]);
	free_split(split_cmd);
	return (cmd_name);
}

static char	*get_pathenv(void)
{
	extern char	**environ;
	size_t		i;

	i = 0;
	while (environ[i] != NULL)
	{
		if (ft_strncmp("PATH=", environ[i], 5) == 0 && ft_strlen(environ[i]) > 5)
			return (environ[i] + 5);
		i++;
	}
	return (NULL);
}
