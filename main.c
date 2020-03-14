/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 14:31:51 by amouassi          #+#    #+#             */
/*   Updated: 2019/12/13 17:48:15 by amouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
int main(){
	/*char n[]="you";
	  char c='X';
	  int r=89;*/
	char *str = "hello";


//	ft_printf("66,%-3.*s\n",2, "wow");
//	printf("66,%-3.*s\n",2, "wow");

//	ft_printf("%*.*s %s,%-3.*s\n", 6, 2, str , NULL, 2, "wow");
//	printf("%*.*s %s,%-3.*s\n", 6, 2, str , NULL, 2, "wow");

	//ft_printf("%s\n", "hello");

	//printf("%d\n",ft_printf("%-*.*s,%.s,%s|%-6s|,>%.2s<,%*.*s\n", 6, 2, "hello", NULL, "wu", "world", NULL, 5, 0, "TYUI"));
	//printf("%d\n",printf("%-*.*s,%.s,%s|%-6s|,>%.2s<,%*.*s\n", 6, 2, "hello", NULL, "wu", "world", NULL, 5, 0, "TYUI"));

	//ft_printf("%-*.*s,%.s,%s|%-6s|,>%s<,%*.*s\n", 6, 2, "hello", NULL, "wu", "world", NULL, 5, 2, "TYUI");

//	ft_printf("%5.s %3s %1s %s %-5s %-1s %-s %*s %*s %*s %5s %3s %1s %s %*s %-*s %.5s %.1s %.s %.s %.*s %.*s %*s\n", "How", "How", "How", "How", "How", "How", "How", 5, "How", -5, "How", 2, "How", "How", "How", "How", "How", 5, "How", 5, "How", "How", "How", "How", "How", 5, "How", -5, "How", -9, NULL);
//	ft_printf("%5.s %3s %1s %s %-5s %-1s %-s %*s %*s %*s %5s %3s %1s %s %*s %-*s %.5s %.1s %.s %.s %.*s %.*s %*s\n", "How", "How", "How", "How", "How", "How", "How", 5, "How", -5, "How", 2, "How", "How", "How", "How", "How", 5, "How", 5, "How", "How", "How", "How", "How", 5, "How", -5, "How", -9, NULL);

	// printf("%d\n",ft_printf("%-*.*s,%.s,%s|%-6s|,>%s<,%*.*s\n", 6, 2, "hello", NULL, "wu", "world", NULL, 5, 2, "TYUI"));
	// printf("%d\n",printf("%-*.*s,%.s,%s|%-6s|,>%s<,%*.*s\n", 6, 2, "hello", NULL, "wu", "world", NULL, 5, 2, "TYUI"));

//	ft_printf("%*s\n",-9,"hello");
//	printf("%*s\n",-9,"hello");

//	ft_printf("%3.1d\n", 0);
//	printf("%3.1d\n", 0);

//	printf("%d\n", ft_printf("%*.*d\n",-9,12, -1));
//	printf("%d\n", printf("%*.*d\n",-9,12, -1));

//	printf("%d\n", ft_printf("%10.7d\n", -4));
//	printf("%d\n", printf("%10.7d\n", -4));

//	printf("%d\n", ft_printf("%-*.*d\n", 4,3,1));
//	printf("%d\n", printf("%-*.*d\n",4,3, 1));


	//printf("%d\n",ft_printf("%8.d\n", -100));
	//printf("%d\n",printf("%8.d\n", -100));
	
//	printf("%d\n", ft_printf("%*d\n", 44, 5));
//	printf("%d\n", printf("%*d\n", 44, 5));

	//T("%4.d", -100);
	//T("%4.d", 0);
	//T("%1.d", 0);



//	printf("%d\n",ft_printf("%015.14d\n",9));
//	printf("%d\n",printf("%15.14d\n", 9));

//     printf("%u\n", ft_printf("%015.3d\n", UINT32_MAX + 2));
//     printf("%u\n", printf("%015.3d\n", UINT32_MAX + 2));

    //  printf("%d\n", ft_printf("%20d\n", INT32_MIN));
    //  printf("%d\n", printf("%20d\n", INT32_MIN));

//     printf("%d\n", ft_printf("%20d\n", INT32_MIN + 1));
//     printf("%d\n", printf("%20d\n", INT32_MIN + 1));

//	ft_printf("%d\n",9);
//	printf("%d\n", 9);
	
//	printf("%d\n",ft_printf("%*c\n",-9, 'e'));
//	printf("%d\n",printf("%*c\n",-9, 'e'));

//	printf("%d\n",ft_printf("f = %u\n", UINT32_MAX + 95));
//	printf("%d\n",printf("p = %u\n", UINT32_MAX + 95));

//	ft_putnbr(4294967295);
//	printf("%u\n", UINT32_MAX);
//	printf("%d\n",ft_printf("a%ua\n",0));
//	printf("%d\n",printf("a%ua\n", 0));




	return 0;
}
