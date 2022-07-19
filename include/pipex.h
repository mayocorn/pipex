/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 00:10:38 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/20 07:45:21 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include "child_process.h"
# include "utils.h"
# include "wrapper.h"

int	pipex(const char **argv);
int	pipex_bonus(const int argc, const char **argv);
int	pipex_heredoc(const int argc, const char **argv);

#endif
