/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 15:08:53 by amouassi          #+#    #+#             */
/*   Updated: 2019/12/12 12:41:01 by amouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_H
#define PROCESS_H

#include "libft/libft.h"
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>


typedef struct		s_flags
{
	char	flag;
	int		width;
	int		precision;
	char    p;
}					t_flags;

int				ft_printf(const char *str, ...);
void			ft_process_char(char *type, va_list *list);
void			ft_process_string(char *type,va_list *list);
int				ft_process_integer(char *type,va_list *list);
t_flags			ft_check_flags(char *str, va_list *args);
int				isType(char c);
int				isFlag(char c);
int				isWidth(char c);
int				isPrecision(char c);
int				isSeparator(char c);
void			print_spaces(int width);
void			ft_process_unsigned_int(char *type, va_list *list);
void			ft_process_hexa_lower_case(char *type, va_list *list);
void			ft_process_hexa_upper_case(char *type, va_list *list);
void			ft_process_pointer(char *type, va_list *list);
int				print_char(char c, int count);
int				digitsCount(int a);
int     		ft_putchar(char c);

#endif
