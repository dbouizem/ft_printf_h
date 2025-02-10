/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 19:16:04 by dbouizem          #+#    #+#             */
/*   Updated: 2025/02/10 05:50:19 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>//Test
# include <limits.h>//Test

/*
** MACROS
*/
# define DIGITS		"0123456789"
# define HEXALOW	"0123456789abcdef"
# define HEXAUPP	"0123456789ABCDEF"
# define OCTAL		"01234567"

/*
** STRUCTURS
*/
/*Print struct*/
typedef struct s_printf
{
	int	total;
	int	err;
}	t_printf;

/*
** FUNCTIONS
*/

int		ft_printf(const char *format, ...);
int		main(void);//Test
/*Handles*/
void	handle_char(char c, t_printf *data);
void	handle_string(char *s, t_printf *data);
void	handle_pointer(void *p, t_printf *data);
void	handle_int(int n, t_printf *data);
void	handle_uint(unsigned int n, t_printf *data);
void	handle_hex(unsigned long n, int uppercase, t_printf *data);
void	handle_oct(unsigned int n, t_printf *data);
/*Utilitaires*/
void	ft_print_char(char c, t_printf *data);
void	ft_print_string(char *s, t_printf *data);
void	ft_print_hex(unsigned long n, int uppercase, t_printf *data);

#endif
