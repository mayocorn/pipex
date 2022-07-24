/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 01:36:47 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/24 13:34:45 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static char	*create_heredoc_str(const char *limiter);

char	*read_heredoc(const char **argv)
{
	if (ft_strcmp(argv[1], "here_doc") != 0)
		return (NULL);
	return (create_heredoc_str(argv[2]));
}

static char	*create_heredoc_str(const char *limiter)
{
	size_t	limiter_len;
	char	*res;
	char	*pre_res;
	char	*str;

	limiter_len = ft_strlen(limiter);
	str = get_next_line(STDIN_FILENO);
	while (str != NULL)
	{
		if (ft_strlen(str) == limiter_len + 1 && \
				ft_strncmp(str, limiter, limiter_len) == 0)
			break ;
		pre_res = res;
		res = wrapper_strjoin(res, str);
		free(pre_res);
		free(str);
		str = get_next_line(STDIN_FILENO);
	}
	free(str);
	return (res);
}
