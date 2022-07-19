/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_fist_child.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 02:35:04 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/20 06:14:15 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "child_process.h"

void	process_first_child(const char **argv, int pipefd[2])
{
	const char	*infile_name;
	const char	*cmd;
	char		*path;
	int			infile_fd;

	close(pipefd[0]);
	wrapper_dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[1]);
	infile_name = argv[0];
	cmd = argv[1];
	path = search_path(cmd);
	infile_fd = wrapper_open(infile_name, O_RDONLY);
	wrapper_dup2(infile_fd, STDIN_FILENO);
	close(infile_fd);
	wrapper_execve(path, cmd);
}
