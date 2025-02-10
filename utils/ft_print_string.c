/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:20:07 by dbouizem          #+#    #+#             */
/*   Updated: 2025/02/09 06:53:00 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_print_string(char *s, t_printf *data)
{
	if (data->err || !s)
		return ;
	ft_putstr_fd(s, 1);
	data->total += ft_strlen(s);
}
