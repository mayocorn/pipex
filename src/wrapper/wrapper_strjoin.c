/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapper_strjoin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 02:13:23 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/19 04:43:42 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrapper.h"

char	*wrapper_strjoin(char const *s1, char const *s2)
{
	char	*res;

	res = ft_strjoin(s1, s2);
	if (res == NULL)
		exit_perror("pipex");
	return (res);
}
