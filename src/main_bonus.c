/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 00:39:53 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/24 02:28:48 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int		pipex(const int argc, const char **argv);
static void		create_first_child(const char **argv, \
									int pre_pipe[2], int next_pipe[2]);
static void		create_middle_child(const char *cmd, \
									int pre_pipe[2], int next_pipe[2]);
static pid_t	create_last_child(const int argc, const char **argv, \
									int pre_pipe[2]);

int	main(const int argc, const char **argv)
{
	if (argc >= 2 && ft_strncmp(argv[1], "here_doc", 8) == 0 && argc < 6)
		exit_print_usage_heredoc();
	if (argc < 5)
		exit_print_usage_bonus();
	return (pipex(argc, argv));
}

static int	pipex(const int argc, const char **argv)
{
	int		pre_pipe[2];
	int		next_pipe[2];
	pid_t	pid;
	int		i;

	create_first_child(argv, pre_pipe, next_pipe);
	i = 3;
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		i++;
	while (i < argc - 2)
	{
		create_middle_child(argv[i], pre_pipe, next_pipe);
		i++;
	}
	pid = create_last_child(argc, argv, pre_pipe);
	return (wait_child_process(pid));
}

static void	create_first_child(const char **argv, \
									int pre_pipe[2], int next_pipe[2])
{
	char	*heredoc;
	pid_t	pid;

	wrapper_pipe(next_pipe);
	heredoc = read_heredoc(argv);
	pid = wrapper_fork();
	if (pid == 0)
	{
		if (heredoc != NULL)
			process_first_child_heredoc(argv[3], heredoc, next_pipe);
		else
			process_first_child(argv[2], argv[1], next_pipe);
	}
	free(heredoc);
	close(next_pipe[1]);
	swap_pipe(pre_pipe, next_pipe);
}

static void	create_middle_child(const char *cmd, \
									int pre_pipe[2], int next_pipe[2])
{
	pid_t	pid;

	wrapper_pipe(next_pipe);
	pid = wrapper_fork();
	if (pid == 0)
		process_middle_child(cmd, pre_pipe, next_pipe);
	close(pre_pipe[0]);
	close(next_pipe[1]);
	swap_pipe(pre_pipe, next_pipe);
}

static pid_t	create_last_child(const int argc, \
									const char **argv, int pre_pipe[2])
{
	int		oflag;
	pid_t	pid;

	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		oflag = O_WRONLY | O_CREAT | O_APPEND;
	else
		oflag = O_WRONLY | O_CREAT | O_TRUNC;
	pid = wrapper_fork();
	if (pid == 0)
		process_last_child(argv[argc - 2], argv[argc - 1], oflag, pre_pipe);
	close(pre_pipe[0]);
	return (pid);
}
