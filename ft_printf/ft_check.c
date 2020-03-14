/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 18:12:37 by amouassi          #+#    #+#             */
/*   Updated: 2019/12/16 19:08:47 by amouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_is_type(char c)
{
	char		*types;
	size_t		i;

	types = "scdiuxXp%";
	i = 0;
	while (i < ft_strlen(types))
	{
		if (types[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int			ft_is_flag(char c)
{
	if (c == 0 || c == '-')
		return (1);
	return (0);
}

int			ft_is_width(char c)
{
	if ((c >= '0' && c <= '9') || c == '*')
		return (1);
	return (0);
}

int			ft_is_precision(char c)
{
	if ((c >= '0' && c <= '9') || c == '*')
		return (1);
	return (0);
}

int			ft_is_separator(char c)
{
	if (c == '.')
		return (1);
	return (0);
}
