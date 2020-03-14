/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 15:48:55 by amouassi          #+#    #+#             */
/*   Updated: 2019/12/21 20:03:12 by amouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printhexa_low(unsigned int nb)
{
	char	str[9];
	int		i;
	int		mod;

	i = 0;
	if (nb == 0)
		ft_putchar_fd('0', 1);
	while (nb != 0)
	{
		mod = nb % 16;
		if (mod >= 0 && mod <= 9)
		{
			str[i] = mod + '0';
			i++;
		}
		else
		{
			str[i] = mod + 87;
			i++;
		}
		nb = nb / 16;
	}
	str[i] = '\0';
	ft_print_rev(str);
}

void		ft_printhexa_up(unsigned int nb)
{
	char	str[9];
	int		i;
	int		mod;

	i = 0;
	if (nb == 0)
		ft_putchar_fd('0', 1);
	while (nb != 0)
	{
		mod = nb % 16;
		if (mod >= 0 && mod <= 9)
		{
			str[i] = mod + '0';
			i++;
		}
		else
		{
			str[i] = mod + 55;
			i++;
		}
		nb = nb / 16;
	}
	str[i] = '\0';
	ft_print_rev(str);
}

int			ft_hexa_count(unsigned int nb)
{
	char	str[20];
	int		i;
	int		mod;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		mod = nb % 16;
		if (mod >= 0 && mod <= 9)
		{
			str[i] = mod + '0';
			i++;
		}
		else
		{
			str[i] = mod + 87;
			i++;
		}
		nb = nb / 16;
	}
	str[i] = '\0';
	return (ft_strlen(str));
}

void		ft_print_pointer(unsigned long int nb)
{
	char	str[30];
	int		i;
	int		mod;

	i = 0;
	if (nb == 0)
		ft_putchar_fd('0', 1);
	while (nb != 0)
	{
		mod = nb % 16;
		if (mod >= 0 && mod <= 9)
		{
			str[i] = mod + '0';
			i++;
		}
		else
		{
			str[i] = mod + 87;
			i++;
		}
		nb = nb / 16;
	}
	str[i] = '\0';
	ft_print_rev(str);
}

int			ft_count_pointer(unsigned long int nb, t_flags flg)
{
	char	str[30];
	int		i;
	int		len;

	len = 0;
	i = 0;
	if (nb == 0 && flg.precision != 0)
		len = 1;
	while (nb != 0)
	{
		if (ft_isdigit(nb % 16))
		{
			str[i] = (nb % 16) + '0';
			i++;
		}
		else
		{
			str[i] = (nb % 16) + 87;
			i++;
		}
		nb = nb / 16;
	}
	str[i] = '\0';
	len += ft_strlen(str);
	return (len);
}
