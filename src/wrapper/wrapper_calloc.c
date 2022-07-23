/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapper_calloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 02:53:33 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/24 03:12:09 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrapper.h"

void	*wrapper_calloc(size_t count, size_t size)
{
	void	*res;

	res = ft_calloc(count, size);
	if (res == NULL)
		exit_perror("pipex: calloc");
	return (res);
}
