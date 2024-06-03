/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:36:50 by msavelie          #+#    #+#             */
/*   Updated: 2024/04/29 11:03:19 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n_size;

	n_size = ft_strlen(needle);
	if (n_size == 0 || needle == NULL)
		return ((char *) haystack);
	if (len <= 0)
		return (NULL);
	while (*haystack && len >= n_size)
	{
		if (*haystack == *needle && ft_strncmp(haystack, needle, n_size) == 0)
			return ((char *)(haystack));
		haystack++;
		len--;
	}
	return (NULL);
}
