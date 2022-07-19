/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_usage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:48:42 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/20 01:18:24 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	exit_print_usage(void)
{
	ft_putstr_fd("pipex: invalid arguments\n", STDERR_FILENO);
	ft_putstr_fd("Usage: ./pipex file1 cmd1 cmd2 file2\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	exit_print_usage_bonus(void)
{
	ft_putstr_fd("pipex: invalid arguments\n", STDERR_FILENO);
	ft_putstr_fd("Usage: ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	exit_print_usage_heredoc(void)
{
	ft_putstr_fd("pipex: invalid arguments\n", STDERR_FILENO);
	ft_putstr_fd("Usage: ./pipex here_doc LIMITTER cmd cmd file\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}
