/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapper_dup2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 02:46:27 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/21 07:09:34 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrapper.h"

int	wrapper_dup2(int oldfd, int newfd)
{
	if (dup2(oldfd, newfd) == -1)
		exit_perror("pipex: dup2");
	return (newfd);
}
