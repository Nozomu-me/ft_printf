/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 18:54:02 by amouassi          #+#    #+#             */
/*   Updated: 2019/12/15 20:48:50 by amouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_char(char c, int count)
{
	int		j;

	j = 0;
	while (j < count)
	{
		ft_putchar_fd(c, 1);
		j++;
	}
	return (j);
}

int		ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i] != 0)
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

void	ft_putnbr(unsigned int n)
{
	if (n <= 9)
		ft_putchar(n + 48);
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}
