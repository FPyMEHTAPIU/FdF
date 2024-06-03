/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:19:52 by msavelie          #+#    #+#             */
/*   Updated: 2024/04/30 13:28:55 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	str_len;
	char	*ptr;

	str_len = ft_strlen(s1);
	ptr = ft_calloc(sizeof(char), str_len + 1);
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, s1, str_len + 1);
	return (ptr);
}
