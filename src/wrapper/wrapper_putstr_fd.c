/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapper_putstr_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 04:36:49 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/22 04:39:47 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrapper.h"

void	wrapper_putstr_fd(char *s, int fd)
{
	ssize_t	res;

	if (s == NULL)
		return ;
	res = write(fd, s, ft_strlen(s));
	if (res < ft_strlen(s))
		exit_perror("pipex");
}
