/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:16:52 by msavelie          #+#    #+#             */
/*   Updated: 2024/08/08 18:04:22 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	count_nums(char **strs)
{
	int	i;

	if (!strs || !(*strs))
		return (-1);
	i = 0;
	while (strs[i])
		i++;
	return (i);
}

/*static int	**create_num_arr(t_map *map)
{
	int	**arr;

	arr = (int **)malloc(sizeof(int *) * map->lines);
	if (!arr)
		return (NULL);
	*arr = NULL;
	return (arr);
}*/

static char	*choose_base(char *color)
{
	int	i;

	i = 'a';
	while (i <= 'z')
	{
		if (ft_strchr(color, i))
			return (LOW_HEX_BASE);
		i++;
	}
	return (UP_HEX_BASE);
	
}

//static int *alloc_and_convert(char **strs, int num_count)
static t_point *alloc_and_convert(char **strs, int num_count, t_point *point)
{
	//int	*sub_arr;
	int	i;
	char	**num_color;

	/*sub_arr = malloc(sizeof(int) * num_count);
	if (!sub_arr)
		return (NULL);*/
	i = 0;
	while (i < num_count)
	{
		//sub_arr[i] = ft_atoi(strs[i]);
		if (ft_strchr(strs[i], ','))
		{
			num_color = ft_split(strs[i], ',');
			point->z = ft_atoi(num_color[0]);
			point->color = (int)ft_atoi_base(num_color[1], choose_base(num_color[1]));
			ft_free_strs(num_color, 2);
		}
		else
		{
			point->z = ft_atoi(strs[i]);
			point->color = 0xFFFFFF;
		}
		//ft_printf("num[%d] = %d\n", i, point[i].z);
		i++;
		point++;
	}
	return (point);
}

//int	**convert_map(t_map *map, t_point *point)
t_point	*convert_map(t_map *map, t_point *point)
{
	char	**strs;
	//int		**arr;
	int		i;
	t_point	*temp;

	i = 0;
	temp = point;
	//arr = create_num_arr(map);
	strs = ft_split(map->strs[i], ' ');
	//map->nums_in_line = count_nums(strs);
	while (map->strs[i])
	{
		if (count_nums(strs) != map->nums_in_line)
		{
			ft_free_strs(strs, count_nums(&strs[i]));
			//free_arr(arr, i);
			exit (1);
		}
		//arr[i] = alloc_and_convert(strs, map->nums_in_line);
		point = alloc_and_convert(strs, map->nums_in_line, point);
		ft_free_strs(strs, map->nums_in_line);
		i++;
		//point++;
		if (map->strs[i])
			strs = ft_split(map->strs[i], ' ');
	}
	/*for (int j = 0; j < map->lines * map->nums_in_line; j++)
		ft_printf("num[%d] = %d\n", j, temp[j].z);*/
	ft_free_strs(map->strs, map->lines);
	return (temp);
}
