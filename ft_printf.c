/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:59:55 by dbouizem          #+#    #+#             */
/*   Updated: 2025/02/02 01:02:47 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	dispatch_format(char specifier, va_list ap, t_printf *data)
{
	if (data->err || !specifier)
		return ;
	if (specifier == 'c')
		handle_char(va_arg(ap, int), data);
	else if (specifier == 's')
		handle_string(va_arg(ap, char *), data);
	else if (specifier == 'p')
		handle_pointer(va_arg(ap, void *), data);
	else if (specifier == 'd' || specifier == 'i')
		handle_int(va_arg(ap, int), data);
	else if (specifier == 'u')
		handle_uint(va_arg(ap, unsigned int), data);
	else if (specifier == 'x')
		handle_hex(va_arg(ap, unsigned int), 0, data);
	else if (specifier == 'X')
		handle_hex(va_arg(ap, unsigned int), 1, data);
	else if (specifier == 'o')
		handle_oct(va_arg(ap, unsigned int), data);
	else if (specifier == '%')
		ft_print_char('%', data);
	else
	{
		ft_print_char('%', data);
		ft_print_char(specifier, data);
	}
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	t_printf	data;

	ft_memset(&data, 0, sizeof(t_printf));
	va_start(ap, format);
	while (*format && !data.err)
	{
		if (*format == '%')
		{
			format++;
			dispatch_format(*(format), ap, &data);
		}
		else
			ft_print_char(*format, &data);
		format++;
	}
	va_end(ap);
	if (data.err)
		return (-1);
	return (data.total);
}
