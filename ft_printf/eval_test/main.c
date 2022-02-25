/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotran <leotran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 19:24:42 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/25 15:59:40 by leotran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/ft_printf.h"
#include <stdio.h>
#include <assert.h>

static unsigned int tests;
static unsigned int done;

void mix_ezz(void)
{
	int ret, ret2;
	int	a;
	int	b;
	ret = printf("%u\n", 4);
	ret2 = ft_printf("%u\n", 4);
	printf("\nret: %d \n", ret);
	printf("ret: %d \n", ret2);
	if (ret == ret2)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_ezz failed_______\x1b[0m\n\n"));
	++done;
}

void mix_ez1(void)
{
	int ret, ret2;
	int	a;
	int	b;
	ret = printf("printf: test %u this %i\n", 0, 4);
	ret2 = ft_printf("ft_pri: test %u this %i\n", 0, 4);
	printf("\nret: %d \n", ret);
	printf("ret: %d \n", ret2);
	if (ret == ret2)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_ez1 failed_______\x1b[0m\n\n"));
	++done;
}

void mix_ez2(void)
{
	int ret, ret2;
	int	a;
	int	b;
	ret = printf("printf: this %i\n", 1);
	ret2 = ft_printf("ft_pri: this %i\n", 1);
	printf("\nret: %d \n", ret);
	printf("ret: %d \n", ret2);
	if (ret == ret2)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_ez2 failed_______\x1b[0m\n\n"));
	++done;
}

void mix_ez3(void)
{
	int ret, ret2;
	int	a;
	int	b;
	ret = printf("printf: test %d %% this %i\n", 0, 4);
	ret2 = ft_printf("ft_pri: test %d %% this %i\n", 0, 4);
	printf("\nret: %d \n", ret);
	printf("ret: %d \n", ret2);
	if (ret == ret2)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_ez3 failed_______\x1b[0m\n\n"));
	++done;
}

void mix_ez4(void)
{
	int ret, ret2;
	int	a;
	int	b;
	b = printf("printf: test %u %d this %i %s %c\n", 0, 4, 1, "hej", 'b');
	a = ft_printf("ft_pri: test %u %d this %i %s %c\n", 0, 4, 1, "hej", 'b');
	printf("\nret: %d \n", ret);
	printf("ret: %d \n", ret2);
	if (ret == ret2)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_ez4 failed_______\x1b[0m\n\n"));
	++done;
}

void	test_oct_zero(void)
{
	int ret, ret2;
	int	a;
	int	b;
	ret = printf("printf: oct: %o\n", 0);
	ret2 = ft_printf("ft_pri: oct: %o\n", 0);
	printf("\nret: %d \n", ret);
	printf("ret: %d \n", ret2);
	if (ret == ret2)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_oct_zero failed_______\x1b[0m\n\n"));
	++done;
}

void	test_oct(void)
{
	int ret, ret2;
	int	a;
	int	b;
	ret = printf("printf: oct: %o\n", 123432);
	ret2 = ft_printf("ft_pri: oct: %o\n", 123432);
	printf("\nret: %d \n", ret);
	printf("ret: %d \n", ret2);
	if (ret == ret2)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_oct failed_______\x1b[0m\n\n"));
	++done;
}

void	test_hex(void)
{
	int ret, ret2;
	int	a;
	int	b;
	ret = printf("printf: hex: %X \n", 1234554321);
	ret2 = ft_printf("ft_pri: hex: %X \n", 1234554321);
	printf("\nret: %d \n", ret);
	printf("ret: %d \n", ret2);
	if (ret == ret2)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_hex failed_______\x1b[0m\n\n"));
	++done;
}

void	test_hex_zero(void)
{
	int ret, ret2;
	int	a;
	int	b;
	ret = printf("printf: hex: %X \n", 0);
	ret2 = ft_printf("ft_pri: hex: %X \n", 0);
	printf("\nret: %d \n", ret);
	printf("ret: %d \n", ret2);
	if (ret == ret2)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_hex_zero failed_______\x1b[0m\n\n"));
	++done;
}

void	test_dec(void)
{
	int ret, ret2;
	int	a;
	int	b;

	ret = printf("printf: decimal  %d\n", 32456);
	ret2 = ft_printf("ft_pri: decimal  %d\n", 32456);
	printf("\nret: %d \n", ret);
	printf("ret: %d \n", ret2);
	if (ret == ret2)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n _______test_dec failed_______\x1b[0m\n\n"));
	++done;
}

void	test_int(void)
{
	int ret, ret2;
	int	a;
	int	b;

	ret = printf("printf: decimal  %i\n", 32456);
	ret2 = ft_printf("ft_pri: decimal  %i\n", 32456);
	printf("\nret: %d \n", ret);
	printf("ret: %d \n", ret2);
	if (ret == ret2)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n _______test_int failed_______\x1b[0m\n\n"));
	++done;
}

void	test_hex_random(void)
{
	int ret, ret2;
	int	a;
	int	b;
	ret = printf("printf: hex: %X \n", 17);
	ret2 = ft_printf("ft_pri: hex: %X \n", 17);
	printf("\nret: %d \n", ret);
	printf("ret: %d \n", ret2);
	if (ret == ret2)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_hex_random failed_______\x1b[0m\n\n"));
	++done;
}

void	test_int_zero(void)
{
	int ret, ret2;
	int	a;
	int	b;
	ret = printf("printf: dec: %d \n", 0);
	ret2 = ft_printf("ft_pri: dec: %d \n", 0);
	printf("\nret: %d \n", ret);
	printf("ret: %d \n", ret2);
	if (ret == ret2)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_int_zero failed_______\x1b[0m\n\n"));
	++done;
}

void	test_int_minus(void)
{
	int ret, ret2;
	int	a;
	int	b;
	ret = printf("printf dec: %d \n", -22);
	ret2 = ft_printf("ft_pri dec: %d \n", -22);
	printf("\nret: %d \n", ret);
	printf("ret: %d \n", ret2);
	if (ret == ret2)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_int_minus failed_______\x1b[0m\n\n"));
	++done;
}

void	test_int_plus_flag(void)
{
	int ret, ret2;
	int	a;
	int	b;
	ret = printf("printf dec: %+d more\n", 234);
	ret2 = ft_printf("ft_pri dec: %+d more\n", 234);
	printf("\nret: %d \n", ret);
	printf("ret: %d \n", ret2);
	if (ret == ret2)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_int_plus_flag failed_______\x1b[0m\n\n"));
	++done;
}

void	test_int_plus_flag2(void)
{
	int ret, ret2;
	int	a;
	int	b;
	ret = printf("%+dtext", 21);
	ret2 = ft_printf("%+dtext", 21);
	printf("\nret: %d \n", ret);
	printf("ret: %d \n", ret2);
	if (ret == ret2)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_int_plus_flag2 failed_______\x1b[0m\n\n"));
	++done;
}

void	test_int_minusminus_flag(void)
{
	int ret, ret2;
	int	a;
	int	b;
	ret = printf("printf dec: %+d more\n", -2);
	ret2 = ft_printf("ft_pri dec: %+d more\n", -2);
	printf("\nret: %d \n", ret);
	printf("ret: %d \n", ret2);
	if (ret == ret2)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_int_minusminus_flag failed_______\x1b[0m\n\n"));
	++done;
}

void	test_procentage(void)
{
	int ret, ret2;
	int	a;
	int	b;
	ret = printf("printf dec: %%\n");
	ret2 = ft_printf("ft_pri dec: %%\n");
	printf("\nret: %d \n", ret);
	printf("ret: %d \n", ret2);
	if (ret == ret2)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_procentage failed_______\x1b[0m\n\n"));
	++done;
}

/* void	test_binary(void)
{
	int	a;
	//int	b;
	a = ft_printf("ft_pri dec: %b\n", 2);
	//b = printf("printf dec: %b\n", 2);
	printf("\nret: %d \n", a);
	//printf("ret: %d \n", b);
	//if (a == b)
	//	printf("%d tests complete.\n\n", ++tests);
	//else
	//	assert(printf("\n\x1b[1m _______test_binary failed_______\x1b[0m\n\n"));
	++done;
}
 */

void	test_address(void)
{
	int ret, ret2;
	int	a;
	int	b;
	ret = printf("printf address: %p\n", &a);
	ret2 = ft_printf("ft_pri address: %p\n", &a);
	printf("\nret: %d \n", ret);
	printf("ret: %d \n", ret2);
	if (ret == ret2)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_address failed_______\x1b[0m\n\n"));
	++done;
}

void	test_asterix_with_int(void)
{
	int ret, ret2;
	int	a;
	int	b;
	ret = printf("printf: %*d\n", 20, 21);
	ret2 = ft_printf("ft_pri: %*d\n", 20, 21);
	printf("\nret: %d \n", ret);
	printf("ret: %d \n", ret2);
	if (ret == ret2)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_asterix_with_int failed_______\x1b[0m\n\n"));
	++done;
}

void	test_asterix_with_str(void)
{
	int ret, ret2;
	int	a;
	int	b;
	ret = printf("printf: %*s\n", 76, "this is a string");
	ret2 = ft_printf("ft_pri: %*s\n", 76, "this is a string");
	printf("\nret: %d \n", ret);
	printf("ret: %d \n", ret2);
	if (ret == ret2)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_asterix_with_str failed_______\x1b[0m\n\n"));
	++done;
}

void	test_asterix_with_int_plus(void)
{
	int ret, ret2;
	int	a;
	int	b;
	ret = printf("printf: %+*d\n", 20, 21);
	ret2 = ft_printf("ft_pri: %+*d\n", 20, 21);
	printf("\nret: %d \n", ret);
	printf("ret: %d \n", ret2);
	if (ret == ret2)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_asterix_with_int failed_______\x1b[0m\n\n"));
	++done;
}

void	test_width_single(void)
{
	int ret, ret2;
	int	a;
	int	b;
	ret = printf("pri: %4d\n", 21);
	ret2 = ft_printf("ft_: %4d\n", 21);
	printf("\nret: %d \n", ret);
	printf("ret: %d \n", ret2);
	if (ret == ret2)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_width_single failed_______\x1b[0m\n\n"));
	++done;
}

void	test_width_multi(void)
{
	int ret, ret2;
	int	a;
	int	b;
	ret = printf("pri: %14d\n", 21);
	ret2 = ft_printf("ft_: %14d\n", 21);
	printf("\nret: %d \n", ret);
	printf("ret: %d \n", ret2);
	if (ret == ret2)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_width_multi failed_______\x1b[0m\n\n"));
	++done;
}

void	test_width_multi2(void)
{
	int ret, ret2;
	int	a;
	int	b;
	ret = printf("pri: %114d\n", 21);
	ret2 = ft_printf("ft_: %114d\n", 21);
	printf("\nret: %d \n", ret);
	printf("ret: %d \n", ret2);
	if (ret == ret2)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_width_multi2 failed_______\x1b[0m\n\n"));
	++done;
}

void	test_precision(void)
{
	int ret, ret2;
	int	a;
	int	b;
	ret = printf("pri: %.4d\n", 21);
	ret2 = ft_printf("ft_: %.4d\n", 21);
	printf("\nret: %d \n", ret);
	printf("ret: %d \n", ret2);
	if (ret == ret2)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_precision failed_______\x1b[0m\n\n"));
	++done;
}

void	test_precision_1(void)
{
	int ret, ret2;
	int	a;
	int	b;
	ret = printf("%.8d\n", 21);
	ret2 = ft_printf("%.8d\n", 21);
	printf("\nret: %d \n", ret);
	printf("ret: %d \n", ret2);
	if (ret == ret2)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_precision_1 failed_______\x1b[0m\n\n"));
	++done;
}

void test_mindfuck(void)
{
	int ret, ret2;
	int	a;
	int	b;
	ret = printf("pri: %8.3dLol\n", 42);
	ret2 = ft_printf("ft_: %8.3dLol\n", 42);
	printf("\nret: %d \n", ret);
	printf("ret: %d \n", ret2);
	if (ret == ret2)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_mindfuck failed_______\x1b[0m\n\n"));
	++done;
}

void test_mindfuck_minus(void)
{
	int ret, ret2;
	int	a;
	int	b;
	ret = printf("pri: %-10.5dLol\n", 42);
	ret2 = ft_printf("ft_: %-10.5dLol\n", 42);
	printf("\nret: %d \n", ret);
	printf("ret: %d \n", ret2);
	if (ret == ret2)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_mindfuck_minus failed_______\x1b[0m\n\n"));
	++done;
}

void test_mindfuck_minusminus(void)
{
	int ret, ret2;
	int	a;
	int	b;
	ret = printf("pri: %-10.7dLol\n", -42);
	ret2 = ft_printf("ft_: %-10.7dLol\n", -42);
	printf("\nret: %d \n", ret);
	printf("ret: %d \n", ret2);
	if (ret == ret2)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_mindfuck_minusminus failed_______\x1b[0m\n\n"));
	++done;
}

void test_mindfuck_simpleminus(void)
{
	int ret, ret2;
	int	a;
	int	b;
	ret = printf("pri: %10.5dLol\n", -42);
	ret2 = ft_printf("ft_: %10.5dLol\n", -42);
	printf("\nret: %d \n", ret);
	printf("ret: %d \n", ret2);
	if (ret == ret2)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_mindfuck_simpleminus failed_______\x1b[0m\n\n"));
	++done;
}

void test_mindfuck_minusminint(void) 
{
	int ret, ret2;
	int	a = -2147483648;
	int	b = -2147483648;
	ret = printf("pri: %-30.25dLol\n", b);
	ret2 = ft_printf("ft_: %-30.25dLol\n",a);
	printf("\nret: %d \n", ret);
	printf("ret: %d \n", ret2);
	if (ret == ret2)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_mindfuck_minusminint failed_______\x1b[0m\n\n"));
	++done;
}

void test_mindfuck_minusminint2(void) 
{
	int ret, ret2;
	long	a = -2147483648;
	long	b = -2147483648;
	ret = printf("pri: %13.13dLol\n", (int)b);
	ret2 = ft_printf("ft_: %13.13dLol\n",(int)a);
	printf("\nret: %d \n", ret);
	printf("ret: %d \n", ret2);
	if (ret == ret2)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_mindfuck_minusminint2 failed_______\x1b[0m\n\n"));
	++done;
}

void test_mindfuck_plus_craz(void) 
{
	int ret, ret2;
	long	a = -214;
	long	b = -214;
	ret = printf("pri: %+13.13dLol\n", (int)b);
	ret2 = ft_printf("ft_: %+13.13dLol\n",(int)a);
	printf("\nret: %d \n", ret);
	printf("ret: %d \n", ret2);
	if (ret == ret2)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_mindfuck_plus_craz failed_______\x1b[0m\n\n"));
	++done;
}

void test_mindfuck_plus_craz2(void) 
{
	int ret, ret2;
	long	a = 2147483647;
	long	b = 2147483647;
	ret = printf("pri: %+13.13dLol\n", (int)b);
	ret2 = ft_printf("ft_: %+13.13dLol\n",(int)a);
	printf("\nret: %d \n", ret);
	printf("ret: %d \n", ret2);
	if (ret == ret2)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_mindfuck_plus_craz2 failed_______\x1b[0m\n\n"));
	++done;
}

void test_mindfuck_plus_craz3(void) 
{
	int ret, ret2;
	long	a = -214;
	long	b = -214;
	ret = printf("pri: %+113.13dLol\n", (int)b);
	ret2 = ft_printf("ft_: %+113.13dLol\n",(int)a);
	printf("\nret: %d \n", ret);
	printf("ret: %d \n", ret2);
	if (ret == ret2)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_mindfuck_plus_craz3 failed_______\x1b[0m\n\n"));
	++done;
}

void test_mindfuck_plus_craz4(void) 
{
	int ret, ret2 = 0;
	long	a = 2147483647;
	long	b = 2147483647;
	ret = printf("pri: %+13.83ldLol\n", b);
	ret2 = ft_printf("ft_: %+13.83dLol\n", a);
	printf("\nret: %d \n", ret);
	printf("ret: %d \n", ret2);
	if (ret == ret2)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_mindfuck_plus_craz4 failed_______\x1b[0m\n\n"));
	++done;
}

void test_flag_space_minus(void)
{
	int ret, ret2;
	int	a;
	int	b;
	ret = printf("pri: %     dLol\n", -2147483647);
	ret2 = ft_printf("ft_: %     dLol\n", -2147483647);
	printf("\nret: %d \n", ret);
	printf("ret: %d \n", ret2);
	if (ret == ret2)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_flag_space_minus failed_______\x1b[0m\n\n"));
	++done;
}

void test_flag_space(void)
{
	int	a;
	int	b;
	b = printf("pri: %  dLol\n", 7483647);
	a = ft_printf("ft_: %  dLol\n", 7483647);
	printf("\nret: %d \n", b);
	printf("ret: %d \n", a);
	if (a == b)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_flag_space failed_______\x1b[0m\n\n"));
	++done;
}

void test_length_h(void)
{
	int ret, ret2;
	int	a = -32769;
	int	b = -32769;
	ret = printf("pri: %hd\n", (short)b);
	ret2 = ft_printf("ft_: %hd\n", (short)a);
	printf("\nret: %d \n", ret);
	printf("ret: %d \n", ret2);
	if (ret == ret2)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_length_h failed_______\x1b[0m\n\n"));
	++done;
}

void test_length_h2(void)
{
	int ret, ret2;
	int	a = -327;
	int	b = -327;
/* 	int b;
	int a; */
	ret = printf("%hd\n", (short)b);
	ret2 = ft_printf("%hd\n", (short)a);
	printf("\nret: %d \n", ret);
	printf("ret: %d \n", ret2);
	if (ret == ret2)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_length_h2 failed_______\x1b[0m\n\n"));
	++done;
}

void test_42hex(void)
{
	int ret, ret2;
	int	a;
	int	b;
	ret = printf("pri: %x\n", 42);
	ret2 = ft_printf("ft_: %x\n", 42);
	printf("\nret: %d \n", ret);
	printf("ret: %d \n", ret2);
	if (ret == ret2)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_42hex failed_______\x1b[0m\n\n"));
	++done;
}

void test_length_hh(void)
{
	int ret, ret2;
	int	a;
	int	b;
	ret = printf("%hhd\n", (signed char)287);
	ret2 = ft_printf("%hhd\n", (signed char)287);
	printf("\nret: %d \n", ret);
	printf("ret: %d \n", ret2);
	if (ret == ret2)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_length_hh failed_______\x1b[0m\n\n"));
	++done;
}

void test_length_hh2(void)
{
	int ret, ret2;
	signed char	a = 40;
	signed char	b = 40;
	ret = printf("%hhd\n", b);
	ret2 = ft_printf("%hhd\n", a);
	printf("\nret: %d \n", ret);
	printf("ret: %d \n", ret2);
	if (ret == ret2)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_length_hh2 failed_______\x1b[0m\n\n"));
	++done;
}

void test_length_hh_unsigned_int(void)
{
	int ret, ret2;
	int	a = 4000000;
	int	b = 4000000;
	ret = printf("%hhu\n", (unsigned char)b);
	ret2 = ft_printf("%hhu\n", (unsigned char)a);
	printf("\nret: %d \n", ret);
	printf("ret: %d \n", ret2);
	if (ret == ret2)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_length_hh_unsigned_int failed_______\x1b[0m\n\n"));
	++done;
}

void test_length_hh_unsigned_int2(void)
{
	int ret, ret2;
	int	a = -400;
	int	b = -400;
	ret = printf("pri: %hhu\n", (unsigned char)b);
	ret2 = ft_printf("ft_: %hhu\n", (unsigned char)a);
	printf("\nret: %d \n", ret);
	printf("ret: %d \n", ret2);
	if (ret == ret2)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_length_hh_unsigned_int failed_______\x1b[0m\n\n"));
	++done;
}

void test_length_h_unsigned_int(void)
{
	int ret, ret2;
	int	a = 4000000;
	int	b = 4000000;
	ret = printf("%hu\n", (unsigned short)b);
	ret2 = ft_printf("%hu\n", (unsigned short)a);
	printf("\nret: %d \n", ret);
	printf("ret: %d \n", ret2);
	if (ret == ret2)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_length_h_unsigned_int failed_______\x1b[0m\n\n"));
	++done;
}

void test_length_h_unsigned_int2(void)
{
	int ret, ret2;
	int	a = -400;
	int	b = -400;
	ret = printf("pri: %hu\n", (unsigned short)b);
	ret2 = ft_printf("ft_: %hu\n", (unsigned short)a);
	printf("\nret: %d \n", ret);
	printf("ret: %d \n", ret2);
	if (ret == ret2)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_length_h_unsigned_int failed_______\x1b[0m\n\n"));
	++done;
}

void test_intmin(void)
{
	int ret, ret2;
	int	a = -2147483648;
	int	b = -2147483648;
	ret = printf("pri: %d\n", b);
	ret2 = ft_printf("ft_: %d\n", a);
	printf("\nret: %d \n", ret);
	printf("ret: %d \n", ret2);
	if (ret == ret2)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_test_intmin failed_______\x1b[0m\n\n"));
	++done;
}

void test_hashoct(void)
{
	int ret, ret2;
	int	a = 648;
	int	b = 648;
	ret = printf("pri: %#o\n", b);
	ret2 = ft_printf("ft_: %#o\n", a);
	printf("\nret: %d \n", ret);
	printf("ret: %d \n", ret2);
	if (ret == ret2)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_hashoct failed_______\x1b[0m\n\n"));
	++done;
}

void test_hashoct_intmin(void)
{
	int ret, ret2;
	int	a = -2147483648;
	int	b = -2147483648;
	ret = printf("pri: %#o\n", b);
	ret2 = ft_printf("ft_: %#o\n", a);
	printf("\nret: %d \n", ret);
	printf("ret: %d \n", ret2);
	if (ret == ret2)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_hashoct_intmin failed_______\x1b[0m\n\n"));
	++done;
}

void test_hashhex_intmax(void)
{
	int ret, ret2;
	int	a = 2147483647;
	int	b = 2147483647;
	ret = printf("pri: %#x\n", b);
	ret2 = ft_printf("ft_: %#x\n", a);
	printf("\nret: %d \n", ret);
	printf("ret: %d \n", ret2);
	if (ret == ret2)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_hashhex_intmax failed_______\x1b[0m\n\n"));
	++done;
}

void test_hashhex_intmin(void)
{
	int ret, ret2;
	int	a = -2147483648;
	int	b = -2147483648;
	ret = printf("pri: %#X\n", b);
	ret2 = ft_printf("ft_: %#X\n", a);
	printf("\nret: %d \n", ret);
	printf("ret: %d \n", ret2);
	if (ret == ret2)
		printf("%d tests complete.\n\n", ++tests);
	else
		assert(printf("\n\x1b[1m _______test_hashhex_intmin failed_______\x1b[0m\n\n"));
	++done;
}

int	main(void)
{
	mix_ezz();
	mix_ez1();
	mix_ez2();
	mix_ez3();
	mix_ez4();
	test_oct_zero();
	test_oct();
	test_int();
	test_hex();
	test_hex_zero();
	test_dec();
	test_hex_random();
	test_int_zero();
	test_int_minus();
	test_int_plus_flag();
	test_int_plus_flag2();
	test_int_minusminus_flag();
	test_procentage();
	test_address();
	test_asterix_with_int();
	test_asterix_with_str(); 
	test_width_single();
	test_width_multi();
	test_width_multi2();
 	test_precision();
 	test_precision_1();
	test_mindfuck();
	test_mindfuck_minus();
	test_mindfuck_minusminus();
	test_mindfuck_simpleminus();
 	test_mindfuck_minusminint();
	test_mindfuck_minusminint2();//30 
	
	test_mindfuck_plus_craz(); // 31 FAIL
	test_mindfuck_plus_craz2();
	test_mindfuck_plus_craz3();
	test_mindfuck_plus_craz4();
	test_flag_space_minus(); //35 fail
	
	test_flag_space();
	test_length_h();
	test_length_h2();
	test_length_hh();
	test_length_hh2();
	test_length_hh_unsigned_int();
	test_length_hh_unsigned_int2();
	test_length_h_unsigned_int();
	test_length_h_unsigned_int2();
	test_intmin();
	test_42hex();
	test_asterix_with_int_plus(); //need more tests shere with width, precision, and minus flag
	test_hashoct();
	test_hashoct_intmin();
	test_hashhex_intmin();
	test_hashhex_intmax();
//	test_binary();

	printf("\n%d/%d completed\n", tests, done);

	system("leaks a.out");
	return (0);
}
	
	//- %[flags][width][.precision][length]specifier