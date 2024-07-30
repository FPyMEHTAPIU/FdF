/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:48:10 by msavelie          #+#    #+#             */
/*   Updated: 2024/06/18 15:16:27 by msavelie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_next_char(char sym, va_list ptr)
{
	int		len;

	len = 0;
	if (sym == 'c')
		len += ft_putchar(va_arg(ptr, int));
	else if (sym == 's')
		len += ft_putstr(va_arg(ptr, char *));
	else if (sym == 'p')
		len += print_p((unsigned long)(va_arg(ptr, void *)));
	else if (sym == 'd' || sym == 'i')
		len += ft_print_hex((long) va_arg(ptr, int), 10, sym);
	else if (sym == 'u')
		len += ft_print_hex((unsigned long) va_arg(ptr, unsigned int), 10, sym);
	else if (sym == 'x' || sym == 'X')
		len += ft_print_hex((long) va_arg(ptr, unsigned int), 16, sym);
	else
		len += write(1, &sym, 1);
	return (len);
}

int	ft_printf(const char *data, ...)
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
			len = check_next_char(*(++data), ptr);
		else if ((' ' >= *data || *data <= '~')
			|| ('\t' >= *data || *data <= '\r'))
			len = write(1, data, 1);
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
