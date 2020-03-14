/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_integer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 14:31:58 by amouassi          #+#    #+#             */
/*   Updated: 2019/12/21 20:26:38 by amouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_process_neg_pre(int nbr, t_flags flg, int *count)
{
	if (flg.flag == '1')
	{
		*count += ft_print_char(' ', flg.width - ft_digitscount(nbr));
		ft_putnbr_fd(nbr, 1);
	}
	if (flg.flag == '-')
	{
		ft_putnbr_fd(nbr, 1);
		*count += ft_print_char(' ', flg.width - ft_digitscount(nbr));
	}
	if (flg.flag == '0')
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			*count += ft_print_char('0', flg.width - ft_digitscount(nbr));
			ft_putnbr(nbr * -1);
		}
		else
		{
			*count += ft_print_char('0', flg.width - ft_digitscount(nbr));
			ft_putnbr_fd(nbr, 1);
		}
	}
}

void		ft_process_noflag(int nbr, t_flags flg, int *c)
{
	if (flg.width > flg.precision)
	{
		if (nbr < 0)
		{
			if ((flg.precision < ft_digitscount(nbr)) && nbr != 0)
				*c += ft_print_char(' ', flg.width - ft_digitscount(nbr));
			else
				*c += ft_print_char(' ', flg.width - flg.precision - 1);
			ft_putchar('-');
			*c += ft_print_char('0', flg.precision - ft_digitscount(nbr) + 1);
			ft_putnbr(nbr * -1);
		}
		else
		{
			if ((flg.precision < ft_digitscount(nbr)) && nbr != 0)
				*c += ft_print_char(' ', flg.width - ft_digitscount(nbr));
			else
				*c += ft_print_char(' ', flg.width - flg.precision);
			*c += ft_print_char('0', flg.precision - ft_digitscount(nbr));
			if ((!nbr && flg.precision != 0) || (nbr && flg.precision != -1))
				ft_putnbr_fd(nbr, 1);
		}
	}
}

void		ft_process_flag(int nbr, t_flags flg, int *c)
{
	if (flg.width > flg.precision)
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			*c += ft_print_char('0', flg.precision - ft_digitscount(nbr) + 1);
			ft_putnbr(nbr * -1);
			if (flg.precision < ft_digitscount(nbr) && nbr != 0)
				*c += ft_print_char(' ', flg.width - ft_digitscount(nbr));
			else
				*c += ft_print_char(' ', flg.width - flg.precision - 1);
		}
		else
		{
			*c += ft_print_char('0', flg.precision - ft_digitscount(nbr));
			if ((!nbr && flg.precision != 0) || (nbr && flg.precision != -1))
				ft_putnbr_fd(nbr, 1);
			if ((flg.precision < ft_digitscount(nbr)) && nbr != 0)
				*c += ft_print_char(' ', flg.width - ft_digitscount(nbr));
			else
				*c += ft_print_char(' ', flg.width - flg.precision);
		}
	}
}

void		ft_sub_process_integer(int nbr, t_flags flg, int *c)
{
	if (flg.flag == '1')
		ft_process_noflag(nbr, flg, c);
	else if (flg.flag == '-')
		ft_process_flag(nbr, flg, c);
	if (flg.precision >= flg.width)
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			*c += ft_print_char('0', flg.precision - ft_digitscount(nbr) + 1);
			ft_putnbr(nbr * -1);
		}
		else
		{
			*c += ft_print_char('0', flg.precision - ft_digitscount(nbr));
			if ((!nbr && flg.precision != 0) || (nbr && flg.precision != -1))
				ft_putnbr_fd(nbr, 1);
		}
	}
}

int			ft_process_integer(char *type, va_list *list)
{
	long int	nbr;
	t_flags		flg;
	int			count;

	flg = ft_check_flags(type, list);
	nbr = va_arg(*list, int);
	count = ft_digitscount(nbr);
	if (flg.width < 0)
	{
		flg.width *= -1;
		flg.flag = '-';
	}
	count = (!flg.precision && !nbr) ? --count : count;
	if (flg.precision >= 0 && flg.flag == '0')
		flg.flag = '1';
	if (flg.precision < 0)
		ft_process_neg_pre(nbr, flg, &count);
	else if (flg.precision != -1)
		ft_sub_process_integer(nbr, flg, &count);
	return (count);
}
