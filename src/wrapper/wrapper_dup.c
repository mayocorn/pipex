/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapper_dup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 07:07:48 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/21 07:09:25 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrapper.h"

int	wrapper_dup(int oldfd)
{
	int	newfd;

	newfd = dup(oldfd);
	if (newfd == -1)
		exit_perror("pipex: dup");
	return (newfd);
}
