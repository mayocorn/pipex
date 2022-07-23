/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 01:20:59 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/24 02:40:40 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include "get_next_line.h"
# include "wrapper.h"

void	exit_print_usage(void);
void	exit_print_usage_bonus(void);
void	exit_print_usage_heredoc(void);
void	exit_perror(const char *message);
void	exit_command_not_found(char *cmd_name);
char	*read_heredoc(const char **argv);
char	*search_path(const char *cmd);
void	swap_pipe(int pre_pipe[2], int next_pipe[2]);
char	*find_cmd_fullpath(char *pathenv, char *cmd_name);
void	swap_pipe(int pre_pipe[2], int next_pipe[2]);
int		wait_child_process(pid_t last_pid);

#endif
