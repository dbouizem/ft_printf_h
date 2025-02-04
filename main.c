/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouizem <djihane.bouizem@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:09:43 by dbouizem          #+#    #+#             */
/*   Updated: 2025/02/02 03:01:48 by dbouizem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	int	ret;

	// Test pour les caractères
	ret = ft_printf("Char: %c\n", 'A');
	printf("ft_printf returned: %d\n", ret);
	printf("------\n");

	// Test pour les chaînes
	ret = ft_printf("String: %s\n", "Testing my s specifier!");
	printf("ft_printf returned: %d\n", ret);
	printf("------\n");

	// Test pour les entiers signés (d et i)
	ret = ft_printf("Integer (d): %d\n", 42);
	printf("ft_printf returned: %d\n", ret);

	ret = ft_printf("Integer (i): %i\n", -42);
	printf("ft_printf returned: %d\n", ret);
	printf("------\n");

	// Test pour les entiers non signés (u)
	ret = ft_printf("Unsigned Integer (u): %u\n", 42);
	printf("ft_printf returned: %d\n", ret);
	printf("------\n");

	// Test pour les hexadécimaux (x et X)
	ret = ft_printf("Hexadecimal (x): %x\n", 255);
	printf("ft_printf returned: %d\n", ret);

	ret = ft_printf("Hexadecimal (X): %X\n", 255);
	printf("ft_printf returned: %d\n", ret);
	printf("------\n");

	// Test pour les octaux (o)
	ret = ft_printf("Octal (o): %o\n", 255);
	printf("ft_printf returned: %d\n", ret);
	printf("------\n");

	// Test pour les pointeurs (p)
	ret = ft_printf("Pointer (p): %p\n", (void *)&ret);
	printf("ft_printf returned: %d\n", ret);
	printf("------\n");

	// Test pour le caractère %
	ret = ft_printf("Percentage (%%): %%\n");
	printf("ft_printf returned: %d\n", ret);
	printf("------\n");

	// Test pour un cas avec un nombre élevé
	ret = ft_printf("Large number (d): %d\n", INT_MAX);
	printf("ft_printf returned: %d\n", ret);

	ret = ft_printf("Large number (d): %d\n", INT_MIN);
	printf("ft_printf returned: %d\n", ret);
	printf("------\n");

	// Test pour un cas avec un pointeur NULL
	ret = ft_printf("Pointer NULL (p): %p\n", NULL);
	printf("ft_printf returned: %d\n", ret);
	printf("------\n");

	// Test avec plusieurs spécificateurs dans une même chaîne
	ret = ft_printf("Test multiple: %d, %s, %x, %p, %%\n", 123, "Hello", 255, (void *)&ret);
	printf("ft_printf returned: %d\n", ret);
	printf("------\n");

	return (0);
}

