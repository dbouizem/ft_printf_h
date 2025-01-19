/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:59:55 by dbouizem          #+#    #+#             */
/*   Updated: 2025/01/19 16:39:44 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	return (write(1, &c, 1));
}

int	ft_print_str(char *s)
{
	int	count;

	count = 0;
	while (*s)
	{
		ft_print_char((int)(*s));
		s++;
		count++;
	}
	return (count);
}

int	ft_print_digit(long n, int base, int uppercase)
{
	int		count;
	char	*symbole;

	if (base == 10)
		symbole = DIGITS;
	else if (base == 16)
	{
		if (uppercase)
			symbole = HEXAUPP;
		else
			symbole = HEXALOW;
	}
	else if (base == 8)
		symbole = OCTAL;
	else
		return (0);
	count = 0;
	if (n < 0 && base == 10)
	{
		write(1, "-", 1);
		count ++;
		n = -n;
	}
	if (n >= base)
		count += ft_print_digit((n / base), base, uppercase);
	count += ft_print_char(symbole[n % base]);
	return (count);
}

int	ft_print_pointer(void *p)
{
	int	count;

	count = 0;
	count += write(1, "0x", 2);
	if (p == 0)
		count += write(1, "0", 1);
	else
		count += ft_print_digit((unsigned long)(p), 16, 0);
	return (count);
}

int	ft_printf_format(char specifier, va_list ap)
{
	int	count;

	count = 0;
/*
** - Spécificateurs pour les caractères et les chaînes :
**		c, s
*/
	if (specifier == 'c')
		count += ft_print_char(va_arg(ap, int));
	else if (specifier == 's')
		count += ft_print_str(va_arg(ap, char *));
/*
** - Spécificateurs pour les entiers :
**		d, i, u, o, x, X => Bonus : o
*/
	else if (specifier == 'd' || specifier == 'i')
		count += ft_print_digit((long)va_arg(ap, int), 10, 0);
	else if (specifier == 'u')
		count += ft_print_digit((long)va_arg(ap, unsigned int), 10, 0);
	else if (specifier == 'x')
		count += ft_print_digit((long)va_arg(ap, unsigned int), 16, 0);
	else if (specifier == 'X')
		count += ft_print_digit((long)va_arg(ap, unsigned int), 16, 1);
//Bonus
	else if (specifier == 'o')
		count += ft_print_digit((long)va_arg(ap, unsigned int), 8, 0);
/*
** - Spécificateur pour les pointeurs :
**		p
*/
	else if (specifier == 'p')
		count += ft_print_pointer(va_arg(ap, void *));
/*
** - Spécificateur pour les valeurs spéciales (% symbol) :
**		%
*/
	else if (specifier == '%')
		count += ft_print_char('%');
/*
** - Spécificateurs pour les nombres flottants :
**		f, .nf, e, E, g, G => Bonus : tous
*/

/*
** - Modificateurs de taille spécifiques des spécificateurs :
**		h, l, ll, z => Bonus : tous
*/
	else
		return (-1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
			count += ft_printf_format(*(++format), ap);
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (count);
}
