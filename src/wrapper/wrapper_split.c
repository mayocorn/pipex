/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapper_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 19:18:12 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/18 20:24:22 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrapper.h"

char	**wrapper_split(char const *s, char c)
{
	char	**res;

	res = ft_split(s, c);
	if (res == NULL)
		exit_perror("pipex");
	return (res);
}

void	free_split(char **buf)
{
	char	**head;

	head = buf;
	while (*buf != NULL)
	{
		free(*buf);
		buf++;
	}
	free(head);
}
