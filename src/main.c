/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 23:55:55 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/21 05:09:48 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	pipex(const char **argv);

int	main(int argc, const char **argv)
{
	if (argc != 5)
		exit_print_usage();
	return (pipex(argv));
}

static int	pipex(const char **argv)
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
		process_last_child(argv + 3, pipefd, O_WRONLY | O_CREAT | O_TRUNC);
	close(pipefd[0]);
	return (wait_child_process(pid));
}
