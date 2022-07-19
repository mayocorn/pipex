/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_child_process.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 04:58:33 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/20 05:13:47 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	wait_child_process(pid_t last_pid)
{
	pid_t	pid;
	int		status;
	int		last_status;

	last_status = 0;
	pid = wait(&status);
	while (pid != -1)
	{
		if (pid == last_pid)
			last_status = status;
		pid = wait(&status);
	}
	if (WIFEXITED(last_status) == 0)
		return (EXIT_FAILURE);
	return (WEXITSTATUS(last_status));
}
