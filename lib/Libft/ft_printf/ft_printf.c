/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 21:51:58 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/02/04 15:17:42 by  ctokoyod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	process_dispatch(va_list arguments, char specifier)
{
	if (specifier == '%')
		return (print_char('%'));
	else if (specifier == 'c')
		return (print_char(va_arg(arguments, int)));
	else if (specifier == 's')
		return (print_string(va_arg(arguments, char *)));
	else if (specifier == 'd' || specifier == 'i')
		return (print_d_i(va_arg(arguments, int)));
	else if (specifier == 'u')
		return (print_u(va_arg(arguments, unsigned int)));
	else if (specifier == 'x')
		return (convert_hex(va_arg(arguments, unsigned int), 1));
	else if (specifier == 'X')
		return (convert_hex(va_arg(arguments, unsigned int), 0));
	else if (specifier == 'p')
		return (convert_pointer(va_arg(arguments, void *)));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	arguments;
	int		word_count;
	int		i;

	word_count = 0;
	va_start(arguments, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			word_count += process_dispatch(arguments, format[i]);
		}
		else
		{
			word_count += 1;
			write(1, &format[i], 1);
		}
		i++;
	}
	va_end(arguments);
	return (word_count);
}

// メモリリーク確認用　
// #include <libc.h>

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q a.out");
// }

// int	main(void)
// {
// 	char		test_c;
// 	char		test_null;
// 	int			test_zero;
// 	char		*test_s;
// 	int			test_d;
// 	int			test_i;
// 	int			test_u;
// 	int			test_xX;
// 	uintptr_t	test_p;
// 	int			p_len;

// 	test_c = '1';
// 	test_null = '0'; // NULL check
// 	test_zero = '0';
// 	test_s = "abcde";
// 	test_d = -2147483648;
// 	test_i = -214748;
// 	test_u = 12345;
// 	test_xX = 922337207;
// 	// ０、NULL、空の文字列
// 	printf("----------------------------------\n");
// 	printf("Hello\n");
// 	ft_printf("Hello\n");
// 	printf("----------------------------------\n");
// 	printf("<%%c>\n");
// 	p_len = printf("printf    :%c%d%c%d%c%c%d\n", test_c, test_d, test_c,
// 		test_d, test_null, test_null, test_zero);
// 	printf("p_len:%d\n", p_len);
// 	p_len = ft_printf("ft_printf :%c%d%c%d%c%c%d\n", test_c, test_d, test_c,
// 		test_d, test_null, test_null, test_zero);
// 	printf("p_len:%d\n", p_len);
// 	printf("----------------------------------\n");
// 	printf("<%%s>\n");
// 	p_len = printf("printf    :%s\n", test_s);
// 	printf("p_len:%d\n", p_len);
// 	p_len = ft_printf("ft_printf :%s\n", test_s);
// 	printf("p_len:%d\n", p_len);
// 	printf("----------------------------------\n");
// 	printf("<%%d>\n");
// 	p_len = printf("printf    :%d\n", test_d);
// 	printf("p_len:%d\n", p_len);
// 	p_len = ft_printf("ft_printf :%d\n", test_d);
// 	printf("p_len:%d\n", p_len);
// 	printf("----------------------------------\n");
// 	printf("<%%i>\n");
// 	p_len = printf("printf    :%i\n", test_i);
// 	printf("p_len:%d\n", p_len);
// 	p_len = ft_printf("ft_printf :%i\n", test_i);
// 	printf("p_len:%d\n", p_len);
// 	printf("----------------------------------\n");
// 	printf("<%%u>\n");
// 	p_len = printf("printf    :%u\n", test_u);
// 	printf("p_len:%d\n", p_len);
// 	p_len = ft_printf("ft_printf :%u\n", test_u);
// 	printf("p_len:%d\n", p_len);
// 	printf("----------------------------------\n");
// 	printf("<%%x>\n");
// 	p_len = printf("printf    :%x\n", test_xX);
// 	printf("p_len:%d\n", p_len);
// 	p_len = ft_printf("ft_printf :%x\n", test_xX);
// 	printf("p_len:%d\n", p_len);
// 	printf("----------------------------------\n");
// 	printf("<%%X>\n");
// 	p_len = printf("printf    :%X\n", test_xX);
// 	printf("p_len:%d\n", p_len);
// 	p_len = ft_printf("ft_printf :%X\n", test_xX);
// 	printf("p_len:%d\n", p_len);
// 	printf("----------------------------------\n");
// 	printf("<%%p>\n");
// 	p_len = printf("printf    :%p\n", &test_p);
// 	printf("p_len:%d\n", p_len);
// 	p_len = ft_printf("ft_printf :%p\n", &test_p);
// 	printf("ft p_len:%d\n", p_len);
// 	printf("----------------------------------\n");
// 	printf("<MIX>\n");
// 	p_len = 0;
// 	p_len = printf("printf    :%c%s%d%i%u@@%x%X%p\n", test_c, test_s, test_d,
// 		test_i, test_u, test_xX, test_xX, &test_p);
// 	printf("p_len:%d\n", p_len);
// 	p_len = ft_printf("ft_printf :%c%s%d%i%u@@%x%X%p\n", test_c, test_s, test_d,
// 		test_i, test_u, test_xX, test_xX, &test_p);
// 	printf("ft p_len:%d\n", p_len);
// }