/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:27:27 by msavelie          #+#    #+#             */
/*   Updated: 2024/04/22 15:12:09 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	put_char_to_str(char *str, size_t *index, char c)
{
	str[*index] = c;
	(*index)++;
}

static size_t	calculate_length(long num)
{
	size_t	i;

	i = 1;
	if (num < 0)
	{
		i++;
		num *= -1;
	}
	while (num >= 10)
	{
		i++;
		num /= 10;
	}
	return (i);
}

static size_t	put_number(long num, char *str, size_t *index)
{
	if (num < 0)
	{
		put_char_to_str(str, index, '-');
		num *= -1;
	}
	if (num >= 10)
	{
		put_number(num / 10, str, index);
		put_number(num % 10, str, index);
	}
	else
		put_char_to_str(str, index, num + '0');
	return (*index);
}

char	*ft_itoa(int n)
{
	long	num;
	char	*str;
	size_t	len;
	size_t	index;

	num = (long) n;
	index = 0;
	len = calculate_length(n);
	str = ft_calloc(sizeof(char), len + 1);
	if (!str)
		return (NULL);
	put_number(num, str, &index);
	str[index] = '\0';
	return (str);
}
