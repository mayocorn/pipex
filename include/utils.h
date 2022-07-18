/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 01:20:59 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/19 02:35:06 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include "wrapper.h"

void	print_usage(char *prg);
void	exit_perror(const char *message);
void	exit_command_not_found(char *cmd_name);
char	*search_path(const char *cmd);
char	*find_cmd_fullpath(const char *pathenv, const char *cmd_name);
#endif
