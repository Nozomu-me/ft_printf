/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_pointer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:12:43 by amouassi          #+#    #+#             */
/*   Updated: 2019/12/22 15:31:03 by amouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_process_pnegpre(unsigned long int n, t_flags f, int *c)
{
	if (f.flag == '1')
	{
		*c += ft_print_char(' ', f.width - ft_count_pointer(n, f) - 2);
		ft_putstr_fd("0x", 1);
		ft_print_pointer(n);
	}
	if (f.flag == '-')
	{
		ft_putstr_fd("0x", 1);
		ft_print_pointer(n);
		*c += ft_print_char(' ', f.width - ft_count_pointer(n, f) - 2);
	}
	if (f.flag == '0')
	{
		ft_putstr_fd("0x", 1);
		*c += ft_print_char('0', f.width - ft_count_pointer(n, f) - 2);
		ft_print_pointer(n);
	}
}

void	ft_process_pnoflag(unsigned long int n, t_flags f, int *c)
{
	if (f.width > f.precision)
	{
		if ((f.precision < ft_count_pointer(n, f)) && n != 0)
			*c += ft_print_char(' ', f.width - ft_count_pointer(n, f) - 2);
		else
			*c += ft_print_char(' ', f.width - f.precision - 2);
		ft_putstr_fd("0x", 1);
		*c += ft_print_char('0', f.precision - ft_count_pointer(n, f));
		if ((!n && f.precision != 0) || (n && f.precision != -1))
			ft_print_pointer(n);
	}
}

void	ft_process_pflag(unsigned long int n, t_flags f, int *c)
{
	if (f.width > f.precision)
	{
		ft_putstr_fd("0x", 1);
		*c += ft_print_char('0', f.precision - ft_count_pointer(n, f));
		if ((!n && f.precision != 0) || (n && f.precision != -1))
			ft_print_pointer(n);
		if (f.precision < ft_count_pointer(n, f) && n != 0)
			*c += ft_print_char(' ', f.width - ft_count_pointer(n, f) - 2);
		else
			*c += ft_print_char(' ', f.width - f.precision - 2);
	}
}

void	ft_sub_pointer(unsigned long int n, t_flags flg, int *c)
{
	if (flg.flag == '1')
		ft_process_pnoflag(n, flg, c);
	else if (flg.flag == '-')
		ft_process_pflag(n, flg, c);
	if (flg.precision >= flg.width)
	{
		ft_putstr_fd("0x", 1);
		*c += ft_print_char('0', flg.precision - ft_count_pointer(n, flg));
		if ((!n && flg.precision != 0) || (n && flg.precision != -1))
			ft_print_pointer(n);
	}
}

int		ft_process_pointer(char *type, va_list *list)
{
	unsigned long int	nbr;
	t_flags				flg;
	int					count;

	flg = ft_check_flags(type, list);
	nbr = va_arg(*list, unsigned long int);
	count = 2 + ft_count_pointer(nbr, flg);
	if (flg.width < 0)
	{
		flg.width *= -1;
		flg.flag = '-';
	}
	if (flg.precision >= 0 && flg.flag == '0')
		flg.flag = '1';
	if (flg.precision < 0)
		ft_process_pnegpre(nbr, flg, &count);
	else if (flg.precision != -1)
		ft_sub_pointer(nbr, flg, &count);
	return (count);
}
