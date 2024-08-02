/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:53:35 by msavelie          #+#    #+#             */
/*   Updated: 2024/08/02 15:34:45 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./MLX42/include/MLX42/MLX42.h"
# include "./libft/libft.h"
# include <fcntl.h>

# ifndef MAP_LINES
#  define MAP_LINES 10
# endif

/*--------------------STRUCTS--------------------*/

typedef struct	s_map
{
	char	**strs;
	int		alloc_lines;
	int		lines;
}	t_map;

/*--------------------MAP HANDLING--------------------*/

t_map	*free_map(t_map *map);
t_map	*parse_map(int fd);
int		check_map(t_map *map);

void	free_arr(int **arr, int index);
int		**convert_map(t_map *map);
void	map_to_mlx(void);

#endif