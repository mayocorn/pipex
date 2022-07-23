/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_first_child_heredoc.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 09:11:29 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/24 02:15:43 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "child_process.h"

static int	create_tmp_infile(char *heredoc);
static void	exit_unlink(void);

void	process_first_child_heredoc(const char *cmd, char *heredoc, \
									int next_pipe[2])
{
	char	*path;
	int		fd;

	close(next_pipe[0]);
	wrapper_dup2(next_pipe[1], STDOUT_FILENO);
	close(next_pipe[1]);
	fd = create_tmp_infile(heredoc);
	free(heredoc);
	wrapper_dup2(fd, STDIN_FILENO);
	close(fd);
	path = search_path(cmd);
	wrapper_execve(path, cmd);
}

static int	create_tmp_infile(char *heredoc)
{
	int	tmp_fd;
	int	write_fd;
	int	read_fd;

	tmp_fd = wrapper_open_mode(TMP_FILE, \
								O_RDWR | O_CREAT | O_EXCL | O_CLOEXEC, 0600);
	write_fd = dup(tmp_fd);
	if (write_fd == -1)
		exit_unlink();
	ft_putstr_fd(heredoc, write_fd);
	close(write_fd);
	read_fd = open(TMP_FILE, O_RDONLY);
	if (read_fd == -1)
		exit_unlink();
	close(tmp_fd);
	unlink(TMP_FILE);
	return (read_fd);
}

static void	exit_unlink(void)
{
	unlink(TMP_FILE);
	exit_perror("pipex");
}
