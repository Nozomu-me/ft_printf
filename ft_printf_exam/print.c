/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouassi <amouassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:06:31 by amouassi          #+#    #+#             */
/*   Updated: 2020/02/19 14:24:30 by amouassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<stdarg.h>
int ft_putchar(char c)
{
	write(1,&c,1);
	return 1;
}

int ft_strlen(char *str)
{
	int i=0;
	while(str[i]!='\0')
		i++;
	return i;
}

int ft_putstr(char *str, int n)
{
	int i=0;
	while(i<n)
	{
		ft_putchar(str[i]);
		i++;
	}
	return i;
}

void ft_putnbr(unsigned int n)
{
	if (n>9)
	{
		ft_putnbr(n/10);
		ft_putchar(n%10 + '0');
	}
	else
		ft_putchar(n%10 + '0');
}

int ft_countdigit(int n)
{
	int c =0;
	long nb = n;
	if (nb==0)
		return 1;
	if (nb<0)
	{
		c++;
		nb*=-1;
	}
	while(nb!=0)
	{
		nb/=10;
		c++;
	}
	return c;
}

void ft_printhexa(unsigned int n)
{
	if(n>15)
	{
		ft_printhexa(n/16);
		ft_putchar("0123456789abcdef"[n%16]);
	}
	else
		ft_putchar("0123456789abcdef"[n%16]);
}

int ft_counthexa(unsigned int n)
{
	int c = 0;
	if(n>15)
	{
		c+=ft_counthexa(n/16);
		c+=1;
	}
	else
		c+=1;
	return c;
}

char *ft_substr(char *str, int start, int len)
{
	char *s;
	int i =0;
	s = malloc(len + 1);
	if (s == NULL)
		return NULL;
	while(i<len && str[start]!='\0')
	{
		s[i] = str[start];
		i++;
		start++;
	}
	return s;
}

int ft_atoi(char *str)
{
	int i = 0;
	int res = 0;
	while(str[i] >= '0' && str[i] <= '9')
	{
		res = res*10 + str[i] - '0';
		i++;
	}
	return res;
}
int ft_print(char c, int n)
{
	int i =0;
	while(i<n)
	{
		ft_putchar(c);
		i++;
	}
	return i;
}

int ft_isvalid(char c)
{
	return ((c>='0' && c<= '9') || c=='.' || c=='*');
}

int ft_istype(char c)
{
	return (c=='s' || c=='x' || c=='d');
}

typedef struct  s_flags
{
	int w;
	int p;
	char point;
}				t_flags;

t_flags ft_check(char *str, va_list *list)
{
	int i =0;
	t_flags flg;
	flg.w = 0;
	flg.p = -1;
	flg.point  = 'e';
	while(str[i]!='\0')
	{
		if(str[i] == '.')
			break;
		if(str[i] >= '0' && str[i] <= '9')
		{
			flg.w = ft_atoi(&str[i]);
			break;
		}
		i++;
	}
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '.')
		{
			flg.point = '.';
			if (((i - 1) >= 0) && str[i - 1] == '*')
				flg.w = va_arg(*list, int);
			if (str[i + 1] == '*')
				flg.p = va_arg(*list, int);
			else
				flg.p = ft_atoi(&str[i + 1]);
			break ;
		}
		if (ft_istype(str[i]) && str[i - 1] == '*')
			flg.w = va_arg(*list, int);
		i++;
	}
	// i=0;
	// while(str[i] != '\0')
	// {
	// 	if(str[i] == '.')
	// 	{
	// 		flg.p = ft_atoi(&str[i + 1]);
	// 	}
	// 	i++;
	// }
	return flg;
}

int ft_string(char *str, va_list *list)
{
	t_flags flg;
	char *s;
	int len;
	int c = 0;
	flg = ft_check(str, list);
	s = va_arg(*list, char*);
	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	if(flg.p < len && flg.p != -1)
		len = flg.p;
	c+=ft_print(' ',flg.w - len);
	c+=ft_putstr(s,len);
	return c;
}

int ft_integer(char *str, va_list *list)
{
	t_flags flg;
	int n;
	int c;
	int x;
	flg = ft_check(str, list);
	n = va_arg(*list, int);
	x = ft_countdigit(n);
	c = ft_countdigit(n);
	c = (flg.p == 0 && n == 0) ? --c : c;
	if(flg.p  == -1)
	{
		if(n<0)
		{
			c+=ft_print(' ', flg.w - x);
			ft_putchar('-');
			ft_putnbr(n*-1);
		}
		else
		{
			c+=ft_print(' ', flg.w - x);
			ft_putnbr(n);
		}
	}
	if (flg.p >= flg.w)
	{
		if(n<0)
		{
			ft_putchar('-');
			c+=ft_print('0',flg.p - x + 1);
			ft_putnbr(n*-1);
		}
		else
		{
			c+=ft_print('0',flg.p - x);
			if((n == 0 && flg.p !=0) || (n!=0 && flg.p != -1))
				ft_putnbr(n);
		}
	}
	else if(flg.p < flg.w && flg.p != -1)
	{
		if(n<0)
		{
			if(flg.p < x && n!=0)
				c+=ft_print(' ',flg.w - x);
			else
				c+=ft_print(' ', flg.w - flg.p -1);
			ft_putchar('-');
			c+=ft_print('0',flg.p - x + 1);
			ft_putnbr(n*-1);
		}
		else
		{
			if(flg.p < x && n!=0)
				c+=ft_print(' ',flg.w - x);
			else
				c+=ft_print(' ',flg.w - flg.p);
			c+=ft_print('0',flg.p - x);
			if((n == 0 && flg.p != 0) || (n!=0 && flg.p != -1))
				ft_putnbr(n);
		}
	}
	return c;
}

int ft_hexa(char *str, va_list *list)
{
	t_flags flg;
	unsigned int n;
	int c;
	int x;
	flg = ft_check(str, list);
	n = va_arg(*list, unsigned int);
	x = ft_counthexa(n);
	c = ft_counthexa(n);
	c = (flg.p == 0 && n == 0) ? --c : c;
	if(flg.p  == -1)
	{
			c+=ft_print(' ', flg.w - x);
			ft_printhexa(n);
	}
	if (flg.p >= flg.w)
	{
			c+=ft_print('0',flg.p - x);
			if((n == 0 && flg.p !=0) || (n!=0 && flg.p != -1))
				ft_printhexa(n);
	}
	else if(flg.p < flg.w && flg.p != -1)
	{
			if(flg.p < x && n!=0)
				c+=ft_print(' ',flg.w - x);
			else
				c+=ft_print(' ',flg.w - flg.p);
			c+=ft_print('0',flg.p - x);
			if((n == 0 && flg.p != 0) || (n!=0 && flg.p != -1))
				ft_printhexa(n);
	}
	return c;
}
int ft_subprintf(char *str, int i, int s, int *c, va_list *list)
{
	char *string;
	string = ft_substr(str, i + 1, s - i);
	if(!ft_istype(str[s]))
	{
		*c+=ft_putstr(string,ft_strlen(string));
		i = s+1;
	}
	if(ft_istype(str[s]))
	{
		if(str[s] == 's')
			*c+=ft_string(string, list);
		if(str[s] == 'x')
			*c+=ft_hexa(string, list);
		if(str[s] == 'd')
			*c+=ft_integer(string,list);
		i = s+1;
	}
	free(string);
	return i;
}
int ft_printf(const char *str, ...)
{
	va_list list;
	int c;
	int i;
	int s;

	va_start(list,str);
	i=0;
	c=0;
	while(str[i]!='\0')
	{
		if(str[i] != '%')
		{
			c+=ft_putchar(str[i]);
			i++;
		}
		else
		{
			s = i + 1;
			while(str[s] != '\0' && ft_isvalid(str[s]))
				s++;
			if(str[s] == '\0')
			{
				c+= ft_putstr((char *)str,ft_strlen((char *)str));
				i = s;
			}
			else
				i= ft_subprintf((char *)str,i,s,&c,&list);
		}
	}
	return c;
}
#include <limits.h>
// #define TEMP "|%15.10x|\n",LONG_MIN
// int     main()
// {
//     printf("%d\n",ft_printf(TEMP));
//     printf("%d\n",printf(TEMP));
//     //printf("%c , w = %d, p = %d", spec, width,prec);
//     return (0);
// }
#define TEMP "|%*.*d|\n",i,j,-56
int main()
{
    int i = 0;
    int j = 0;
    // int x = ft_printf(TEMP);
    // int y = printf(TEMP);
    // printf("x = %d\ny = %d\n",x,y);
    int x,y,u;
    while (i < 6)
    {
     j = 0;
     while (j < 6)
     {
         x = ft_printf(TEMP);
         y = printf(TEMP);
         printf("[%d]--[%d]\n", i, j);
         if (x != y)
         {
             printf("FAIL");
             u = 1;
             break ;
         }
         j++;
     }
     if (u != 0)
         break ;
     i++;
    }
}





