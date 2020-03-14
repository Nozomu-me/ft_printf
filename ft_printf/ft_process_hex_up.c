/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_hex_up.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 15:48:02 by amouassi          #+#    #+#             */
/*   Updated: 2019/12/21 20:24:43 by amouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_hex_up_neg_pre(unsigned int nbr, t_flags flg, int *count)
{
	if (flg.flag == '1')
	{
		*count += ft_print_char(' ', flg.width - ft_hexa_count(nbr));
		ft_printhexa_up(nbr);
	}
	if (flg.flag == '-')
	{
		ft_printhexa_up(nbr);
		*count += ft_print_char(' ', flg.width - ft_hexa_count(nbr));
	}
	if (flg.flag == '0')
	{
		*count += ft_print_char('0', flg.width - ft_hexa_count(nbr));
		ft_printhexa_up(nbr);
	}
}

void		ft_hex_up_noflag(unsigned int nbr, t_flags flg, int *count)
{
	if (flg.width > flg.precision)
	{
		if ((flg.precision < ft_hexa_count(nbr)) && nbr != 0)
			*count += ft_print_char(' ', flg.width - ft_hexa_count(nbr));
		else
			*count += ft_print_char(' ', flg.width - flg.precision);
		*count += ft_print_char('0', flg.precision - ft_hexa_count(nbr));
		if ((!nbr && flg.precision != 0) || (nbr && flg.precision != -1))
			ft_printhexa_up(nbr);
	}
}

void		ft_hex_up_flag(unsigned int nbr, t_flags flg, int *count)
{
	if (flg.width > flg.precision)
	{
		*count += ft_print_char('0', flg.precision - ft_hexa_count(nbr));
		if ((!nbr && flg.precision != 0) || (nbr && flg.precision != -1))
			ft_printhexa_up(nbr);
		if (flg.precision < ft_hexa_count(nbr) && nbr != 0)
			*count += ft_print_char(' ', flg.width - ft_hexa_count(nbr));
		else
			*count += ft_print_char(' ', flg.width - flg.precision);
	}
}

void		ft_sub_hex_up(unsigned int nbr, t_flags flg, int *count)
{
	if (flg.flag == '1')
		ft_hex_up_noflag(nbr, flg, count);
	else if (flg.flag == '-')
		ft_hex_up_flag(nbr, flg, count);
	if (flg.precision >= flg.width)
	{
		*count += ft_print_char('0', flg.precision - ft_hexa_count(nbr));
		if ((!nbr && flg.precision != 0) || (nbr && flg.precision != -1))
			ft_printhexa_up(nbr);
	}
}

int			ft_process_hex_up(char *type, va_list *list)
{
	unsigned int		nbr;
	t_flags				flg;
	int					count;

	flg = ft_check_flags(type, list);
	nbr = va_arg(*list, unsigned int);
	count = ft_hexa_count(nbr);
	if (flg.width < 0)
	{
		flg.width *= -1;
		flg.flag = '-';
	}
	count = (!flg.precision && !nbr) ? --count : count;
	if (flg.precision >= 0 && flg.flag == '0')
		flg.flag = '1';
	if (flg.precision < 0)
		ft_hex_up_neg_pre(nbr, flg, &count);
	else if (flg.precision != -1)
		ft_sub_hex_up(nbr, flg, &count);
	return (count);
}
