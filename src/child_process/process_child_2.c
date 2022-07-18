/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_child_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 02:39:20 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/19 03:17:27 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "child_process.h"

void	process_child_2(char **argv, int pipefd[2])
{
	char		*path;
	const char	*outfile_name;
	int			outfile_fd;

	wrapper_dup2(pipefd[0], STDIN_FILENO);
	close(pipefd[0]);
	path = search_path(argv[3]);
	outfile_name = argv[4];
	outfile_fd = wrapper_open_mpde(outfile_name, \
									O_WRONLY | O_CREAT | O_TRUNC, 0666);
	wrapper_dup2(outfile_fd, STDOUT_FILENO);
	close(outfile_fd);
	wrapper_execve(path, argv[3]);
}
