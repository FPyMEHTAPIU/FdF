/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:56:41 by msavelie          #+#    #+#             */
/*   Updated: 2024/04/18 14:49:20 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	str_len;

	i = 0;
	str_len = ft_strlen(s);
	while (i < str_len)
	{
		if ((char) c == s[i])
		{
			return ((char *) &s[i]);
		}
		i++;
	}
	if (s[i] == '\0' && (char) c == '\0')
		return ((char *) &s[i]);
	return (NULL);
}
