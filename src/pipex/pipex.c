/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 03:36:05 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/20 03:36:44 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipex(const char **argv)
{
	int		pipefd[2];
	pid_t	pid;
	pid_t	last_pid;
	int		status;
	int		last_status;

	wrapper_pipe(pipefd);
	pid = wrapper_fork();
	if (pid == 0)
		process_child_1(argv, pipefd);
	close(pipefd[1]);
	pid = wrapper_fork();
	if (pid == 0)
		process_child_2(argv, pipefd);
	close(pipefd[0]);
	last_pid = pid;
	last_status = EXIT_FAILURE;
	pid = wait(&status);
	while (pid != -1)
	{
		if (pid == last_pid)
			last_status = status;
		pid = wait(&status);
	}
	return (WEXITSTATUS(last_status));
}