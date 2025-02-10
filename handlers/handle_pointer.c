/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:43:25 by dbouizem          #+#    #+#             */
/*   Updated: 2025/02/10 05:37:00 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	handle_pointer(void *p, t_printf *data)
{
	if (data->err)
		return ;
	if (p == NULL)
	{
		ft_print_string("(nil)", data);
		return ;
	}
	ft_print_string("0x", data);
	ft_print_hex((unsigned long)(p), 0, data);
}
