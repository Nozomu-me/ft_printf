/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_unsigned_int.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 15:41:45 by amouassi          #+#    #+#             */
/*   Updated: 2019/12/21 18:20:32 by amouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_process_u_neg_pre(unsigned int nbr, t_flags flg, int *count)
{
	if (flg.flag == '1')
	{
		*count += ft_print_char(' ', flg.width - ft_digits_unsigned(nbr));
		ft_putnbr(nbr);
	}
	if (flg.flag == '-')
	{
		ft_putnbr(nbr);
		*count += ft_print_char(' ', flg.width - ft_digits_unsigned(nbr));
	}
	if (flg.flag == '0')
	{
		*count += ft_print_char('0', flg.width - ft_digits_unsigned(nbr));
		ft_putnbr(nbr);
	}
}

void		ft_process_u_noflag(unsigned int nbr, t_flags flg, int *count)
{
	if (flg.width > flg.precision)
	{
		if ((flg.precision < ft_digits_unsigned(nbr)) && nbr != 0)
			*count += ft_print_char(' ', flg.width - ft_digits_unsigned(nbr));
		else
			*count += ft_print_char(' ', flg.width - flg.precision);
		*count += ft_print_char('0', flg.precision - ft_digits_unsigned(nbr));
		if ((!nbr && flg.precision != 0) || (nbr && flg.precision != -1))
			ft_putnbr(nbr);
	}
}

void		ft_process_u_flag(unsigned int nbr, t_flags flg, int *count)
{
	if (flg.width > flg.precision)
	{
		*count += ft_print_char('0', flg.precision - ft_digits_unsigned(nbr));
		if ((!nbr && flg.precision != 0) || (nbr && flg.precision != -1))
			ft_putnbr(nbr);
		if (flg.precision < ft_digits_unsigned(nbr) && nbr != 0)
			*count += ft_print_char(' ', flg.width - ft_digits_unsigned(nbr));
		else
			*count += ft_print_char(' ', flg.width - flg.precision);
	}
}

void		ft_sub_process_int(unsigned int nbr, t_flags flg, int *count)
{
	if (flg.flag == '1')
		ft_process_u_noflag(nbr, flg, count);
	else if (flg.flag == '-')
		ft_process_u_flag(nbr, flg, count);
	if (flg.precision >= flg.width)
	{
		*count += ft_print_char('0', flg.precision - ft_digits_unsigned(nbr));
		if ((!nbr && flg.precision != 0) || (nbr && flg.precision != -1))
			ft_putnbr(nbr);
	}
}

int			ft_process_unsigned_int(char *type, va_list *list)
{
	int			nbr;
	t_flags		flg;
	int			count;

	flg = ft_check_flags(type, list);
	nbr = va_arg(*list, unsigned int);
	count = ft_digits_unsigned(nbr);
	if (flg.width < 0)
	{
		flg.width *= -1;
		flg.flag = '-';
	}
	count = (!flg.precision && !nbr) ? --count : count;
	if (flg.precision >= 0 && flg.flag == '0')
		flg.flag = '1';
	if (flg.precision < 0)
		ft_process_u_neg_pre(nbr, flg, &count);
	else if (flg.precision != -1)
		ft_sub_process_int(nbr, flg, &count);
	return (count);
}
