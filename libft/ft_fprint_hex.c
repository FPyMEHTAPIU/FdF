/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprint_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:33:51 by msavelie          #+#    #+#             */
/*   Updated: 2024/07/15 18:15:01 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_fprint_hex(long nbr, int base, char c, int fd)
{
	int		bytes;
	char	*base_content;

	if (c == 'X')
		base_content = UP_HEX_BASE;
	else
		base_content = LOW_HEX_BASE;
	if (nbr < 0)
	{
		if (write(fd, "-", 1) < 0)
			return (-1);
		return (ft_fprint_hex((nbr * -1), base, c, fd) + 1);
	}
	else if (nbr < base)
		return (ft_putchar_fd(base_content[nbr], fd));
	else
	{
		bytes = ft_fprint_hex(nbr / base, base, c, fd);
		if (bytes < 0)
			return (-1);
		return (bytes + ft_fprint_hex(nbr % base, base, c, fd));
	}
}

int	fprint_p(unsigned long num, int fd)
{
	int		bytes;
	char	*base;

	base = LOW_HEX_BASE;
	bytes = 0;
	bytes += ft_putstr_fd("0x", fd);
	if (bytes < 0)
		return (-1);
	if (num < 16)
		return (bytes += ft_putchar_fd(base[num], fd));
	bytes += ft_fprint_hex(num / 16, 16, 'x', fd);
	return (bytes + ft_fprint_hex(num % 16, 16, 'x', fd));
}
