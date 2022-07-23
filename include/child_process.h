/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 01:56:34 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/24 02:19:08 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHILD_PROCESS_H
# define CHILD_PROCESS_H

# include <unistd.h>
# include "utils.h"
# include "wrapper.h"
# include "get_next_line.h"

# define TMP_FILE "/tmp/sh-thd.pipex"

void	process_first_child(const char *cmd, const char *infile, \
								int next_pipe[2]);
void	process_first_child_heredoc(const char *cmd, char *heredoc, \
								int next_pipe[2]);
void	process_middle_child(const char *cmd, \
								int pre_pipe[2], int next_pipe[2]);
void	process_last_child(const char *cmd, const char *outfile, \
								int oflag, int pre_pipe[2]);

#endif