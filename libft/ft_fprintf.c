/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:24:59 by msavelie          #+#    #+#             */
/*   Updated: 2024/07/15 18:14:53 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_next_char(char sym, va_list ptr, int fd)
{
	int		len;

	len = 0;
	if (sym == 'c')
		len += ft_putchar_fd(va_arg(ptr, int), fd);
	else if (sym == 's')
		len += ft_putstr_fd(va_arg(ptr, char *), fd);
	else if (sym == 'p')
		len += fprint_p((unsigned long)(va_arg(ptr, void *)), fd);
	else if (sym == 'd' || sym == 'i')
		len += ft_fprint_hex((long) va_arg(ptr, int), 10, sym, fd);
	else if (sym == 'u')
		len += ft_fprint_hex((unsigned long) va_arg(ptr, unsigned int),
				10, sym, fd);
	else if (sym == 'x' || sym == 'X')
		len += ft_fprint_hex((long) va_arg(ptr, unsigned int), 16, sym, fd);
	else
		len += write(fd, &sym, 1);
	return (len);
}

int	ft_fprintf(int fd, const char *data, ...)
{
	va_list	ptr;
	int		bytes;
	int		len;

	bytes = 0;
	len = 0;
	va_start(ptr, data);
	while (*data != '\0')
	{
		if (*data == '%')
			len = check_next_char(*(++data), ptr, fd);
		else if ((' ' >= *data || *data <= '~')
			|| ('\t' >= *data || *data <= '\r'))
			len = write(fd, data, 1);
		else
			bytes++;
		if (len < 0)
			return (-1);
		bytes += len;
		data++;
	}
	va_end(ptr);
	return (bytes);
}
