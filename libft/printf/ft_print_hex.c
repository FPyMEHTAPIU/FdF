/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:03:47 by msavelie          #+#    #+#             */
/*   Updated: 2024/06/18 19:33:29 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(long nbr, int base, char c)
{
	int		bytes;
	char	*base_content;

	if (c == 'X')
		base_content = UP_HEX_BASE;
	else
		base_content = LOW_HEX_BASE;
	if (nbr < 0)
	{
		if (write(1, "-", 1) < 0)
			return (-1);
		return (ft_print_hex((nbr * -1), base, c) + 1);
	}
	else if (nbr < base)
		return (ft_putchar(base_content[nbr]));
	else
	{
		bytes = ft_print_hex(nbr / base, base, c);
		if (bytes < 0)
			return (-1);
		return (bytes + ft_print_hex(nbr % base, base, c));
	}
}

int	print_p(unsigned long num)
{
	int		bytes;
	char	*base;

	base = LOW_HEX_BASE;
	bytes = 0;
	bytes += ft_putstr("0x");
	if (bytes < 0)
		return (-1);
	if (num < 16)
		return (bytes += ft_putchar(base[num]));
	bytes += ft_print_hex(num / 16, 16, 'x');
	return (bytes + ft_print_hex(num % 16, 16, 'x'));
}
