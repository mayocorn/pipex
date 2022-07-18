/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapper_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 23:27:06 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/17 07:07:42 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrapper.h"

pid_t	wrapper_fork(void)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		exit_perror("pipex: fork");
	return (pid);
}
