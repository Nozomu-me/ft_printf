/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 17:08:06 by amouassi          #+#    #+#             */
/*   Updated: 2019/12/21 16:44:32 by amouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_digits_unsigned(unsigned int nb)
{
	int		c;

	c = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb = nb / 10;
		c++;
	}
	return (c);
}

int		ft_digitscount(int nb)
{
	int c;

	c = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		c++;
		nb *= -1;
	}
	while (nb != 0)
	{
		nb = nb / 10;
		c++;
	}
	return (c);
}

void	ft_print_rev(char *str)
{
	int		len;
	int		j;

	len = ft_strlen(str) - 1;
	j = 0;
	while (len >= 0)
	{
		ft_putchar_fd(str[len], 1);
		len--;
	}
}

int		ft_print_str(char *str, int precision)
{
	int		i;

	i = 0;
	while (i < precision)
	{
		ft_putchar_fd(str[i], 1);
		i++;
	}
	return (i);
}
