/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 01:56:34 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/19 04:26:53 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHILD_PROCESS_H
# define CHILD_PROCESS_H
# include <unistd.h>
# include "utils.h"
# include "wrapper.h"

void	process_child_1(const char **argv, int pipefd[2]);
void	process_child_2(const char **argv, int pipefd[2]);
#endif