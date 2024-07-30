/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:00:25 by msavelie          #+#    #+#             */
/*   Updated: 2024/07/16 13:43:02 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_range(int num, int sign, const char *str)
{
	long long	check;

	while ((*str >= '0' && *str <= '9') && *str)
	{
		check = num * 10 + *str - '0';
		if ((check == -2147483648 || check == 2147483648) && sign == -1)
			return (-2147483648);
		if (check == 2147483647 && sign == 1)
			return (2147483647);
		if (check / 10 != num && sign == 1)
			return (-1);
		if (check / 10 != num && sign == -1)
			return (0);
		num = check;
		str++;
	}
	return ((num * sign));
}

int	ft_atoi(const char *str)
{
	int			sign;
	int			num;

	num = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	return (check_range(num, sign, str));
}
