/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_last_child.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 02:39:20 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/21 08:30:09 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "child_process.h"

void	process_last_child(const char *cmd, const char *outfile, \
							int oflag, int pre_pipe[2])
{
	char	*path;
	int		fd;

	wrapper_dup2(pre_pipe[0], STDIN_FILENO);
	close(pre_pipe[0]);
	path = search_path(cmd);
	fd = wrapper_open_mode(outfile, oflag, 0666);
	wrapper_dup2(fd, STDOUT_FILENO);
	close(fd);
	wrapper_execve(path, cmd);
}
