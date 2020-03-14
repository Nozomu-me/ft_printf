/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:24:50 by amouassi          #+#    #+#             */
/*   Updated: 2019/12/18 17:29:04 by amouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_isvalide(char c)
{
	if (ft_is_separator(c) || ft_is_flag(c) ||
			ft_is_precision(c) || ft_is_width(c))
		return (1);
	return (0);
}

int		ft_sub_printf(char *string, const char *str, int s, va_list *list)
{
	if (str[s] == 's')
		return (ft_process_string(string, list));
	else if (str[s] == 'c' || str[s] == '%')
		return (ft_process_char(string, list));
	else if (str[s] == 'u')
		return (ft_process_unsigned_int(string, list));
	else if (str[s] == 'd')
		return (ft_process_integer(string, list));
	else if (str[s] == 'i')
		return (ft_process_integer(string, list));
	else if (str[s] == 'x')
		return (ft_process_hex_low(string, list));
	else if (str[s] == 'X')
		return (ft_process_hex_up(string, list));
	else if (str[s] == 'p')
		return (ft_process_pointer(string, list));
	return (0);
}

int		ft_help(const char *str, int *i, int s, va_list *list)
{
	char	*string;
	int		count;

	count = 0;
	string = ft_substr(str, *i + 1, s - *i);
	if (!ft_is_type(str[s]))
	{
		count += ft_putstr(string);
		*i = s + 1;
	}
	if (ft_is_type(str[s]))
	{
		count += ft_sub_printf(string, str, s, list);
		*i = s + 1;
	}
	free(string);
	return (count);
}

int		ft_normeprob(const char *str, int i, int *count, va_list *list)
{
	int		s;

	if (str[i] == '%' && str[i + 1] == '%')
	{
		*count += ft_putchar(str[i]);
		i = i + 2;
	}
	else
	{
		s = i + 1;
		while (str[s] != '\0' && str[s] != '%' && ft_isvalide(str[s]))
			s++;
		if (str[s] == '\0')
		{
			*count += ft_putstr((char *)str);
			i = s;
		}
		*count += ft_help(str, &i, s, list);
	}
	return (i);
}

int		ft_printf(const char *str, ...)
{
	int			i;
	va_list		list;
	int			count;

	i = 0;
	va_start(list, str);
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '%')
		{
			count += ft_putchar(str[i]);
			i++;
		}
		else
			i = ft_normeprob(str, i, &count, &list);
	}
	va_end(list);
	return (count);
}
