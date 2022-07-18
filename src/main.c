/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 23:55:55 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/17 06:11:36 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, const char **argv)
{
	if (argc != 5)
	{
		print_usage();
		exit(EXIT_FAILURE);
	}
	return (pipex(argv));
}

static int	pipex(char **argv)
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
	return (WIFEXITED(last_status) && WEXITSTATUS(last_status));
}
