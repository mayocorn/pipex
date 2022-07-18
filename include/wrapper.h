/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapper.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 23:29:33 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/19 02:30:54 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRAPPER_H
# define WRAPPER_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include "utils.h"

int		wrapper_dup2(int oldfd, int newfd);
void	wrapper_execve(const char *path, const char *args);
pid_t	wrapper_fork(void);
int		wrapper_open(const char *path, int oflag);
void	wrapper_pipe(int pipefd[2]);
char	**wrapper_split(char const *s, char c);
void	free_split(char **buf);
char	*wrapper_strdup(const char *s);
char	*wrapper_strjoin(char const *s1, char const *s2);
#endif
