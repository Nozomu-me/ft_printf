/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 17:54:17 by amouassi          #+#    #+#             */
/*   Updated: 2019/12/18 17:46:42 by amouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_initiate_flags(t_flags *flg)
{
	flg->precision = -1;
	flg->width = 0;
	flg->flag = '1';
	flg->point = 0;
}

void		ft_sub_check_flags(char *str, t_flags *flg)
{
	int			i;

	ft_initiate_flags(flg);
	i = 0;
	while (str[i] != '\0')
	{
		if (i == 0 && str[i] == '0')
			flg->flag = '0';
		if (str[i] == '-')
			flg->flag = '-';
		i++;
	}
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '.')
			break ;
		if (str[i] >= '1' && str[i] <= '9')
		{
			flg->width = ft_atoi(&str[i]);
			break ;
		}
		i++;
	}
}

t_flags		ft_check_flags(char *str, va_list *list)
{
	int			i;
	t_flags		flg;

	ft_sub_check_flags(str, &flg);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '.')
		{
			flg.point = '.';
			if (((i - 1) >= 0) && str[i - 1] == '*')
				flg.width = va_arg(*list, int);
			if (str[i + 1] == '*')
				flg.precision = va_arg(*list, int);
			else
				flg.precision = ft_atoi(&str[i + 1]);
			break ;
		}
		if (ft_is_type(str[i]) && str[i - 1] == '*')
			flg.width = va_arg(*list, int);
		i++;
	}
	return (flg);
}
