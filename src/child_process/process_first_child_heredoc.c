/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_first_child_heredoc.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 09:11:29 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/22 08:46:33 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "child_process.h"

static int	create_tmp_infile(const char *limiter);
static void	read_heredoc(int fd, const char *limiter);
static void	exit_unlink(void);

void	process_first_child_heredoc(const char *cmd, const char *limiter, \
									int next_pipe[2])
{
	char	*path;
	int		fd;

	close(next_pipe[0]);
	wrapper_dup2(next_pipe[1], STDOUT_FILENO);
	close(next_pipe[1]);
	fd = create_tmp_infile(limiter);
	wrapper_dup2(fd, STDIN_FILENO);
	close(fd);
	path = search_path(cmd);
	wrapper_execve(path, cmd);
}

static int	create_tmp_infile(const char *limiter)
{
	int	tmp_fd;
	int	write_fd;
	int	read_fd;

	tmp_fd = wrapper_open_mode(TMP_FILE, \
								O_RDWR | O_CREAT | O_EXCL | O_CLOEXEC, 0600);
	write_fd = dup(tmp_fd);
	if (write_fd == -1)
		exit_unlink();
	read_heredoc(write_fd, limiter);
	close(write_fd);
	read_fd = open(TMP_FILE, O_RDONLY);
	if (read_fd == -1)
		exit_unlink();
	close(tmp_fd);
	unlink(TMP_FILE);
	return (read_fd);
}

static void	read_heredoc(int fd, const char *limiter)
{
	char	*str;
	size_t	len;

	len = ft_strlen(limiter);
	str = get_next_line(STDIN_FILENO);
	while (str != NULL)
	{
		if (ft_strlen(str) == len + 1 && ft_strncmp(str, limiter, len) == 0)
		{
			free(str);
			return ;
		}
		ft_putstr_fd(str, fd);
		free(str);
		str = get_next_line(STDIN_FILENO);
	}
}

static void	exit_unlink(void)
{
	unlink(TMP_FILE);
	exit_perror("pipex");
}
