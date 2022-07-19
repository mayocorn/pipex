/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_last_child.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 02:39:20 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/20 06:17:15 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "child_process.h"

void	process_last_child(const char **argv, int pipefd[2])
{
	const char	*outfile_name;
	const char	*cmd;
	char		*path;
	int			outfile_fd;

	wrapper_dup2(pipefd[0], STDIN_FILENO);
	close(pipefd[0]);
	outfile_name = argv[1];
	cmd = argv[0];
	path = search_path(cmd);
	outfile_fd = wrapper_open_mode(outfile_name, \
									O_WRONLY | O_CREAT | O_TRUNC, 0666);
	wrapper_dup2(outfile_fd, STDOUT_FILENO);
	close(outfile_fd);
	wrapper_execve(path, cmd);
}
