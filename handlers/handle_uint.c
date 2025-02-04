/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_uint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:45:56 by dbouizem          #+#    #+#             */
/*   Updated: 2025/02/02 01:23:32 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_print_uint(unsigned long n, t_printf *data)
{
	int			i;
	const char	*base;
	char		buffer[20];

	i = sizeof(buffer) - 1;
	buffer[i--] = '\0';
	base = DIGITS;
	if (data->err)
		return ;
	if (n == 0)
		return (ft_print_char('0', data));
	while (n > 0)
	{
		buffer[i--] = base[n % 10];
		n /= 10;
	}
	ft_print_string(&buffer[i + 1], data);
}

void	handle_uint(unsigned int n, t_printf *data)
{
	if (data->err)
		return ;
	ft_print_uint((unsigned long)n, data);
}
