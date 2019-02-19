/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwyl-the <lwyl-the@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 19:00:23 by lwyl-the          #+#    #+#             */
/*   Updated: 2019/02/19 17:58:27 by lwyl-the         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//чтобы запустить этот мейн вводишь																		sh test.sh
//чтобы перекомпилить либу, в которой создается функция printf, когда внес изменения в принтф, вводишь	sh relink.sh
//42Checker работает, только не забывай перекомпиливать либу

// %U когда подали больше чем int

	/*int		i;

	all->type = str[j];
	while (j >= 0)
	{
		i = 0;
		while (ft_isdigit(str[j - i]))
			i++;
		if (!(all->filler->width) && i && str[j - i] != '.')
			all->filler->width = ft_atoi(str + j - i + 1);
		if (!(all->filler->prec) && i && str[j - i] == '.')
		{
			all->filler->prec = ft_atoi(str + j - i + 1);
			all->filler->flaq = 1;
		}
		j--;
	}
	all->width = all->filler->width;
	if (ft_minus_prec(all, all->filler->prec, all->filler->flaq, str))
		all->filler->prec = -1;
	all->prec = all->filler->prec;*/

/*union parsingfloat (для реализации через мантису и экспоненту)
{
	long double v;
	struct
	{
		unsigned long long m_h : 64;
		unsigned int e : 15;
		unsigned int s : 1;
	}	f;
};*/

#include "includes/printf.h"

int main()
{
	int i;
	int j;
	char *tmp;
	long double a = 0.025L;
	double b = 1.42;
	//int a = 5;
	// void *x;
	// x = &kek;
	//union parsingfloat pf;

	//pf.f.m_l = 0;   // 001 1010 0101 0000 0000 0000
	//pf.f.m_h = 0x7FFFFFFFFFFFFFFF;
    //pf.f.e = 0x4009;       // 1000 1001
    //pf.f.s = 0;          // 0

	//pf.v = -0.0 / 0;

	//ft_printf_bits(&kek, 10);

	//printf("%llx     %d    %u\n", pf.f.m_h, (pf.f.e - 0x3FFF), pf.f.s);

	//printf("%Lf\n", pf.v);

	//tmp = "lolkek\n";

	//tmp = "åß∂çlolkek\n";
    //write(1, "\x1b[31m", 6);
    //write(1, "n", 1);
    //write(1, tmp, strlen(tmp));
	//printf(ANSI_COLOR_RED     "This text is RED!"     ANSI_COLOR_RESET "\n");
	//i = ft_printf("%d  %x  %s  %o  %f\n", 5, 5, "kek", 5, 5.0);
	//printf("original printf\n");
	//j = printf("%d\n", 5);
	//printf("%d\n%d\n", i , j);
	//write(1, tmp, ft_strlen(tmp)); //пытаюсь в уникод
/*ft_printf("%");
 ft_printf("% ");
ft_printf("% h");
ft_printf("%Z");
 ft_printf("% hZ");
        ft_printf("%05%");
        ft_printf("%-05%");
   ft_printf("% hZ%");
        ft_printf("% Z", "test");*/
   //ft_printf("    dfasdfds% Keklol ", "test");
   //ft_printf("% Z%s", "test");
        //ft_printf("%000   %", "test");
       /*ft_printf("%%%", "test");
        ft_printf("%%   %", "test");
        ft_printf("%ll#x", 9223372036854775807);
        ft_printf("%010s is a string", "this");
        ft_printf("%-010s is a string", "this");
        ft_printf("%05c", 42);
        ft_printf("% Z", 42);
        ft_printf("%0 d", 42);
        ft_printf("%0 d", -42);
        ft_printf("% 0d", 42);
        ft_printf("% 0d", -42);
        ft_printf("%5+d", 42);
        ft_printf("%5+d", -42);
        ft_printf("%-5+d", 42);
        ft_printf("%-0+5d", 42);
        ft_printf("%-5+d", -42);
        ft_printf("%-0+5d", -42);
        ft_printf("%zhd", 4294967296);
        ft_printf("%jzd", 9223372036854775807);
        ft_printf("%jhd", 9223372036854775807);
        ft_printf("%lhl", 9223372036854775807);
        ft_printf("%lhlz", 9223372036854775807);
        ft_printf("%zj", 9223372036854775807);
        ft_printf("%lhh", 2147483647);
        ft_printf("%hhld", 128);
ft_printf("@main_ftprintf: %####0000 33..1..#00d\n", 256);
  ft_printf("@main_ftprintf: %####0000 33..1d", 256);
ft_printf("@main_ftprintf: %###-#0000 33...12..#0+0d", 256);*/
  /*ft_printf("\n");
  ft_printf("%%\n");
  ft_printf("%d\n", 42);
  ft_printf("%d%d\n", 42, 41);
  ft_printf("%d%d%d\n", 42, 43, 44);
  ft_printf("%ld\n", 2147483647);
  ft_printf("%lld\n", 9223372036854775807);
  ft_printf("%x\n", 505);
  ft_printf("%X\n", 505);
  ft_printf("%p\n", &ft_printf);
  ft_printf("%20.15d\n", 54321);
  ft_printf("%-10d\n", 3);
  ft_printf("% d\n", 3);
  ft_printf("%+d\n", 3);
  ft_printf("%010d\n", 1);
  ft_printf("%hhd\n", 0);
  ft_printf("%jd\n", 9223372036854775807);
  ft_printf("%zd\n", 4294967295);
  ft_printf("%\n");
  ft_printf("%U\n", 4294967295);
  ft_printf("%u\n", 4294967295);
  ft_printf("%o\n", 40);
  ft_printf("%%#08x\n", 42);
  ft_printf("%x\n", 1000);
  ft_printf("%#X\n", 1000);
  ft_printf("%s\n", NULL);
  ft_printf("%S\n", L"ݗݜशব");
  ft_printf("%s%s\n", "test", "test");
  ft_printf("%s%s%s\n", "test", "test", "test");
  ft_printf("%C\n", 15000);*/

		/*ft_printf("%.1Lf\n", 0.25L);
		printf("%.1Lf\n", 0.25L);

		ft_printf("%.2Lf\n",0.25L);
		printf("%.2Lf\n",0.25L);

		ft_printf("%.3Lf\n",0.25L);
		printf("%.3Lf\n",0.25L);

		i = ft_printf("%f\n", -1.0/0);
		j = printf("%f\n", -1.0/0);
		printf("%d\n%d\n", i , j);*/
        printf("%s\n", "42");
	return (0);
}
