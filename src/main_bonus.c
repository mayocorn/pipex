/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 00:39:53 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/20 07:47:51 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, const char **argv)
{
	if (argc >= 2 && ft_strncmp(argv[1], "here_doc", 8) == 0)
		return (pipex_heredoc(argc, argv));
	else
		return (pipex_bonus(argc, argv));
}
