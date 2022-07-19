/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 23:55:55 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/20 03:37:02 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, const char **argv)
{
	if (argc != 5)
		exit_print_usage();
	return (pipex(argv));
}
