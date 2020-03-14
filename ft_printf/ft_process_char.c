/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 14:58:16 by amouassi          #+#    #+#             */
/*   Updated: 2019/12/18 17:47:36 by amouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_spaces(int width)
{
	int j;

	j = 0;
	while (j < (width - 1))
	{
		ft_putchar_fd(' ', 1);
		j++;
	}
	return (j);
}

void	ft_sub_process_char(t_flags flg, int *count, char c)
{
	if (flg.flag == '0')
		*count += ft_print_char('0', flg.width - 1);
	else
		*count += print_spaces(flg.width);
	*count += ft_putchar(c);
}

int		ft_process_char(char *type, va_list *list)
{
	t_flags		flg;
	int			count;
	char		c;

	count = 0;
	flg = ft_check_flags(type, list);
	if (type[ft_strlen(type) - 1] == '%')
		c = '%';
	else
		c = va_arg(*list, int);
	if (flg.width < 0)
	{
		flg.width *= -1;
		flg.flag = '-';
	}
	if (flg.flag == '-')
	{
		count += ft_putchar(c);
		count += print_spaces(flg.width);
	}
	else
		ft_sub_process_char(flg, &count, c);
	return (count);
}
