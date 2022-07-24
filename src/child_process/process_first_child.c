/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_first_child.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 02:35:04 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/24 03:19:21 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "child_process.h"

void	process_first_child(const char *cmd, const char *infile, \
								int next_pipe[2])
{
	char	*path;
	int		fd;

	close(next_pipe[0]);
	wrapper_dup2(next_pipe[1], STDOUT_FILENO);
	close(next_pipe[1]);
	fd = wrapper_open(infile, O_RDONLY);
	path = search_path(cmd);
	wrapper_dup2(fd, STDIN_FILENO);
	close(fd);
	wrapper_execve(path, cmd);
}
