/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_last_child.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 02:39:20 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/21 05:17:11 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "child_process.h"

void	process_last_child(const char **argv, int pre_fd[2], int oflag)
{
	const char	*outfile_name;
	const char	*cmd;
	char		*path;
	int			outfile_fd;

	wrapper_dup2(pre_fd[0], STDIN_FILENO);
	close(pre_fd[0]);
	path = search_path(cmd);
	outfile_name = argv[1];
	outfile_fd = wrapper_open_mode(outfile_name, oflag, 0666);
	cmd = argv[0];
	wrapper_dup2(outfile_fd, STDOUT_FILENO);
	close(outfile_fd);
	wrapper_execve(path, cmd);
}
