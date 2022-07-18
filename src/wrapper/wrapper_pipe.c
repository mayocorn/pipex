/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapper_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 23:37:41 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/17 07:07:34 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrapper.h"

void	wrapper_pipe(int pipefd[2])
{
	if (pipe(pipefd) < 0)
		exit_perror("pipex: pipe");
}
