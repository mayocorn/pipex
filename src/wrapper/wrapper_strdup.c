/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapper_strdup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 19:22:29 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/22 07:29:41 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrapper.h"

char	*wrapper_strdup(const char *s)
{
	char	*res;

	res = ft_strdup(s);
	if (res == NULL)
		exit(EXIT_FAILURE);
	return (res);
}
