/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:47:58 by msavelie          #+#    #+#             */
/*   Updated: 2024/08/08 17:25:10 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen_gnl(const char *s)
{
	int	size;

	if (!s)
		return (0);
	size = 0;
	while (s[size] != '\0')
		size++;
	return (size);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	while (*s && *s != (unsigned char)c)
		s++;
	if (*s == 0 && (unsigned char)c != 0)
		return (NULL);
	return ((char *)s);
}

void	*ft_memmove_gnl(void *dst, const void *src, size_t len)
{
	char	*temp;

	if ((!dst && !src) && len != 0)
		return (NULL);
	temp = dst;
	if (dst <= src)
		while (len--)
			*temp++ = *(char *)src++;
	else
	{
		temp += len;
		src += len;
		while (len--)
			*(--temp) = *(char *)(--src);
	}
	return (dst);
}
