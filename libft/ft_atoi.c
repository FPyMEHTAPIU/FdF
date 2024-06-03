/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:00:25 by msavelie          #+#    #+#             */
/*   Updated: 2024/04/30 13:37:32 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int			sign;
	long long	num;
	long long	check;

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
	while ((*str >= '0' && *str <= '9') && *str)
	{
		check = num * 10 + *str - '0';
		if (check / 10 != num && sign == 1)
			return (-1);
		if (check / 10 != num && sign == -1)
			return (0);
		num = check;
		str++;
	}
	return ((int)(num * sign));
}
