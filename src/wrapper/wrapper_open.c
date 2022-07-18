/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapper_open.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 06:37:28 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/19 01:47:54 by mayocorn         ###   ########.fr       */
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
