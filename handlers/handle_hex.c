/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:41:53 by dbouizem          #+#    #+#             */
/*   Updated: 2025/02/02 01:22:32 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	handle_hex(unsigned long n, int uppercase, t_printf *data)
{
	if (data->err)
		return ;
	ft_print_hex((unsigned long)n, uppercase, data);
}
