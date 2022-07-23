/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 01:36:47 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/24 02:53:20 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*read_heredoc(const char **argv)
{
	const char	*limiter;
	size_t		limiter_len;
	char		*res;
	char		*pre;
	char		*str;

	if (ft_strncmp(argv[1], "here_doc", 8) != 0)
		return (NULL);
	limiter = argv[2];
	res = wrapper_calloc(1, sizeof(char));
	limiter_len = ft_strlen(limiter);
	str = get_next_line(STDIN_FILENO);
	while (str != NULL)
	{
		if (ft_strlen(str) == limiter_len + 1 && \
				ft_strncmp(str, limiter, limiter_len) == 0)
			break;
		pre = res;
		res = wrapper_strjoin(res, str);
		free(str);
		free(pre);
		str = get_next_line(STDIN_FILENO);
	}
	free(str);
	return (res);
}
