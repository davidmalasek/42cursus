/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalasek <dmalasek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:41:12 by dmalasek          #+#    #+#             */
/*   Updated: 2024/10/03 11:47:30 by dmalasek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	process(const char *format, va_list args, int *count)
{
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'd' || *format == 'i')
				print_sint(args, count);
			else if (*format == 's')
				print_str(args, count);
			else if (*format == 'c')
				print_char(args, count);
			else if (*format == 'p')
				print_ptadd(args, count);
			else if (*format == 'u')
				print_uint(args, count);
			else if (*format == 'x')
				print_lhex(args, count);
			else if (*format == 'X')
				print_uhex(args, count);
			else if (*format == '%')
				ft_putchar_fd('%', 1, count);
			else
				print_invalid(format, count);
			format++;
		}
		else
			ft_putchar_fd(*format++, 1, count);
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	process(format, args, &count);
	va_end(args);
	return (count + 2);
}

#include <stdio.h>

// Prototype of your custom ft_printf function
int		ft_printf(const char *format, ...);

// int	main(void)
// {
// 	int			count_custom;
// 	int			count_standard;
// 	const char	*test_str = "Hello\nWorld!";

// 	// Case 1: Newline at the end
// 	count_custom = ft_printf("Custom: Hello, world!\n");
// 	count_standard = printf("Standard: Hello, world!\n");
// 	printf("Custom printed %d characters, Standard printed %d characters\n\n",
// 		count_custom, count_standard);
// 	// Case 2: Newline in the middle of the format string
// 	count_custom = ft_printf("Custom: Hello,\nworld!\n");
// 	count_standard = printf("Standard: Hello,\nworld!\n");
// 	printf("Custom printed %d characters, Standard printed %d characters\n\n",
// 		count_custom, count_standard);
// 	// Case 3: Newline in the format string with an integer
// 	count_custom = ft_printf("Custom: Number is %d\n", 42);
// 	count_standard = printf("Standard: Number is %d\n", 42);
// 	printf("Custom printed %d characters, Standard printed %d characters\n\n",
// 		count_custom, count_standard);
// 	// Case 4: Multiple newlines in a single format string
// 	count_custom = ft_printf("Custom:\n\nHello\n\nWorld\n\n");
// 	count_standard = printf("Standard:\n\nHello\n\nWorld\n\n");
// 	printf("Custom printed %d characters, Standard printed %d characters\n\n",
// 		count_custom, count_standard);
// 	// Case 5: Newline with string specifier
// 	count_custom = ft_printf("Custom: %s\n", test_str);
// 	count_standard = printf("Standard: %s\n", test_str);
// 	printf("Custom printed %d characters, Standard printed %d characters\n\n",
// 		count_custom, count_standard);
// 	return (0);
// }

// int	main(void)
// {
// 	int				count_custom;
// 	int				count_standard;
// 	int				test_int;
// 	const char		*test_str = "Hello, world!";
// 	char			test_char;
// 	void			*test_ptr;
// 	unsigned int	test_unsigned;
// 	unsigned int	test_hex;

// 	// Testing %d and %i for signed integers
// 	test_int = 42;
// 	count_custom = ft_printf("Custom: %d\n", test_int);
// 	count_standard = printf("Standard: %d\n", test_int);
// 	printf("Custom printed %d characters, Standard printed %d characters\n\n",
// 		count_custom, count_standard);
// 	// Testing %s for strings
// 	count_custom = ft_printf("Custom: %s\n", test_str);
// 	count_standard = printf("Standard: %s\n", test_str);
// 	printf("Custom printed %d characters, Standard printed %d characters\n\n",
// 		count_custom, count_standard);
// 	// Testing %c for single character
// 	test_char = 'A';
// 	count_custom = ft_printf("Custom: %c\n", test_char);
// 	count_standard = printf("Standard: %c\n", test_char);
// 	printf("Custom printed %d characters, Standard printed %d characters\n\n",
// 		count_custom, count_standard);
// 	// Testing %p for pointer address
// 	test_ptr = (void *)&test_int;
// 	count_custom = ft_printf("Custom: %p\n", test_ptr);
// 	count_standard = printf("Standard: %p\n", test_ptr);
// 	printf("Custom printed %d characters, Standard printed %d characters\n\n",
// 		count_custom, count_standard);
// 	// Testing %u for unsigned integers
// 	test_unsigned = 123456;
// 	count_custom = ft_printf("Custom: %u\n", test_unsigned);
// 	count_standard = printf("Standard: %u\n", test_unsigned);
// 	printf("Custom printed %d characters, Standard printed %d characters\n\n",
// 		count_custom, count_standard);
// 	// Testing %x for lowercase hexadecimal
// 	test_hex = 0xabc123;
// 	count_custom = ft_printf("Custom: %x\n", test_hex);
// 	count_standard = printf("Standard: %x\n", test_hex);
// 	printf("Custom printed %d characters, Standard printed %d characters\n\n",
// 		count_custom, count_standard);
// 	// Testing %X for uppercase hexadecimal
// 	count_custom = ft_printf("Custom: %X\n", test_hex);
// 	count_standard = printf("Standard: %X\n", test_hex);
// 	printf("Custom printed %d characters, Standard printed %d characters\n\n",
// 		count_custom, count_standard);
// 	// Testing %% for printing percent sign
// 	count_custom = ft_printf("Custom: %%\n");
// 	count_standard = printf("Standard: %%\n");
// 	printf("Custom printed %d characters, Standard printed %d characters\n\n",
// 		count_custom, count_standard);
// 	return (0);
// }
