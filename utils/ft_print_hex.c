/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 22:33:36 by dbouizem          #+#    #+#             */
/*   Updated: 2025/02/02 01:23:49 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_print_hex(unsigned long n, int uppercase, t_printf *data)
{
	char	*base;
	char	buffer[20];
	int		i;

	if (uppercase)
		base = HEXAUPP;
	else
		base = HEXALOW;
	if (data->err)
		return ;
	i = sizeof(buffer) - 1;
	buffer[i--] = '\0';
	if (n == 0)
		buffer[i--] = '0';
	while (n > 0 && i >= 0)
	{
		buffer[i--] = base[n % 16];
		n /= 16;
	}
	ft_print_string(&buffer[i + 1], data);
}
