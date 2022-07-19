/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_middle_child.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 06:28:56 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/20 06:37:40 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "child_process.h"

void	process_middle_child(const char *cmd, int pre_pipe[2], int next_pipe[2])
{
	char	*path;

	close(next_pipe[0]);
	wrapper_dup2(pre_pipe[0], STDIN_FILENO);
	close(pre_pipe[0]);
	wrapper_dup2(next_pipe[1], STDOUT_FILENO);
	close(next_pipe[1]);
	path = search_path(cmd);
	wrapper_execve(path, cmd);
}
