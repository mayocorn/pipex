/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapper_open.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 06:37:28 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/19 03:11:41 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrapper.h"

int	wrapper_open(const char *path, int oflag)
{
	int	fd;

	fd = open(path, oflag);
	if (fd == -1)
		exit_perror(wrapper_strjoin("pipex: ", path));
	return (fd);
}

int	wrapper_open_mode(const char *path, int oflag, mode_t mode)
{
	int	fd;

	fd = open(path, oflag, mode);
	if (fd == -1)
		exit_perror(wrapper_strjoin("pipex: ", path));
	return (fd);
}
