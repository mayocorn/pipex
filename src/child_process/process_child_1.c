/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_child_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 02:35:04 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/19 01:46:26 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "child_process.h"

void	process_child_1(char **argv, int pipefd[2])
{
	char		*path;
	const char	*infile_name;
	int			infile_fd;

	close(pipefd[0]);
	wrapper_dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[1]);
	path = search_path(argv[2]);
	infile_name = argv[1];
	infile_fd = wrapper_open(infile_name, O_RDONLY);
	wrapper_dup2(infile_fd, STDIN_FILENO);
	close(infile_fd);
	wrapper_execve(path, argv[2]);
}
