/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:14:20 by dbouizem          #+#    #+#             */
/*   Updated: 2025/02/06 03:37:30 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_print_char(char c, t_printf *data)
{
	if (data->err)
		return ;
	if (write(1, &c, 1) == -1)
	{
		data->err = 1;
		return ;
	}
	data->total++;
}
