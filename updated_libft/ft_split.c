/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:27:49 by msavelie          #+#    #+#             */
/*   Updated: 2024/04/22 13:27:49 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_str_count(char const *s, char c)
{
	size_t	count;
	size_t	i;
	int		space;

	count = 0;
	i = 0;
	space = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && space == 0)
		{
			space = 1;
			count++;
		}
		else if (s[i] == c)
			space = 0;
		i++;
	}
	return (count);
}

static int	free_list(char **list, int index)
{
	while (index >= 0)
	{
		free(list[index]);
		list[index] = NULL;
		index--;
	}
	free(list);
	list = NULL;
	return (1);
}

static char	*make_str(char const *src, int start, int end)
{
	char	*str;

	str = ft_calloc(sizeof(char), end - start + 1);
	if (!str)
		return (NULL);
	ft_memcpy(str, src + start, end - start);
	str[end - start] = '\0';
	return (str);
}

static int	split_str(char const *s, char c, char **list, int count)
{
	int	i;
	int	j;
	int	position;

	i = 0;
	j = 0;
	position = -1;
	while (j < count)
	{
		if (s[i] != c && position < 0)
			position = i;
		else if ((s[i] == c || !s[i]) && position >= 0)
		{
			list[j] = make_str(s, position, i);
			if (!list[j])
			{
				free_list(list, j);
				return (1);
			}
			position = -1;
			j++;
		}
		i++;
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**string_list;
	int		i;
	int		str_count;

	str_count = ft_str_count(s, c);
	string_list = (char **)malloc(sizeof(char *) * (str_count + 1));
	if (!string_list)
		return (NULL);
	i = split_str(s, c, string_list, str_count);
	if (i == 1)
		return (NULL);
	string_list[str_count] = NULL;
	return (string_list);
}
