/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:40:31 by msavelie          #+#    #+#             */
/*   Updated: 2024/04/22 16:38:43 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*str_end;

	i = ft_strlen(s);
	str_end = (char *) s;
	while (i > 0)
	{
		if (str_end[i] == (char) c)
			return (str_end + i);
		i--;
	}
	if (str_end[i] == (char) c)
		return (str_end);
	return (NULL);
}
