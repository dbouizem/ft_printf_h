/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 00:29:44 by dbouizem          #+#    #+#             */
/*   Updated: 2025/02/02 01:22:58 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_print_int(long n, t_printf *data)
{
	int				i;
	const char		*base;
	char			buffer[20];
	unsigned long	num;

	i = sizeof(buffer) - 1;
	buffer[i--] = '\0';
	base = DIGITS;
	if (data->err)
		return ;
	if (n == 0)
		return (ft_print_char('0', data));
	if (n < 0)
	{
		ft_print_char('-', data);
		num = (unsigned long)(-n);
	}
	else
		num = (unsigned long)n;
	while (num > 0 && i >= 0)
	{
		buffer[i--] = base[num % 10];
		num /= 10;
	}
	ft_print_string(&buffer[i + 1], data);
}

void	handle_int(int n, t_printf *data)
{
	if (data->err)
		return ;
	ft_print_int((long)n, data);
}
