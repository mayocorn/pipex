/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapper_execve.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 06:51:41 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/24 02:30:35 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrapper.h"

void	wrapper_execve(const char *path, const char *args)
{
	extern char	**environ;
	char		**argv;

	argv = wrapper_split(args, ' ');
	execve(path, argv, environ);
	exit_perror(wrapper_strjoin("pipex: ", path));
}
