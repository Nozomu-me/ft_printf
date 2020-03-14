# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amouassi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/13 12:26:56 by amouassi          #+#    #+#              #
#    Updated: 2019/12/17 19:00:08 by amouassi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
AR = ar rcs
LIBFT = libft
NAMELIBFT = libft.a

SRC = ft_check.c\
	  ft_check_flags.c\
	  ft_printf.c\
	  ft_process_char.c\
	  ft_process_integer.c\
	  ft_process_string.c\
	  ft_process_unsigned_int.c\
	  ft_process_hex_low.c\
	  ft_process_hex_up.c\
	  ft_process_pointer.c\
	  utils.c\
	  sub_utils.c\
	  hexa_utils.c
	  
SRCLIB =  ft_atoi.c \
		  ft_bzero.c \
	      ft_calloc.c \
	  	  ft_isalnum.c \
	 	  ft_isalpha.c \
		  ft_isascii.c \
		  ft_isdigit.c \
		  ft_isprint.c \
		  ft_itoa.c \
		  ft_memccpy.c \
		  ft_memchr.c \
		  ft_memcmp.c \
		  ft_memcpy.c \
		  ft_memmove.c \
		  ft_memset.c \
		  ft_putchar_fd.c \
		  ft_putnbr_fd.c \
		  ft_putstr_fd.c \
		  ft_putendl_fd.c \
		  ft_split.c \
		  ft_strchr.c \
		  ft_strdup.c \
		  ft_strjoin.c \
		  ft_strlcat.c \
		  ft_strlcpy.c \
		  ft_strlen.c \
		  ft_strmapi.c \
		  ft_strncmp.c \
		  ft_strnstr.c \
		  ft_strrchr.c \
		  ft_strtrim.c \
		  ft_substr.c \
		  ft_tolower.c \
		  ft_toupper.c

OBJ = $(SRC:.c=.o)
OBJLIB = $(addprefix $(LIBFT)/,$(SRCLIB:.c=.o))

all: $(NAME)

$(NAME): $(OBJ) $(OBJLIB)
	$(AR) $(NAME) $(OBJ) $(OBJLIB)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	rm -f $(OBJLIB)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)/$(NAMELIBFT)

re: fclean all   

