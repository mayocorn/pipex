/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stsunoda <stsunoda@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 05:31:19 by stsunoda          #+#    #+#             */
/*   Updated: 2022/01/20 04:42:42 by stsunoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	char	*res;

	res = NULL;
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		res = (char *)s;
	return (res);
}

size_t	ft_strlen(const char *s)
{
	size_t	res;

	res = 0;
	while (*(s++))
		res++;
	return (res);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*res;
	char	*res_head;

	len = ft_strlen(s1);
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (0);
	res_head = res;
	while (*s1)
		*(res++) = *(s1++);
	*res = 0;
	return (res_head);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	res;

	res = ft_strlen(src);
	if (!dstsize)
		return (res);
	while (--dstsize && *src)
		*(dest++) = *(src++);
	*dest = 0;
	return (res);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	s_size;
	size_t	res_size;

	if (!s)
		return (0);
	s_size = ft_strlen(s);
	if (s_size <= start)
		res_size = 0;
	else
		res_size = s_size - start;
	if (len < res_size)
		res_size = len;
	res = (char *)malloc((res_size + 1) * sizeof(char));
	if (!res)
		return (0);
	ft_strlcpy(res, s + start, res_size + 1);
	return (res);
}
