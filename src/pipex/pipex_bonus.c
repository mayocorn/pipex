/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 03:37:47 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/20 07:48:24 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void		create_first_child(const char **argv, int next_pipe[2]);
static void		create_middle_child(const char *cmd, int pre_pipe[2], int next_pipe[2]);
static pid_t	create_last_child(const char **argv, int pre_pipe[2]);

int	pipex_bonus(const int argc, const char **argv)
{
	int		pre_pipe[2];
	int		next_pipe[2];
	size_t	cmd_cnt;
	size_t	i;
	pid_t	last_pid;

	if (argc < 5)
		exit_print_usage_bonus();
	cmd_cnt = argc - 3;
	i = 0;
	last_pid = 0;
	while(i < cmd_cnt)
	{
		if (i == 0)
			create_first_child(argv + 1, next_pipe);
		else if (i == cmd_cnt - 1)
			last_pid = create_last_child(argv + argc - 2, pre_pipe);
		else
			create_middle_child(argv[i + 2], pre_pipe, next_pipe);
		swap_pipe(pre_pipe, next_pipe);
		i++;
	}
	return (wait_child_process(last_pid));
}

static void	create_first_child(const char **argv, int next_pipe[2])
{
	pid_t	pid;

	wrapper_pipe(next_pipe);
	pid = wrapper_fork();
	if (pid == 0)
		process_first_child(argv, next_pipe);
	close(next_pipe[1]);
}

static void	create_middle_child(const char *cmd, int pre_pipe[2], int next_pipe[2])
{
	pid_t	pid;

	wrapper_pipe(next_pipe);
	pid = wrapper_fork();
	if (pid == 0)
		process_middle_child(cmd, pre_pipe, next_pipe);
	close(pre_pipe[0]);
	close(next_pipe[1]);
}

static pid_t	create_last_child(const char **argv, int pre_pipe[2])
{
	pid_t	pid;

	pid = wrapper_fork();
	if (pid == 0)
		process_last_child(argv, pre_pipe);
	close(pre_pipe[0]);
	return (pid);
}
