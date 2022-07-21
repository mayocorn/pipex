/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 01:58:25 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/22 07:37:15 by mayocorn         ###   ########.fr       */
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

	while (*environ != NULL)
	{
		if (ft_strncmp("PATH=", *environ, 5) == 0 && ft_strlen(*environ) > 5)
			return (*environ + 5);
		environ++;
	}
	return (NULL);
}
