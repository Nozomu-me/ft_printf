/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 15:20:51 by amouassi          #+#    #+#             */
/*   Updated: 2019/12/18 17:49:52 by amouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_string_check_help(char *str, t_flags *flg, int *count)
{
	if ((size_t)flg->precision < ft_strlen(str))
	{
		*count += ft_print_char('0', flg->width - flg->precision);
		*count += ft_print_str(str, flg->precision);
	}
	else
	{
		*count += ft_print_char('0', flg->width - ft_strlen(str));
		*count += ft_putstr(str);
	}
}

void		ft_string_check_flag(char *str, t_flags *flg, int *count)
{
	if (flg->flag == '-')
	{
		if ((size_t)flg->precision < ft_strlen(str))
		{
			*count += ft_print_str(str, flg->precision);
			*count += ft_print_char(' ', flg->width - flg->precision);
		}
		else
		{
			*count += ft_putstr(str);
			*count += ft_print_char(' ', flg->width - ft_strlen(str));
		}
	}
	else if (flg->flag == '0')
		ft_string_check_help(str, flg, count);
}

void		ft_sub_process_string(char *str, t_flags *flg, int *count)
{
	if (flg->flag == '-' || flg->flag == '0')
		ft_string_check_flag(str, flg, count);
	else
	{
		if ((size_t)flg->precision < ft_strlen(str))
		{
			*count += ft_print_char(' ', flg->width - flg->precision);
			*count += ft_print_str(str, flg->precision);
		}
		else
		{
			*count += ft_print_char(' ', flg->width - ft_strlen(str));
			*count += ft_putstr(str);
		}
	}
}

void		ft_string_nopre(char *str, t_flags flg, int *count)
{
	if (flg.flag == '-')
	{
		*count += ft_putstr(str);
		*count += ft_print_char(' ', (flg.width - ft_strlen(str)));
	}
	else
	{
		if (flg.flag == '0')
			*count += ft_print_char('0', (flg.width - ft_strlen(str)));
		else
			*count += ft_print_char(' ', (flg.width - ft_strlen(str)));
		*count += ft_putstr(str);
	}
}

int			ft_process_string(char *type, va_list *list)
{
	t_flags		flg;
	char		*str;
	int			count;

	count = 0;
	flg = ft_check_flags(type, list);
	str = va_arg(*list, char*);
	if (str == NULL)
		str = "(null)";
	if (flg.width < 0)
	{
		flg.width *= -1;
		flg.flag = '-';
	}
	if (flg.point == '.' && flg.precision == 0 && flg.flag == '0')
		count += ft_print_char('0', flg.width);
	else if (flg.point == '.' && flg.precision == 0)
		count += ft_print_char(' ', flg.width);
	else if (flg.precision == -1)
		ft_string_nopre(str, flg, &count);
	else
		ft_sub_process_string(str, &flg, &count);
	return (count);
}
