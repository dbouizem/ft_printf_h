/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_oct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 23:48:18 by dbouizem          #+#    #+#             */
/*   Updated: 2025/02/02 02:12:36 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_print_oct(unsigned long n, t_printf *data)
{
	const char	*base;
	int			i;
	char		buffer[23];

	if (data->err || n == 0)
	{
		ft_print_char('0', data);
		return ;
	}
	base = OCTAL;
	i = sizeof(buffer) - 1;
	buffer[i--] = '\0';
	while (n > 0 && i >= 0)
	{
		buffer[i--] = base[n % 8];
		n /= 8;
	}
	ft_print_string(&buffer[i + 1], data);
}

void	handle_oct(unsigned int n, t_printf *data)
{
	if (data->err)
		return ;
	ft_print_oct((unsigned long)n, data);
}
