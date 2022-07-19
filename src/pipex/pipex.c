/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 03:36:05 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/20 05:52:30 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipex(const char **argv)
{
	int		pipefd[2];
	pid_t	pid;

	wrapper_pipe(pipefd);
	pid = wrapper_fork();
	if (pid == 0)
		process_first_child(argv + 1, pipefd);
	close(pipefd[1]);
	pid = wrapper_fork();
	if (pid == 0)
		process_last_child(argv + 3, pipefd);
	close(pipefd[0]);
	return(wait_child_process(pid));
}
