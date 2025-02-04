/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:43:25 by dbouizem          #+#    #+#             */
/*   Updated: 2025/02/02 01:37:28 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	handle_pointer(void *p, t_printf *data)
{
	if (data->err)
		return ;
	ft_print_string("0x", data);
	if (p == NULL)
		ft_print_string("0", data);
	else
		ft_print_hex((unsigned long)(p), 0, data);
}
