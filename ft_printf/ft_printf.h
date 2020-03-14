/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 15:08:53 by amouassi          #+#    #+#             */
/*   Updated: 2019/12/20 18:15:30 by amouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

typedef struct		s_flags
{
	char			flag;
	int				width;
	int				precision;
	char			point;
}					t_flags;

int					ft_printf(const char *str, ...);
int					ft_process_char(char *type, va_list *list);
int					ft_process_string(char *type, va_list *list);
int					ft_process_integer(char *type, va_list *list);
t_flags				ft_check_flags(char *str, va_list *args);
int					ft_is_type(char c);
int					ft_is_flag(char c);
int					ft_is_width(char c);
int					ft_is_precision(char c);
int					ft_is_separator(char c);
int					ft_print_spaces(int width);
int					ft_process_unsigned_int(char *type, va_list *list);
int					ft_process_hex_low(char *type, va_list *list);
int					ft_process_hex_up(char *type, va_list *list);
int					ft_process_pointer(char *type, va_list *list);
int					ft_print_char(char c, int count);
int					ft_digitscount(int a);
int					ft_putstr(char *str);
int					ft_putchar(char c);
void				ft_putnbr(unsigned int nbr);
int					ft_digits_unsigned(unsigned int nbr);
void				ft_printhexa_up(unsigned int nb);
void				ft_printhexa_low(unsigned int nb);
int					ft_hexa_count(unsigned int nb);
void				ft_print_rev(char *str);
void				ft_print_pointer(unsigned long int nb);
int					ft_count_pointer(unsigned long int nb, t_flags flg);
int					ft_print_str(char *str, int precision);

#endif
